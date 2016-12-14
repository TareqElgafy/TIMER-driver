
#include <stdlib.h>
#include <stdint.h>
#include "tm4c123gh6pm.h"


int main()
{
   // Configure LED1 in portF
    SYSCTL_RCGCGPIO_R |= (1<<5); // enable clock on PortF
    GPIO_PORTF_DIR_R = (1<<1);  // make LED pin (PF1) output
    GPIO_PORTF_DEN_R = (1<<1); // enable digital function on LED pin
    GPIO_PORTF_DATA_R &= ~(1<<1); // turn off led
  
  
  
  // Timer stuff
    
  SYSCTL_RCGCTIMER_R |= (1<<0); // timer clock
  TIMER0_CTL_R &= ~ (1<<0 ) ; // disable timer
  TIMER0_CFG_R = 0x00000000;  // 32 bit config mode
  TIMER0_TAMR_R |= (0x2<<0); // enable perodic mode
  TIMER0_TAMR_R &= ~(1<<4); // make it count down timer
  TIMER0_TAILR_R = 0x00F42400; // 16,000,000 , start load value
  TIMER0_CTL_R |= (1<<0 ) ; // enable timer
  
  while(1){
    
    if((TIMER0_RIS_R & 0x1) == 1 ){ // when counter reaches 0
    
    TIMER0_ICR_R |=(1<<0);  // clear RIS bit which was set to 1 
    GPIO_PORTF_DATA_R ^=  (1<<1)  ;
    
    }
    
  }
  
}
