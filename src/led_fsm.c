#include <stdio.h>
#include "led.h"
#include "led_fsm.h"
#include "timer.h"

static led_state_t current_state;
static unsigned long last_transition_time;

void led_fsm_init(void)
{
    current_state = LED_STATE_OFF;
    last_transition_time = timer_get_ms();
    led_off();
}

void led_fsm_update(void)
{
    unsigned long now = timer_get_ms();

    if ((now - last_transition_time) < 1000)
        return; // non-blocking wait

    last_transition_time = now;

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
void led_fsm_task(void)
{
    led_fsm_update();
}
