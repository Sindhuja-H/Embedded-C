#include <avr/io.h>
#include <avr/interrupt.h>

void port()
{

    DDRB|=(1<<PB0);
    DDRB|=(1<<PB1);
    DDRB|=(1<<PB6);

    DDRD&=~(1<<PD2);
    PORTD|=(1<<PD2);

    DDRD&=~(1<<PD3);
    PORTD|=(1<<PD3);

    DDRC&=~(1<<PC4);
    PORTC|=(1<<PC4);

    EICRA|=(1<<ISC00)|(1<<ISC01);
    EIMSK|=(1<<INT0)|(1<<INT1);
    PCICR|=(1<<PCIE1);
    PCMSK1|=(1<<PCINT12);

    sei();
}
