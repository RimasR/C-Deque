#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

struct DequeNode {
	int value;
	DequeElementPointer previous;
	DequeElementPointer next;
};

int CreateDeque(Deque * Dequeue)
{
	if (Dequeue->isCreated == 0) {
		Dequeue->first = NULL;
		Dequeue->last = NULL;
		Dequeue->isCreated = 1;

		return 1;
	}
	return 0;
}

int EraseDeque(Deque * Dequeue)
{
	if (Dequeue->isCreated == 1) {
		if (IsEmpty(Dequeue) == 1) {
			return 1;
		}

		struct DequeNode *node;
		struct DequeNode *nextNode;

		node = Dequeue->first;
		nextNode = node;

		while (nextNode != NULL) {
			nextNode = node->next;
			free(node);
			node = nextNode;
			Dequeue->first = nextNode;
		}

		free(node);
		Dequeue->first = NULL;
		Dequeue->last = NULL;

		return 1;
	}
	return 0;
}

int DeleteDeque(Deque * Dequeue)
{
	if (Dequeue->isCreated == 1) {
		if (EraseDeque(Dequeue)) {
			Dequeue->isCreated = 0;
			return 1;
		}
		return 0;
	}
	return -1;
}

int PushFirst(Deque * Dequeue, int variable)
{
	if (IsCreated(Dequeue)) {
		struct DequeNode *node = (struct DequeNode*)malloc(sizeof(struct DequeNode));
		node->value = variable;
		node->previous = NULL;
		node->next = Dequeue->first;
		Dequeue->first = node;

		if (node->next != NULL) {
			node->next->previous = Dequeue->first;
		}

		if (Dequeue->last == NULL) {
			Dequeue->last = node;
		}
		return 1;
	}
	return 0;
}

int PushLast(Deque * Dequeue, int variable)
{
	if (IsCreated(Dequeue)) {
		struct DequeNode *node = (struct DequeNode*)malloc(sizeof(struct DequeNode));
		node->value = variable;
		node->previous = Dequeue->last;
		node->next = NULL;
		Dequeue->last = node;

		if (node->previous != NULL) {
			node->previous->next = Dequeue->last;
		}

		if (Dequeue->first == NULL) {
			Dequeue->first = node;
		}
		return 1;
	}
	return -1;
}

int PopFirst(Deque * Dequeue, int * variable)
{
	if (IsCreated(Dequeue)) {
		struct DequeNode *node;
		
		if (!IsEmpty(Dequeue)) {
			node = Dequeue->first;
			*variable = node->value;

			if (node->next != NULL) {
				node->next->previous = NULL;
				Dequeue->first = node->next;
			}
			else {
				Dequeue->first = NULL;
				Dequeue->last = NULL;
			}

			free(node);
			return 1;
		}
		return 0;
	}
	return -1;
}

int PopLast(Deque * Dequeue, int * variable)
{
	if (IsCreated(Dequeue)) {
		struct DequeNode *node;

		if (!IsEmpty(Dequeue)) {
			node = Dequeue->last;
			*variable = node->value;

			if (node->previous != NULL) {
				node->previous->next = NULL;
				Dequeue->last = node->previous;
			}
			else {
				Dequeue->first = NULL;
				Dequeue->last = NULL;
			}

			free(node);
			return 1;
		}
		return 0;
	}
	return -1;
}

int PeekFirst(Deque * Dequeue, int * variable)
{
	if (IsCreated(Dequeue)) {
		if (IsEmpty(Dequeue)) {
			return 0;
		}

		struct DequeNode *node;
		node = Dequeue->first;
		*variable = node->value;
		return 1;
	} 
	return -1;
}

int PeekLast(Deque * Dequeue, int * variable)
{
	if (IsCreated(Dequeue)) {
		if (IsEmpty(Dequeue)) {
			return 0;
		}

		struct DequeNode *node;
		node = Dequeue->last;
		*variable = node->value;
		return 1;
	}
	return -1;
}

int IsEmpty(Deque * Dequeue)
{
	if (Dequeue->isCreated == 1) {
		if (Dequeue->first == NULL && Dequeue->last == NULL) {
			return 1;
		}
		return 0;
	}
	return -1;
}

int IsCreated(Deque * Dequeue)
{
	if (Dequeue->isCreated == 1) {
		return 1;
	}
	return 0;
}

int * ToArray(Deque * Dequeue)
{
	int count = Count(Dequeue);
	int * dequeArray = malloc(count * sizeof(int*));
	if (IsCreated(Dequeue)) {
		struct DequeNode *node;
		node = Dequeue->first;

		for (int i = 0; i < count; i++) {
			dequeArray[i] = node->value;
			node = node->next;
		}
		
		return dequeArray;
	}
	return dequeArray;
}

int Count(Deque * Dequeue)
{
	if (IsCreated(Dequeue)) {
		struct DequeNode *node;
		int count = 0;

		node = Dequeue->first;

		while (node != NULL) {
			count++;
			node = node->next;
		}
		return count;
	}
	return -1;
}
