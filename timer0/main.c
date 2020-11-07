/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    PORTD|=(1<<PD6);
    TCCR0B|=(1<<CS00);
    TCNT0=0;
    sei();

    while(1)
    {
        if(TCNT0>=191)
        {
            PORTD^=(1<<PD6);
            TCNT0=0;
        }

    }

    return 0;
}
