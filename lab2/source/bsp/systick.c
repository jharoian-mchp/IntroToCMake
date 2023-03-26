// SysTick functions

#include <xc.h>
#include "systick.h"

void systick_init(void) {
    // 3Hz = 16,000,000 or 0xF42400
    SysTick->LOAD = 0xF42400;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
}

uint32_t systick_not_expired(void) {
    return(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
}
