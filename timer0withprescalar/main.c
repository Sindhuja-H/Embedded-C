/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    DDRD|=(1<<PD6);
    PORTD|=(1<<PD6);
    TCCR0B|=(1<<CS02);
    TCNT0=0;
    sei();

    while(1)
    {
        if(TCNT0>=124)
        {
            PORTD^=(1<<PD6);
            TCNT0=0;
        }
     else
    {
        TCNT0++;
    }
    }
    return 0;
}
