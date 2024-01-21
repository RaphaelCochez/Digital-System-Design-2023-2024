/*
 * Codevoorbeeld 2
 *
 * Dit voorbeeld is geschreven met hulp van de cursus Microcontrollers van het tweede jaar.
 * Het laat een looplichtje lopen en toont UART berichten met een counter voor iedere cyclus van het looplichtje
 * Dit toont de werking van de UART periphial en GPIO aan als de interne systeemklok wordt belast.

 */

/***************************** Include Files *********************************/

#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"

/************************** Constant Definitions *****************************/

#define LED0 0b0000000000000001  /* led 0*/
#define LED1 0b0000000000000010  /* led 1*/
#define LED2 0b0000000000000100  /* led 2*/
#define LED3 0b0000000000001000	 /* led 3*/
#define LED4 0b0000000000010000  /* led 4*/


#define GPIO_EXAMPLE_DEVICE_ID  XPAR_AXI_GPIO_LED_DEVICE_ID
#define LED_DELAY     1000000
#define LED_CHANNEL 1

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/

#ifdef PRE_2_00A_APPLICATION

/*
 * The following macros are provided to allow an application to compile that
 * uses an older version of the driver (pre 2.00a) which did not have a channel
 * parameter. Note that the channel parameter is fixed as channel 1.
 */
#define XGpio_SetDataDirection(InstancePtr, DirectionMask) \
        XGpio_SetDataDirection(InstancePtr, LED_CHANNEL, DirectionMask)

#define XGpio_DiscreteRead(InstancePtr) \
        XGpio_DiscreteRead(InstancePtr, LED_CHANNEL)

#define XGpio_DiscreteWrite(InstancePtr, Mask) \
        XGpio_DiscreteWrite(InstancePtr, LED_CHANNEL, Mask)

#define XGpio_DiscreteSet(InstancePtr, Mask) \
        XGpio_DiscreteSet(InstancePtr, LED_CHANNEL, Mask)

#endif

XGpio Gpio; /* The Instance of the GPIO Driver */


int main(void)
{
	int Status;
	int counter = 0;
	volatile int Delay;

	xil_printf("Entering main(void) function\r\n");

	/* Initialize the GPIO driver */
	Status = XGpio_Initialize(&Gpio, GPIO_EXAMPLE_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("Gpio Initialization Failed\r\n");
		return XST_FAILURE;
	}

	// voorbeeld 1 on board led GPIO setup
	XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0); /* Set the direction for all signals as inputs except the LED output */


	/* Loop forever blinking the LED */

	while (1) {

		/* voorbeeld 1 on-board led GPIO */
		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, LED0); /* Set the LED to High */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteClear(&Gpio, LED_CHANNEL, LED0); /* Clear the LED bit */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */

		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, LED1); /* Set the LED to High */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteClear(&Gpio, LED_CHANNEL, LED1); /* Clear the LED bit */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */

		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, LED2); /* Wait a small amount of time so the LED is visible */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteClear(&Gpio, LED_CHANNEL, LED2); /* Clear the LED bit */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */

		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, LED3); /* Set the LED to High */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteClear(&Gpio, LED_CHANNEL, LED3); /* Clear the LED bit */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */

		XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, LED4); /* Set the LED to High */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteClear(&Gpio, LED_CHANNEL, LED4); /* Clear the LED bit */
		for (Delay = 0; Delay < LED_DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		counter++;
		xil_printf("Cyclus: %d\r\n", counter);

	}

}
