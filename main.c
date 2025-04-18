#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 16000000UL

int main(void) {
    int isOn = 0;
    unsigned int buttonOld = 1;
    unsigned int buttonNew;

    // set input pin and pull up
    DDRD &= ~(1 << DDD2);
    PIND |= (1 << PIND2); 

    // set output pin
    DDRD |= (1 << DDD3);

    /*
    toggle button:
    states = not pressed && off, pressed && off, not pressed && on, pressed && on
    isOn
    
    */
    while(1) {
        buttonNew = (PIND >> PIND2);

        if (buttonNew & 0x01 && !(buttonOld & 0x01)) {
            if (isOn) {
                PORTD &= ~(1 << PORTD3);
            } else {
                PORTD |= (1 << PORTD3);
            }
            isOn = !isOn;
        }

        buttonOld = buttonNew;
        _delay_ms(100);
    }

    return 0;
}