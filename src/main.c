#include "scheduler.h"
#include "led_fsm.h"
#include "logger.h"

int main(void)
{
    led_fsm_init();

    scheduler_add_task(led_fsm_task);
    scheduler_add_task(logger_task);

    while (1)
    {
        scheduler_run();
    }

    return 0;
}
