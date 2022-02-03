#include <stdio.h>
#include <driverlib.h>
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"
#include "uartstdio.h"

#define MAX_STR_SIZE	20

/* Graphic library context */
Graphics_Context g_sContext;

void init_clock_system(void)
{
    CS_setDCOFreq(CS_DCORSEL_1, CS_DCOFSEL_4); //DCO = 16 MHz
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1); //SMCLK = DCO clock
}

void init_lcd(void)
{
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);

    Graphics_drawStringCentered(&g_sContext, (int8_t *)"<uartstdio.h>", AUTO_STRING_LENGTH, 64, 10, OPAQUE_TEXT);
}

void init(void)
{
    // Stop watchdog timer
    WDT_A_hold(WDT_A_BASE);
    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();

    FRAMCtl_configureWaitStateControl(FRAMCTL_ACCESS_TIME_CYCLES_1); //Needed for DCO = 16 MHz

    init_clock_system();

    init_lcd();

    UARTStdioInit();
}

int main(void) {
	unsigned int choice;
	uint8_t my_integer = 187;
	uint16_t my_hex_integer = 32767;
	char my_string[MAX_STR_SIZE];

    init();

    while(1)
    {
    	UARTprintf("*********Example menu*********\n\r");
    	UARTprintf("1. Display char\n\r");
    	UARTprintf("2. Display decimal\n\r");
    	UARTprintf("3. Display hex\n\r");
    	UARTprintf("4. Enter your own string\n\r");
    	UARTprintf("Enter your choice:\n\r");

    	choice = UARTgetc();

    	UARTprintf("\n\rYour choice: %c\n\r", choice);

    	switch(choice){
    	case '1':
    		UARTprintf("Displaying char: %c\n\r", 'L');
    		break;
    	case '2':
    		UARTprintf("Displaying decimal: %d\n\r", my_integer);
    		break;
    	case '3':
    		UARTprintf("Displaying hex: 0x%04X\n\r", my_hex_integer);
    		break;
    	case '4':
    		UARTprintf("Enter your string here: ");
    		UARTgets(my_string, MAX_STR_SIZE);
    		UARTprintf("The string you entered: %s \n\r", my_string);
    		break;
    	default:
    		UARTprintf("Wrong choice!\n\r");
    	}
    }
}
