#ifndef LED_FSM_H
#define LED_FSM_H

typedef enum
{
    LED_STATE_OFF = 0,
    LED_STATE_ON,
    LED_STATE_BLINK
} led_state_t;

void led_fsm_init(void);
void led_fsm_update(void);

#endif
