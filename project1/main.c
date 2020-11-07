#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned volatile FLAG=0;
unsigned volatile FLAG1=0;
unsigned volatile FLAG2=0;

int main(void)
{
    port();
    while(1){
            if(FLAG==1){
                PORTB|=(1<<PB0);
        _delay_ms(200);
        FLAG=0;
            }
       if(FLAG1==1){
                PORTB|=(1<<PB1);
        _delay_ms(200);
        FLAG1=0;
            }

       if(FLAG2==1){
                PORTB|=(1<<PB6);
        _delay_ms(200);
        FLAG2=0;
            }

       else{
        PORTB&=~(1<<PB0);
         _delay_ms(200);
          PORTB&=~(1<<PB1);
         _delay_ms(200);
         PORTB&=~(1<<PB6);
         _delay_ms(200);
       }
    }
    return 0;
}

ISR(INT0_vect)
{
    FLAG = 1;
}
ISR(INT1_vect)
{
    FLAG1 = 1;
}
ISR(PCINT1_vect)
{
    FLAG2 = 1;
}


