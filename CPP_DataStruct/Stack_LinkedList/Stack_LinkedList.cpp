#include "Stack_LinkedList.h"

// 생성자 및 소멸자
Stack::Stack() {}

Stack::~Stack()
{
	while (IsEmpty() == false)
	{
		Node* node = Pop();
		DestoryNode(&node);
	}

	list = NULL;
	top = NULL;
}

// 삽입
void Stack::Push(Node* node)
{
	// 스택이 비어있을 때
	if (list != NULL)
	{
		Node* oldTop = list;
		while (oldTop->NextNode != NULL)
			oldTop = oldTop->NextNode;

		oldTop->NextNode = node;
	}
	else
	{
		list = node;
	}

	top = node;

}

// 제거
Node* Stack::Pop()
{
	Node* temp = top;

	// 스택이 비어 있을 때
	if (list == top)
	{
		list = NULL;
		top = NULL;
	}
	else
	{
		Node* currentTop = list;
		while (currentTop != NULL && currentTop->NextNode != top)
			currentTop = currentTop->NextNode;

		top = currentTop;
		currentTop->NextNode = NULL;
	}

	return temp;
}

// 스택 사이즈 구하기
int Stack::Size()
{
	int count = 0;
	Node* node = list;

	while (node != NULL)
	{
		node = node->NextNode;
		count++;
	}

	return count;
}

// 노드 생성
Node* Stack::CreateNode(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->NextNode = NULL;

	return node;
}

// 노드 삭제
void Stack::DestoryNode(Node** node)
{
	delete* node;
	*node = NULL;
}
