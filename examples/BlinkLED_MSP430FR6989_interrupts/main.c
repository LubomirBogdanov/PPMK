#include <stdio.h>
#include <driverlib.h>
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"

/*!
 * \brief Graphic library context, contains all the objects on screen. You may
 * think of it as "canvas" that is tied to the screen and symbols and shapes
 * are drawn on it.
 *
 * \var g_sContext
 */
Graphics_Context g_sContext;

/*!
 * \brief init_clock_system( ) - initializes the microcontroller's clocks. Uses the DCO as
 * main source, running at 16 MHz. The main clock (MCLK) and sub-module clock (SMCLK) have
 * been made equal to the DCO.
 * \return None.
 */
void init_clock_system(void)
{
    CS_setDCOFreq(CS_DCORSEL_1, CS_DCOFSEL_4); //DCO = 16 MHz
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1); //SMCLK = DCO clock
}

/*!
 * \brief init_lcd( ) - initializes the 128x128 pixel colour TFT LCD
 * \return None.
 */
void init_lcd(void)
{
    Crystalfontz128x128_Init(); // Initializes display driver
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP); // Set default screen orientation
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128); // Initializes graphics context
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);

    Graphics_drawStringCentered(&g_sContext, (int8_t *)"Press button P1.1", AUTO_STRING_LENGTH, 64, 10, OPAQUE_TEXT);
}

/*!
 * \brief init( ) - initializes the microcontroller and board
 * \return None.
 */
void init(void)
{
    WDT_A_hold(WDT_A_BASE); // Stop watchdog timer

    PMM_unlockLPM5(); // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings

    FRAMCtl_configureWaitStateControl(FRAMCTL_ACCESS_TIME_CYCLES_1); //Needed for DCO = 16 MHz

    init_clock_system();

    init_lcd();
}

/*
 * PORT3 Interrupt Service Routine
 */
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
	uint16_t int_status;

    int_status = GPIO_getInterruptStatus(GPIO_PORT_P1, 0xFF);
    GPIO_clearInterrupt(GPIO_PORT_P1, 0xFF);

    if(int_status &GPIO_PIN1){
        GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}

/*!
 * \brief main( ) - the main function of the program
 * \return None.
 */
void main(void) {

    init();

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN1, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN1);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN1);

    __enable_interrupt();

    while(1)
    {
    	__bis_SR_register(CPUOFF + GIE); //Go to sleep, will be awaken by GPIO interrupt
    }
}
