#include "bsp/led.h"
#include "bsp/systick.h"

int main() {
    // Embedded Hello World
    // Blink User LED0 which is attached to PC18
    // Low turns on LED and High turns off
    pc18_init();
    systick_init();

    while(1) {
        pc18_LED_toggle();
        while(systick_not_expired());
    }
}
