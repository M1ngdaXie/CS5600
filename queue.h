#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Process structure definition
typedef struct {
    int id;
    char* name;
} process_t;

// Node structure for the queue
typedef struct node {
    void* data;
    struct node* next;
} node_t;

// Queue structure
typedef struct {
    node_t* front;
    node_t* rear;
} queue_t;

// Function prototypes
queue_t* create_queue();
void enqueue(queue_t* queue, void* element);
void* dequeue(queue_t* queue);
void print_queue(queue_t* queue);
int is_empty(queue_t* queue);

#endif // QUEUE_H