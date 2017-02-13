#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main() {
	int var = 0;
	int i = 0;
	int *dequeArray;
	Deque dequeue;
	dequeue.isCreated = 0;
	while (1) {
		printf("1. Create deque, 2. Push to front, 3. Push to bottom, 4. Pop front, 5. Pop bottom, 6. Peek front, 7 Peek bottom, 8. Delete deque \n");
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			if (CreateDeque(&dequeue)) {
				printf("Deque was created successfully \n");
				break;
			}
			printf("Deque is already created. \n");
			break;
		case 2:
			printf("Number to add: ");
			scanf_s("%d", &i);
			if (PushFirst(&dequeue, i)) {
				printf("Number was added successfully to front \n");
				break;
			}
			printf("Deque was not created. Please create deque first. \n");
			break;
		case 3:
			printf("Number to add: ");
			scanf_s("%d", &i);
			if (PushLast(&dequeue, i)) {
				printf("Number was added successfully to back \n");
				break;
			}
			printf("Deque was not created. Please create deque first. \n");
			break;
		case 4:
			var = PopFirst(&dequeue, &i);
			if (var == 1) {
				printf("Popped value in front: %d \n", i);
				break;
			}
			if (var == 0) {
				printf("Deque is empty. \n");
				break;
			}
			printf("Deque is not initialized \n");
			break;
		case 5:
			var = PopLast(&dequeue, &i);
			if (var == 1) {
				printf("Popped value in back: %d \n", i);
				break;
			}
			if (var == 0) {
				printf("Deque is empty. \n");
				break;
			}
			printf("Deque is not initialized \n");
			break;
		case 6:
			var = PeekFirst(&dequeue, &i);
			if (var == 1) {
				printf("Value in front: %d \n", i);
				break;
			}
			if (var == 0) {
				printf("Deque is empty. \n");
				break;
			}
			printf("Deque is not initialized \n");
			break;
		case 7:
			var = PeekLast(&dequeue, &i);
			if (var == 1) {
				printf("Value in front: %d \n", i);
				break;
			}
			if (var == 0) {
				printf("Deque is empty. \n");
				break;
			}
			printf("Deque is not initialized \n");
			break;
		case 8:
			var = DeleteDeque(&dequeue);
			if (var == 1) {
				printf("Deque was deleted successfully \n");
				break;
			}
			printf("Cannot delete deque. Deque is not created. \n");
			break;
		case 9:
			var = Count(&dequeue);
			dequeArray = malloc(var * sizeof(int));
			dequeArray = ToArray(&dequeue);
			printf("Number array: ");
			for (i = 0; i < var; i++) {
				printf("%d ", dequeArray[i]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}