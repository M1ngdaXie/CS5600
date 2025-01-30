#include "queue.h"
#include "caesar.h"

process_t* create_ciphered_process(int id, const char* name, int key) {
    process_t* proc = (process_t*)malloc(sizeof(process_t));
    proc->id = id;
    // Encode the name before storing
    char* encoded_name = encode((char*)name, key);
    proc->name = strdup(encoded_name);
    return proc;
}

void print_decoded_process(process_t* proc, int key) {
    char* decoded_name = decode(proc->name, key);
    printf("[id: %d, name: %s]", proc->id, decoded_name);
}

int main() {
    queue_t* queue = create_queue();
    int key = 3;
    
    printf("Caesar cipher key: %d.\n", key);

    // Create and enqueue processes with encoded names
    process_t* proc1 = create_ciphered_process(1, "A", key);
    printf("Enqueue: [id: %d, name: A] is enqueued. ", proc1->id);
    enqueue(queue, proc1);
    print_queue(queue);

    process_t* proc2 = create_ciphered_process(2, "B", key);
    printf("Enqueue: [id: %d, name: B] is enqueued. ", proc2->id);
    enqueue(queue, proc2);
    print_queue(queue);

    process_t* proc3 = create_ciphered_process(3, "C", key);
    printf("Enqueue: [id: %d, name: C] is enqueued. ", proc3->id);
    enqueue(queue, proc3);
    print_queue(queue);

    // Dequeue and print processes with decoded names
    while (!is_empty(queue)) {
        process_t* proc = (process_t*)dequeue(queue);
        printf("Dequeue: ");
        print_decoded_process(proc, key);
        printf(" is dequeued. ");
        print_queue(queue);
        free(proc->name);
        free(proc);
    }

    free(queue);
    return 0;
}