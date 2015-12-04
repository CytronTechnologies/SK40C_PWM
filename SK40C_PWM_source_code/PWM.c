/*******************************************************************************
* This is the template file for PTK40A PIC Training Board.
*
* Author: Ober Choo @ Cytron Technologies Sdn. Bhd.
*******************************************************************************/
// This template is being written based on Cytron PTK40A board
// This template C file should be compiled with HI-TECH C PRO Lite Mode
// Please email support@cytron.com.my if you have any problem

// Include all neccessary header files
#include <htc.h>	// include htc for HI-TECH header file for PIC
#include "system.h" // include hardware system define header file
//#include "adc.h"	// include adc initialization for correct digital and analog pin
//#include "lcd.h"	// include lcd library functions
#include "pwm.h" 	// include pwm library functions
#include "pic.h"
/*******************************************************************************
* DEVICE CONFIGURATION WORDS                                                   *
*******************************************************************************/

__CONFIG(HS &			// High Speed Crystal.
		 WDTDIS &		// Disable Watchdog Timer.
		 PWRTEN &		// Enable Power Up Timer.
		 BORDIS &		// Disable Brown Out Reset.
		 LVPDIS);		// Disable Low Voltage Programming.



/*******************************************************************************
* PRIVATE FUNCTION PROTOTYPES                                                  *
*******************************************************************************/

void delay_ms(unsigned int ui_value);
void beep(unsigned char uc_count);

/*******************************************************************************
* Global Variables                                                             *
*******************************************************************************/

char string_buffer[40] = {0};


/*******************************************************************************
* MAIN FUNCTION                                                                *
*******************************************************************************/
int main(void)
{	
	unsigned int speed = 0;	// to store speed value
	// Initiate value for output pin	
	PORTA = 0;
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
	PORTE = 0;
	// Initialize the I/Os.
	// There are 5 IO Ports on PIC16F877A (40 pin)
	// User is needed to initiate all I/O pin according to schematic
	// Most of un-use I/O is being configured as Input
	
	// Initialize the I/Os.
	TRISA = 0b00010001;
	TRISB = 0b00001111;
	TRISC = 0b10010011;
	TRISD = 0;
	TRISE = 0;
		










	CCP1M3 = 1;
	CCP1M2 = 1;		// Configure CCP1 module to operate in PWM mode.
	// Setting PWM frequency = 1.22khz.
	PR2 = 0xff;
	T2CKPS1 = 1;
	T2CKPS0 = 0;	// Timer 2 prescale = 16.	
	CCPR1L = 0;		// Duty cycle = 0;
	TMR2ON = 1;		// Turn on Timer 2, this will start the pulse generation at CCP1
	
	






















	while(1)
	{
	
	if (SW1 == 0)		// if SW1 is pressed
		{	
			M1 = 0;
			M2 = 1;				// activate DC Brush motor in other direction
			if (CCPR1L <255) 
			{
				CCPR1L += 1; 		//increase speed by 1
				delay_ms(30);
			}
		//	CCPR1L = 255; 		//~70% of full speed
		
		}	
	else if (SW2 == 0)		// if SW2 is pressed
		{
		
			M1 = 0;
			M2 = 1;				// activate DC Brush motor in other direction
			if (CCPR1L > 0) 
			{
				CCPR1L -= 1; 		//decrease speed by 1
				delay_ms(30);
			}
		}	
	
	}
	
	
	while(1) continue; 	// Infinate loop at the end of program, prevent the PIC from reset
}



/*******************************************************************************
* PRIVATE FUNCTION: delay_ms
*
* PARAMETERS:
* ~ ui_value	- The period for the delay in miliseconds.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Delay in miliseconds.
*
*******************************************************************************/
void delay_ms(unsigned int ui_value)
{
	while (ui_value-- > 0) 
	{
		__delay_ms(1);
	}	
}	



/*******************************************************************************
* PRIVATE FUNCTION: beep
*
* PARAMETERS:
* ~ uc_count	- How many times we want to beep.
*
* RETURN:
* ~ void
*
* DESCRIPTIONS:
* Beep for the specified number of times.
*
*******************************************************************************/
void beep(unsigned char uc_count)
{
	while (uc_count-- > 0) 
	{
		BUZZER = 1;
		delay_ms(50);
		BUZZER = 0;
		delay_ms(50);
	}
}


