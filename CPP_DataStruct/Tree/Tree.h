#pragma once

#include<stdio.h>
#include<stack>
#include<queue>
#include <iostream>
using namespace std;

template<typename T>
class Tree 
{
public:
	struct Node;

public:
	// 자식 추가
	void AddChild(Node* parent, Node* child)
	{
		// 왼쪽 자식이 비어있다면 먼저 채우기
		if (parent->LeftChild == NULL) 
		{
			parent->LeftChild = child;

			return;
		}

		// 오른쪽 자식 채우기
		Node* node = parent->LeftChild;
		while (node->RightSibling != NULL)
			node = node->RightSibling;

		node->RightSibling = child;
	}

	// 노드 출력
	void PrintNode(Node* node, int depth) 
	{
		for (int i = 0; i < depth; i++)
			cout << "-";

		cout << node->Data << endl;
		queue.push(node->Data);
		stack.push(node);

		
		if (node->LeftChild != NULL)
			PrintNode(node->LeftChild,depth+1);
	
		if (node->RightSibling != NULL)
			PrintNode(node->RightSibling, depth);
	}

public:
	// 노드 생성
	static Node* CreateNode(T data) 
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = NULL;
		node->RightSibling = NULL;

		return node;
	}

	// 노드 삭제
	static void DestoryNode(Node** node) 
	{
		delete* node;
		*node = NULL;
	}

public:
	stack<Node*>* Stack() { return &stack; }
	queue<T>* Queue() { return &queue; }

public:
	struct  Node
	{
		T Data;

		Node* LeftChild;
		Node* RightSibling;

		~Node()
		{
			Data = 0;

			LeftChild = NULL;
			RightSibling = NULL;
		}
	};



private:
	queue<T> queue;
	stack<Node*> stack;

};