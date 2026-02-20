#include <iostream>
#include "LinkedList.h"
using namespace std;

// 노드 생성
Node* Create(DataType data)
{
	Node* node = new Node();

	node->Data = data;
	node->NextNode = NULL;

	return node;
}

// 노드 삭제
void Destroy(Node* node)
{
	delete node;
	node = NULL;
}

// 노드 삽입 (뒤에)
void Push(Node** head, Node* node)
{
	if ((*head) != NULL)
	{
		Node* tail = (*head);

		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
	}
	else
	{
		*head = new Node();
	}
}

// 노드 삽입
void Insert(Node* current, Node* node)
{
	node->NextNode = current->NextNode;
	current->NextNode = node;
}

// 노드 삽입 (머리)
void InsertHead(Node** current, Node* head)
{
	if (*current == NULL)
	{
		*current = head;
	}
	else
	{
		head->NextNode = *current;
		*current = head;
	}
}

// 노드 제거
void Remove(Node** head, Node* remove)
{
	if (*head == remove)
	{
		*head = remove->NextNode;
	}
	else
	{
		Node* current = *head;
		while (current != NULL && current->NextNode != remove)
			current = current->NextNode;

		if (current != NULL)
			current->NextNode = remove->NextNode;
	}
}

// 특정 노드 구하기
Node* GetNode(Node* head, int index)
{
	Node* current = head;

	while (current != NULL && (--index >= 0))
		current = current->NextNode;

	return current;
}

// 노드 길이 구하기
int GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->NextNode;
		count++;
	}

	return count;
}


