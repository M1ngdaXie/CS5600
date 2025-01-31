#include "queue.h"

queue_t *create_queue(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	if (!queue) {
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

void enqueue(queue_t *queue, void *element)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));

	if (!new_node) {
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	new_node->data = element;
	new_node->next = NULL;

	if (!queue->rear) {
		queue->front = queue->rear = new_node;
		return;
	}

	queue->rear->next = new_node;
	queue->rear = new_node;
}

void *dequeue(queue_t *queue)
{
	if (!queue->front)
		return NULL;

	node_t *temp = queue->front;
	void *data = temp->data;

	queue->front = queue->front->next;

	if (!queue->front)
		queue->rear = NULL;

	free(temp);
	return data;
}

int is_empty(queue_t *queue)
{
	return queue->front == NULL;
}

void print_queue(queue_t *queue)
{
	if (is_empty(queue)) {
		printf("[Empty]\n");
		return;
	}

	node_t *current = queue->front;

	while (current) {
		process_t *proc = (process_t *)current->data;
		printf("[id: %d, name: %s]", proc->id, proc->name);

		if (current->next)
			printf(" -> ");

		current = current->next;
	}

	printf("\n");
}
