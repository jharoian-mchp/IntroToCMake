// LED functions

#include <xc.h>
#include "led.h"

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
