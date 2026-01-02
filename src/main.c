#include <stdio.h>
#include "led.h"

int main(void)
{
    led_init();

    led_on();
    printf("Delay...\n");

    led_off();

    return 0;
}
