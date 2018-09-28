#include <msp430.h>
/**
 * main.c
 */

void main(void){
  WDTCTL = WDTPW + WDTHOLD;        // Stop watchdog timer

  P1DIR |= BIT0;                   // sets P1.0 direction as output
  P1OUT &= ~BIT0;                  // Turn 1.0 LED off
  P4DIR |= BIT7;                   // sets P4.7 direction as output
  P4OUT &= ~BIT7;                  // Turn 4.7 LED off
  TA0CCR0 = 1000;                 // Timer A0 period
  TA0CCTL0 = 0x10;                 // enable Timer A0 interrupts
  TA0CTL = TASSEL_1 + MC_1;        // set count mode to up, choose ACLK
  TA1CCR0 = 20000;                 // Timer A1 period
  TA1CCTL0 = 0x10;                 // enable Timer A1 interrupts
  TA1CTL = TASSEL_1 + MC_1;        // set count mode to up, choose ACLK
  _BIS_SR(LPM0_bits + GIE);        // Low power mode interrupts enabled
}

#pragma vector=TIMER1_A0_VECTOR    // interrupt service routine

__interrupt void Timer1_A0 (void)
{
      P1OUT ^= BIT0;               // flash LED 1.0
}

#pragma vector=TIMER0_A0_VECTOR    // interrupt service routine

__interrupt void Timer0_A0 (void)
{
   P4OUT ^= BIT7;                  // flash LED 4.7
}
