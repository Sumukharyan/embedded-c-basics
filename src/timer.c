#include "timer.h"
#include <time.h>

unsigned long timer_get_ms(void)
{
    return (unsigned long)(clock() * 1000 / CLOCKS_PER_SEC);
}
