#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM00);
    TCCR0B|=(1<<CS01)|(1<<CS00);
    DDRD|=(1<<PD6);

    while(1)
    {
        OCR0A=10;
        _delay_ms(200);
         OCR0A=50;
        _delay_ms(200);
         OCR0A=100;
        _delay_ms(200);
         OCR0A=150;
        _delay_ms(200);
         OCR0A=200;
        _delay_ms(200);
         OCR0A=250;
        _delay_ms(200);
    }

    return 0;
}
