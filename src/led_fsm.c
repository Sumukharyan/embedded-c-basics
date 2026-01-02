#include <stdio.h>
#include "led.h"
#include "led_fsm.h"

static led_state_t current_state;

void led_fsm_init(void)
{
    current_state = LED_STATE_OFF;
    led_off();
}

void led_fsm_update(void)
{
    switch (current_state)
    {
    case LED_STATE_OFF:
        led_on();
        current_state = LED_STATE_ON;
        break;

    case LED_STATE_ON:
        printf("Blink mode\n");
        current_state = LED_STATE_BLINK;
        break;

    case LED_STATE_BLINK:
        led_off();
        current_state = LED_STATE_OFF;
        break;

    default:
        current_state = LED_STATE_OFF;
        break;
    }
}
