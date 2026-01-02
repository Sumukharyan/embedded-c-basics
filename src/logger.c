#include <stdio.h>
#include "timer.h"

void logger_task(void)
{
    static unsigned long last_log_time = 0;
    unsigned long now = timer_get_ms();

    if ((now - last_log_time) >= 2000)
    {
        printf("System alive\n");
        last_log_time = now;
    }
}
