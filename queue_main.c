#include "queue.h"

process_t* create_process(int id, const char* name) {
    process_t* proc = (process_t*)malloc(sizeof(process_t));
    proc->id = id;
    proc->name = strdup(name);
    return proc;
}

int main() {
    queue_t* queue = create_queue();
    
    // Create and enqueue processes
    process_t* proc1 = create_process(1, "A");
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", proc1->id, proc1->name);
    enqueue(queue, proc1);
    print_queue(queue);

    process_t* proc2 = create_process(2, "B");
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", proc2->id, proc2->name);
    enqueue(queue, proc2);
    print_queue(queue);

    process_t* proc3 = create_process(3, "C");
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", proc3->id, proc3->name);
    enqueue(queue, proc3);
    print_queue(queue);

    // Dequeue and print processes
    while (!is_empty(queue)) {
        process_t* proc = (process_t*)dequeue(queue);
        printf("Dequeue: [id: %d, name: %s] is dequeued. ", proc->id, proc->name);
        print_queue(queue);
        free(proc->name);
        free(proc);
    }

    free(queue);
    return 0;
}