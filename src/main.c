#include <stdio.h>
#include "led_fsm.h"

int main(void)
{
    led_fsm_init();

    while (1)
    {
        led_fsm_update();

        // Simulated delay
        for (volatile int i = 0; i < 100000000; i++)
            ;
    }

    return 0;
}
