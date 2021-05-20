/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <math.h>

#define MODE_NORMAL 0
#define MODE_CH 1

#define DUMMY 1.0

#define HIGH 1u
#define LOW 0u

/* Switch debounce delay in milliseconds */
#define SWITCH_DEBOUNCE_UNIT (1u)

/* Number of debounce units to count delay, before consider that switch is pressed */
#define SWITCH_DEBOUNCE_PERIOD (10u)

#define DATA_SIZE (6u)

/* Switch state defines */
#define SWITCH_PRESSED (0u)
#define SWITCH_RELEASED (1u)

/* Function prototypes */

CY_ISR_PROTO(ISR_CAN);

/* Global variable used to store switch state */
uint8 switchState = SWITCH_RELEASED;
//String used to output value to UART
char outputstring[50];

float max_temp = 0;
float min_temp = 15;
float avg_temp = 0;

float Temperature;

/* Global variable used to store ISR flag */
volatile uint8 isrFlag = 0u;

/*******************************************************************************
* Function Name: main
********************************************************************************

*
*******************************************************************************/

void UART_STRING(char my_string[], char outputstring[], int ch, float voltage, int mode)
{
    if (mode == MODE_NORMAL)
    {
        sprintf(outputstring, my_string);
        UART_1_PutString(outputstring); // print value to UART
        UART_1_PutString("\r\n");
    }
    if (mode == MODE_CH)
    {
        sprintf(outputstring, "Channel %d is %6.3f C/Degree", ch, voltage);
        UART_1_PutString(outputstring); // print value to UART
        UART_1_PutString("\r\n");
    }
}

CY_ISR(Timer_Int_Handler)
{
    // LED_Write(1u);
    //The CAN message needed to be sent every 100ms, so add an timer interupt to execute this
    //Func
    int num_ther = 2u;
    int hi_ind = 02u;
    int low_ind = 01u;
    //Byte 1: Thermistor Module Number
    CAN_TX_DATA_BYTE1(CAN_TX_MAILBOX_ADCdata) = 0u; //8 bit 0 in binary
    //Byte 2:
    CAN_TX_DATA_BYTE2(CAN_TX_MAILBOX_ADCdata) = (int)min_temp; //int8_t type is the signed 8 bit integer,
    //I am casting my flost value to an 8 bit signed integer
    //Byte 3:
    CAN_TX_DATA_BYTE3(CAN_TX_MAILBOX_ADCdata) = (int)max_temp;
    //Byte 4:
    CAN_TX_DATA_BYTE4(CAN_TX_MAILBOX_ADCdata) = (int)avg_temp;
    //Byte 5: Number of thermistors enabled： we have 34 here
    CAN_TX_DATA_BYTE5(CAN_TX_MAILBOX_ADCdata) = num_ther;
    //Byte 6: Highest thermistor ID on the module: 33
    CAN_TX_DATA_BYTE6(CAN_TX_MAILBOX_ADCdata) = low_ind;
    //Byte 7: Lowest thermistor ID on the module: 0
    CAN_TX_DATA_BYTE7(CAN_TX_MAILBOX_ADCdata) = hi_ind;
    //the last bit sums all bit + Checksum 8-bit (sum of all bytes +ID + length)
    // new algo
    char lastbyte = (0x39 + 8 + 0 + (int8_t)min_temp + (int8_t)max_temp + (int8_t)avg_temp + num_ther + hi_ind + low_ind) & 0xFF;
    //char lastbyte = ((0x1839f380 & 0xFF) + 8 + 0 + (int8_t)min_temp + (int8_t)max_temp + (int8_t)avg_temp + num_ther + hi_ind + low_ind) & 0xFF;
    //Byte 8: Checksum
    //0x39 + 8 + 0xF + 0x1E + 0x19 + 0x2 + 0x1 + 0x2 = 0x8C (0x8C being the Checksum value)
    CAN_TX_DATA_BYTE8(CAN_TX_MAILBOX_ADCdata) = lastbyte;

    //Send CAN message
    CAN_SendMsgADCdata();

    //sprintf(outputstring, "B1: %x, B2: %x, B3: %x, B4: %x, B5: %x, B6: %x, B7: %x, Checksum: %x", 0u, (int)min_temp, (int)max_temp, (int)avg_temp, num_ther, low_ind, hi_ind,
    //lastbyte);
    UART_1_PutString(outputstring); // print value to UART
    UART_1_PutString("\r\n");

    //LED_Write(0u);,
}

int main()
{
    //int16 output;
    //char8 txData[DATA_SIZE];

    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Start services */
    ADC_SAR_1_Start();
    UART_1_Start();
    CAN_Start();
    AMux_Init();
    AMux_Start();
    //Interrupt
    Timer_Start();
    Timer_Int_StartEx(Timer_Int_Handler);

    /* Set CAN interrupt handler to local routine */
    CyIntSetVector(CAN_ISR_NUMBER, ISR_CAN);

    /*Declear Main function local variables*/

    float voltage = 0; //voltage reading
                       //    uint16 counts = 0;     // ADC Counts
    uint16 ch;         // Channels of Amux
    uint16 resVolts;
    int refresh_count = 0;
    
    
    UART_STRING("Starting now", outputstring, (int)DUMMY, DUMMY, MODE_NORMAL);
    for (;;)
    {

        if (refresh_count==5){
            sprintf(outputstring, "Refreshed, count = %d",refresh_count );
            UART_1_PutString(outputstring); // print value to UART
            UART_1_PutString("\r\n");
            
            refresh_count = 0;
            max_temp = Temperature;
            min_temp = Temperature;

        }

        for (ch = 0; ch < 67; ch++)
        {

            AMux_Select(ch);
            ADC_SAR_1_StartConvert();
            //ADC_SAR_1_RETURN_STATUS is a system macro
            while (!ADC_SAR_1_IsEndConversion(ADC_SAR_1_RETURN_STATUS))
            {
            }

            //do the conversion here
            //take average of 5 readings
            uint16 sum = 0;
            for (int i = 0; i < 5; i++)
            {
                sum = sum + ADC_SAR_1_GetResult16();
            }
            uint16 average = sum / 5;

            voltage = ADC_SAR_1_CountsTo_Volts(average);
            resVolts = (uint16)voltage;

            //convert to tenmperature
            //removed ch21-defected, ch53-empty
            if ((ch % 2 != 0 || ch == 0))
            { 
                if (ch!=21 && ch!=53){
                // only update on even number of channels
                Temperature = (-740.85) * powf(voltage, 5.0) + (7056.8) * powf(voltage, 4.0) + (-26800.0) * powf(voltage, 3.0) + (50732.0) * powf(voltage, 2.0) - (47967.0) * powf(voltage, 1.0) + 18213.0;
//              BattTemp = -740.85 * bt5 + 7056.8 * bt4 - 26800 * bt3 + 50732 * bt2 - 47967 * bt1 + 18213;
                //uint16 u16Temperature = (uint16) Temperature;
                if ((Temperature > max_temp) && (Temperature<120))
                {
                    max_temp = Temperature;
                }
                if ((Temperature < min_temp) && (Temperature>-40))
                {
                    min_temp = Temperature;
                }

                avg_temp = (max_temp + min_temp) / 2.0;
                UART_STRING("Channel %d is %6.3f C Degree", outputstring, (int)ch, Temperature, MODE_CH); //debug message
                sprintf(outputstring, "max temp is %6.3f C/Degree", max_temp);
                UART_1_PutString(outputstring); // print value to UART
                UART_1_PutString("\r\n");
                sprintf(outputstring, "min temp is %6.3f C/Degree", min_temp);
                UART_1_PutString(outputstring); // print value to UART
                UART_1_PutString("\r\n");
                }
            }

            CyDelay(100);
            ADC_SAR_1_StopConvert();
            //finished one channel
        }
        //finished all channels
        refresh_count++;
        UART_STRING("one interation", outputstring, (int)DUMMY, DUMMY, MODE_NORMAL);
        //CyDelay(1000);
    }
}

/*******************************************************************************
* Function Name: ISR_CAN
********************************************************************************
*
* Summary:
*  This ISR is executed at a Receive Message event and set the isrFlag.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
CY_ISR(ISR_CAN)
{
    /* Clear Receive Message flag */
    CAN_INT_SR_REG.byte[1u] = CAN_RX_MESSAGE_MASK;

    /* Set the isrFlag */
    isrFlag = 1u;

    /* Acknowledges receipt of new message */
    CAN_RX_ACK_MESSAGE(CAN_RX_MAILBOX_0);
}

/* [] END OF FILE */

/*
#include <stdio.h>
 
int main(void) {
	int high = 30;
	int low = 15;
	int avg = 25;
	int num_ther = 2;
	int hi_ind = 02;
	int low_ind = 01;
	int a = ((0x1839f380 & 0xFF) + 8 + 0 + low + high + avg + num_ther + hi_ind + low_ind) & 0xFF;
	printf("%x", a);
	return 0;
}
 
*/