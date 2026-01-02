#include "scheduler.h"

#define MAX_TASKS 5

static task_func_t task_list[MAX_TASKS];
static int task_count = 0;

void scheduler_add_task(task_func_t task)
{
    if (task_count < MAX_TASKS)
    {
        task_list[task_count++] = task;
    }
}

void scheduler_run(void)
{
    for (int i = 0; i < task_count; i++)
    {
        task_list[i]();
    }
}
