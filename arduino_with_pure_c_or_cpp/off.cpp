#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/power.h>

int main(void) {
    ADCSRA = 0;    // Disable ADC

    power_all_disable();    // Shut down all timers, USART, SPI, TWI, etc. via PRR register

    // Ports configurations
    DDRB = 0; PORTB = 0;    
    DDRC = 0; PORTC = 0;
    DDRD = 0; PORTD = 0;

    DDRB |= (1 << PB5);     // Set as output 
    PORTB &= ~(1 << PB5);   // Set as low (off)

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // Set power_down mode 

    cli();  // Disable global interrupts
    sleep_enable();     // Set SE bit
    sleep_bod_disable();  // Add this line
    sei();          // Enable global interrupts
    sleep_cpu();    // Enter sleep 
    sleep_disable();    // Never reached without wake up

    return 0;
}