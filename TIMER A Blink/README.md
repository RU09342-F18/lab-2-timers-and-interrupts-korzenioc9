# TIMER A Blink
Author: Cameron Korzeniowski,
Last Edited: 09/28/2018

## Task
"Using the TIMER module instead of a software loop, control the speed of two LEDS blinking on your development boards. Experiment with the different counting modes available as well as the effect of the pre-dividers. Why would you ever want to use a pre-divider? What about the Capture and Compare registers? Your code should include a function (if you want, place it in its own .c and .h files) which can convert a desired Hz into the proper values required to operate the TIMER modules."

## Implementation
For this portion of the lab I used boards MSP430G2553 and MSP430F5529. The code for this program is identical on both boards with the exception of the LED pin numbers. To begin the code, we set the direction of both LED pins to be outputs and initialize them to be off. Next, we load numerical values into the capture/compare registers of timer A0 and A1. This lab task specifies that the LEDs are to blink at different rates, so we load a different value into each timer's CCR0. We then use the CTL of each timer to set our counting mode to up and select ACLK as our reference clock. We also need to enable interrupts on both timers using CCTL0. An optional task of this lab was to enable low power mode, which we do with the following line of code:

_BIS_SR(LPM0_bits + GIE);

Finally, a #pragma vector is used again to interrupt the service routine. Each timer is given its own interrupt, in which the respective LED is flashed.

## MSP430G2553
LED1: P1.0, LED2: P1.6

## MSP430F5529
LED1: P1.0, LED2: P4.7
