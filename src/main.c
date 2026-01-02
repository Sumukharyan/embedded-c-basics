#include "led_fsm.h"

int main(void)
{
    led_fsm_init();

    while (1)
    {
        led_fsm_update();
        // No blocking delay here
    }

    return 0;
}
