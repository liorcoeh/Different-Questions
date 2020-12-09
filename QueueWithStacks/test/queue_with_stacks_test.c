
#include "../include/queue_with_stacks.h"
#include "../include/stack.h"

int main()
{
    int capacity = 20;
    int i = 0;

    queue_t *main_queue = QueueCreate(capacity);

    printf("The queue size is(0): %d\n", QueueSize(main_queue));

    for (i = 0; i < 25; ++i)
    {
        QueueEnqueue(main_queue, ((i + 1)* 2));
    }

    printf("The queue size now, is(20): %d\n", QueueSize(main_queue));
    printf("\n");

    for (i = 0; i < 10; ++i)
    {
        printf("Value being poping out is(%d): %d\n", ((i + 1) * 2), QueuePeek(main_queue));
        QueueDequeue(main_queue);
    }
    
    printf("\n");
    printf("The queue size now, is(10): %d\n", QueueSize(main_queue));
    printf("\n");

    QueueDestroy(main_queue);

    return (0);
}