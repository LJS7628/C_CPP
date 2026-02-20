#include <queue>
#include "Queue.h"

int main()
{
	// 큐 생성
	Queue<int> queue;
	queue.Enqueue(Queue<int>::CreateNode(10));
	queue.Enqueue(Queue<int>::CreateNode(20));
	queue.Enqueue(Queue<int>::CreateNode(30));

	printf("Size : %d\n", queue.Size());

	// 큐가 빌때까지 출력
	while (queue.IsEmpty() == false)
	{
		Queue<int>::Node* node = queue.Dequeue();
		printf("Dequeue : %d\n", node->Data);

		Queue<int>::DestroyNode(&node);
	}

	return 0;
}