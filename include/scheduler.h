#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef void (*task_func_t)(void);

void scheduler_add_task(task_func_t task);
void scheduler_run(void);

#endif
