#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned volatile overflow;
int main(void)
{
    DDRD|=(1<<PD6);
    //PORTD|=(1<<PD6);
    TCCR1B|=(1<<CS12);
    TIMSK1|=(1<<TOIE1);
    TCNT1=0;
    overflow=0;
    sei();


    while(1)
    {
         if(overflow>=12)
        {
            if(TCNT1>=53)
            {
                PORTD^=(1<<PD6);
                TCNT1=0;
                overflow=0;
            }

        }

    }


    return 0;
}
ISR(TIMER1_OVF_vect)
{
    overflow++;
}
