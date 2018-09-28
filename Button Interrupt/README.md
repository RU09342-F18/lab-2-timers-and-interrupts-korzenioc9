# Button Interrupt
Author: Cameron Korzeniowski,
Last Edit: 09/28/2018

## Task
"Your goal for this part of the lab is to replicate your button code from Lab 2, where the LED should change states only when the button is pressed. This can be extended to include behaviors such as only have the LED on when the button is depressed, or have the LED blink one color when pressed and another when it is let go. Another behavior extends from the second lab which is speed control based on the button presses. For example, have the rate of the LED cycle between a "low", "Medium", and "High" rate of speed."

## Implementation
For this portion of the lab I used boards MSP430G2553 and MSP430F5529. The functionality that I decided to implement was that of a single LED blinking at a constant rate, turned on and off with the press of a button. If the LED is blinking and the button is pressed, the LED turns off. If the LED is off and the button is pressed, the LED resumes blinking. The implementation of this code is identical on both boards, with the exception of the pin numbers for the LED and button. First, the LED pin must be set as an output. Then, the button pin must be enabled with a pull up resistor, its value initialized, and a pull up resistor enabled on the pin. Next, the interrupt flags should be cleared for the button pin to ensure no unwanted flags cause a state change. The code is finished with a #pragma vector to interrupt the service routine. Within this interrupt, the LED is set to flash and the button pin interrupt flags are cleared.

## MSP430G2553
LED: P1.0,
Button: P1.3

## MSP430F5529
LED: P1.0,
Button: P1.1
