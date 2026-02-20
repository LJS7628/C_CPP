#pragma once
#include <stdio.h>

template<typename T>
class Queue
{
public:
	struct Node;

public:
	// 생성자 및 소멸자
	Queue(){}
	~Queue()
	{
		while (IsEmpty() == false)
		{
			Node* node = Dequeue();
			DestroyNode(&node);
		}
	}

	// 삽입
	void Enqueue(Node* node)
	{
		// 큐가 비어있는 경우
		if (front == NULL)
		{
			front = node;
			rear = node;

			count++;

			return;
		}

		// 맨 뒤에 노드 추가
		rear->Next = node;
		rear = node;

		count++;
	}

	// 삭제
	Node* Dequeue()
	{
		Node* node = front;

		if (front->Next == NULL)
			front = rear = NULL;
		else
			front = front->Next;

		count--;

		return node;
	}

	// 큐 사이즈 구하기
	int Size() { return count; }

	// 큐 비어있는지 체크
	bool IsEmpty()
	{
		return front == NULL;
	}

public:
	// 노드 생성
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	// 노드 삭제
	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}

public:
	struct Node
	{
		T Data;
		Node* Next;
	};

private:
	int count = 0;

	Node* front = NULL;
	Node* rear = NULL;
};
