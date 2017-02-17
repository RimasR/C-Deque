#ifndef DEQUE_H
#define DEQUE_H

typedef int nodeVar; // CHANGE TO ANOTHER STRUCTURE IF NEEDED

typedef struct DequeNode DequeElement;
typedef struct DequeNode* DequeElementPointer;
typedef struct DequeStructure Deque;

struct DequeStructure {
	DequeElementPointer first;
	DequeElementPointer last;
	int isCreated;
};

struct DequeNode {
	nodeVar value;
	DequeElementPointer previous;
	DequeElementPointer next;
};

int CreateDeque(Deque *Dequeue); // Returns: 1 - Created, 0 - Deque already created
int EraseDeque(Deque *Dequeue); // Returns: 1 - Erased, 0 - Deque is not created
int DeleteDeque(Deque *Dequeue); // Returns: 1 - Deleted, 0 - Cannot delete deque (probably not created), -1 - deque not created
int PushFirst(Deque *Dequeue, nodeVar variable); // Returns: 1 - pushed successfully, 0 - deque is not created
int PushLast(Deque *Dequeue, nodeVar variable); // Returns: 1 - pushed successfully, 0 - deque is not created
int PopFirst(Deque *Dequeue, nodeVar *variable); // Returns: 1 - popped successfully, 0 - deque is empty, -1 - deque is not created
int PopLast(Deque *Dequeue, nodeVar *variable); // Returns: 1 - popped succesfully, 0 - deque is empty, -1 - deque is not created
int PeekFirst(Deque *Dequeue, nodeVar *variable); // Returns: 1 - peeked succesfully, 0 - deque is empty, -1 - deque is not created
int PeekLast(Deque *Dequeue, nodeVar *variable); // Returns: 1 - peeked succesfully, 0 - deque is empty, -1 - deque is not created
int IsEmpty(Deque *Dequeue); // Returns: 1 - deque is empty, 0 - deque is not empty, -1 - deque is not created
int IsCreated(Deque *Dequeue); // Returns: 1 - deque is created, 0 - deque is not created
int * ToArray(Deque *Dequeue); // Returns array of variables in deque
int Count(Deque *Dequeue); // Returns number of variables in deque or -1 if deque is not created

#endif

