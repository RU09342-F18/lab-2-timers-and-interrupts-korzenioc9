#include <msp430.h>

//MSP430G2553
/**
 * Created by Cameron Korzeniowski
 * 9/26/2018
 * main.c
 */
void main(void) {
  WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer
  P1DIR |= BIT0;                   // Set P1.0 to output direction
  P1OUT &= ~BIT0;                  // Turn the 1.0 LED off
  P1DIR |= BIT6;                   // Set P1.6 to output direction
  P1OUT &= ~BIT6;                  // Turn the 1.6 LED off
  TA0CCR0 = 1000;                  // Timer period
  TA0CCTL0 = 0x10;                 // Enable Timer A0 interrupts
  TA0CTL = TASSEL_1 + MC_1;        // Sets counting mode to UP, chooses ACLK
  TA1CCR0 = 20000;                 // Timer period
  TA1CCTL0 = 0x10;                 // Enable Timer A1 interrupts
  TA1CTL = TASSEL_1 + MC_1;        // Sets counting mode to UP, chooses ACLK
  _BIS_SR(LPM0_bits + GIE);        // Low power mode interrupts enabled
}

#pragma vector=TIMER1_A0_VECTOR    
// interrupt service routine
__interrupt void Timer1_A0 (void) 
{
   P1OUT ^= BIT0;                  // Flash 1.0 LED
}

#pragma vector=TIMER0_A0_VECTOR    
//interrupt service routine

  __interrupt void Timer0_A0 (void) 
  {
   P1OUT ^= BIT6;                  // Flash 1.6 LED
}
