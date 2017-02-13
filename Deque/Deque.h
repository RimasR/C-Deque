#ifndef HEADER
#define HEADER

typedef struct DequeNode DequeElement;
typedef struct DequeNode* DequeElementPointer;
typedef struct DequeStructure Deque;

struct DequeStructure {
	DequeElementPointer first;
	DequeElementPointer last;
	int isCreated;
};

int CreateDeque(Deque *Dequeue);
int EraseDeque(Deque *Dequeue);
int DeleteDeque(Deque *Dequeue);
int PushFirst(Deque *Dequeue, int variable);
int PushLast(Deque *Dequeue, int variable);
int PopFirst(Deque *Dequeue, int *variable);
int PopLast(Deque *Dequeue, int *variable);
int PeekFirst(Deque *Dequeue, int *variable);
int PeekLast(Deque *Dequeue, int *variable);
int IsEmpty(Deque *Dequeue);
int IsCreated(Deque *Dequeue);
int * ToArray(Deque *Dequeue);
int Count(Deque *Dequeue);

#endif // !HEADER

