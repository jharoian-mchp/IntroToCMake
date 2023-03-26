#include <xc.h>

void pc18_init();
void pc18_LED_on(void);
void pc18_LED_off(void);
void pc18_LED_toggle(void);

void systick_init(void);
uint32_t systick_not_expired(void);


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

void pc18_init(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTSET = PORT_OUTSET_OUTSET(PORT_PC18);
    port_regs->GROUP[2].PORT_DIRSET = PORT_DIRSET_DIRSET(PORT_PC18);    
}

void pc18_LED_on(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTCLR = PORT_OUTCLR_OUTCLR(PORT_PC18);    
}

void pc18_LED_off(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTSET = PORT_OUTSET_OUTSET(PORT_PC18);
}

void pc18_LED_toggle(void) {
    port_registers_t* port_regs = (port_registers_t *)PORT_REGS;
    port_regs->GROUP[2].PORT_OUTTGL = PORT_OUTTGL_OUTTGL(PORT_PC18);    
}

void systick_init(void) {
    // 3Hz = 16,000,000 or 0xF42400
    SysTick->LOAD = 0xF42400;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
}

uint32_t systick_not_expired(void) {
    return(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
}
