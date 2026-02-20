#include <stdio.h>
#include "Stack_LinkedList.h"

int main()
{
	// 스택 생성
	Stack stack;
	stack.Push(Stack::CreateNode(10));
	stack.Push(Stack::CreateNode(20));
	stack.Push(Stack::CreateNode(30));
	stack.Push(Stack::CreateNode(40));

	int count = stack.Size();
	printf("Size : %d\n", count);

	// 스택이 빌 때까지 하나씩 출력
	for (int i = 0; i < count; i++)
	{
		if (stack.IsEmpty() == true)
			break;

		Node* temp = stack.Pop();
		printf("pop : %d\n", temp->Data);
		Stack::DestoryNode(&temp);

		if (stack.IsEmpty() == false)
			printf("Top : %d\n", stack.Top()->Data);
		else
			printf("스택 비었음둥!\n");
	}

	return 0;
}