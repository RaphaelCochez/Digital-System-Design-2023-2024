#include <stdio.h>

#include "xil_printf.h"

#include "xtmrctr.h"

#define TMRCTR_DEVICE_ID        XPAR_TMRCTR_1_DEVICE_ID
#define PWM_PERIOD              500000000    /* PWM period in (500 ms) */
#define TMRCTR_0                0            /* Timer 0 ID */
#define TMRCTR_1                1            /* Timer 1 ID */
#define CYCLE_PER_DUTYCYCLE     10           /* Clock cycles per duty cycle */
#define MAX_DUTYCYCLE           100          /* Max duty cycle */
#define DUTYCYCLE_DIVISOR       8            /* Duty cycle Divisor */

XTmrCtr TimerCounterInst;

int main()
{
	u8  divisor;
	u32 period;
	u32 highTime;
	int status;

    print("Initializing the Timer Counter...");
	/*
	 * Initialize the timer counter so that it's ready to use,
	 * specify the device ID that is generated in xparameters.h
	 */
	status = XTmrCtr_Initialize(&TimerCounterInst, TMRCTR_DEVICE_ID);
	if (status != XST_SUCCESS) {
		return XST_FAILURE;
	}


    print("Timer Counter initialized");
    divisor = DUTYCYCLE_DIVISOR;

    /* Disable PWM for reconfiguration */
    XTmrCtr_PwmDisable(&TimerCounterInst);

	/* Configure PWM */
    period = PWM_PERIOD;
	highTime = PWM_PERIOD / divisor;

	XTmrCtr_PwmConfigure(&TimerCounterInst, period, highTime);

	/* Enable PWM after reconfiguration */
	XTmrCtr_PwmEnable(&TimerCounterInst);
	while(1){

	}

    return 0;
}
