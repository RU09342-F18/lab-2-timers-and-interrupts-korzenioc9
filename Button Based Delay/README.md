# Button Based Delay
Author: Cameron Korzeniowski,
Last Edited: 09/28/2018

## Task
"Setup your microcontroller to initially blink and LED at a rate of 10Hz upon restarting or powering up. Then utilizing one of the buttons on board, a user should be able to set the delay or blinking rate of the LED by holding down a button. The duration in which the button is depressed should then become the new rate at which the LED blinks. As previously stated, you most likely will want to take advantage of the fact that TIMER modules exist and see if you can let them do a bulk of the work for you."


## Implementation
For this portion of the lab I used boards MSP430G2553 and MSP430F5529. While the code for implementing this task is very similar for both boards, there are some important distinctions. In this task, the LED pins on both boards are the same, however the button pins are different. Another difference is the way that timer-specific lines are coded. The G2553 allows for the use of CCR0, CCR0, and TACTL, while the F5529 requires that the desired timer be specified for these commands, such as TA0CCR0, TA0CCTL0, and TA0CTL. Apart from these differences, the implementation is the same between boards. 
The first step is to set the LED pin to an output direction and initialize it to be off. Then the button pin is enabled for use with a pull up resistor, and a pull up resistor is set to the button. Next, interrupts are enabled on the button pin using PXIE |= BITY, and hi/lo behavior is enabled on the button pin using PXIES |= BITY. 

Now the timer is set up by enabling CCR0 interrupt and loading a value into CCR0 that will determine the timer frequency. To finish setting up the timer, a CTL statement is coded to select the desired clock, set the count mode to be up, and select the desired clock division factor. To enable interrupts an infinite while loop is used; e.g. while(1). 

The next items to be coded are two #pragma vectors. One of the vectors is used to simply flash the desired LED at the rate stored in the selected timer. The second vector is more complex and is required to allow the button input to be timed and saved as the timer period. This is accomplished with an if/else statement. 

The if statement is activated if the button is pressed and remains active as long as the button is held (16 seconds max). Within the if statement, the timer CTL is cleared and then reset to continuous mode. Continuous mode is necessary to be able to time the length of the button press, as up mode would only store a value less than its maximum period, allowing the user to shorten the timer period only (speed up LED flash rate). Finally, the hi/lo edge select is set to a low to high edge trigger in order to detect the moment the button pin goes from zero to one (not pressed to pressed).

The else statement is activated when the button is released. To detect the button release, edge select is changed to high to low edge trigger. Currently, the period for which the button was held down is stored in the TA0R register; in order to flash our LED at that period, the value of TA0R is loaded into CCR0. Finally, the timer CTL is reset to UP mode to allow the LED to flash with the new timer period.

The last part of the button vector is a line of code that clears the interrupt flags on the button pin, readying the button for another user input.

# MSP430G2553
LED: P1.0, 
Button: P1.3,
Clock: SMCLK

# MSP430F5529
LED: P1.0,
Button: P1.1,
Clock: ACLK
