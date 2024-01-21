/***************************** Include Files *********************************/

#include "xparameters.h"
#include "xgpio.h"
#include "xil_printf.h"

/************************** Constant Definitions *****************************/
#define KATHODE 0b1111111  // init kathodes/
#define ANODE 0b1111  //init anodes

#define KATHODE0 0b1000000
#define KATHODE1 0b1111001
#define KATHODE2 0b0100100
#define KATHODE3 0b0110000
#define KATHODE4 0b0011001
#define KATHODE5 0b0010010
#define KATHODE6 0b0000011
#define KATHODE7 0b0111000
#define KATHODE8 0b0000000
#define KATHODE9 0b0010000

#define ANODE0 0b11111


#define GPIO_ANODES_DEVICE_ID  XPAR_AXI_GPIO_ANODES_DEVICE_ID
#define GPIO_KATHODES_DEVICE_ID  XPAR_AXI_GPIO_KATHODES_DEVICE_ID
#define DELAY     10000000
#define ANODES_CHANNEL0 1
#define KATHODES_CHANNEL0 1
/**************************** Type Definitions *******************************/


XGpio Gpio; /* The Instance of the GPIO Driver */


int main(void)
{
	int Status;
	volatile int Delay;

	xil_printf("Entering main(void) function\r\n");

	/* Initialize the GPIO driver */
	Status = XGpio_Initialize(&Gpio, GPIO_ANODES_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("ANODES Gpio Initialization Failed\r\n");
		return XST_FAILURE;
	}
	Status = XGpio_Initialize(&Gpio, GPIO_KATHODES_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		xil_printf("KATHODES Gpio Initialization Failed\r\n");
		return XST_FAILURE;
	}


	// voorbeeld 1 on board led GPIO setup
	XGpio_SetDataDirection(&Gpio, ANODES_CHANNEL0, 0); /* Set the direction for all signals as outputs except the LED output */
	XGpio_SetDataDirection(&Gpio, KATHODES_CHANNEL0, 0); /* Set the direction for all signals as outputs except the LED output */
	XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE); /* Set the LED to High */
	XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE); /* Set the LED to High */

	/* Loop forever blinking the LED */

	while (1) {

		/* voorbeeld  on-board 7segment display GPIO */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE0);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE1);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE2);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE3);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE4);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE5);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE6);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE7);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE8);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE);
		XGpio_DiscreteWrite(&Gpio, ANODES_CHANNEL0, ANODE0);
		XGpio_DiscreteWrite(&Gpio, KATHODES_CHANNEL0, KATHODE9);
		for (Delay = 0; Delay < DELAY; Delay++); /* Wait a small amount of time so the LED is visible */
	}
}
