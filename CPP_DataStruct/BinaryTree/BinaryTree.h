#pragma once

#include <iostream>
using namespace std;

template<typename T>
class BTree 
{
public:
	struct Node;

public:
	// 생성자 및 소멸자
	BTree() {}
	~BTree() { Destory(root); }

public:
	// 전위 순회
	void PreOrder(Node* node) 
	{
		if (node == NULL) return;

		cout << " " << node->Data << " ";

		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	// 중위 순회
	void InOrder(Node* node)
	{
		if (node == NULL) return;

		InOrder(node->Left);

		cout << " " << node->Data << " ";

		InOrder(node->Right);
	}

	// 후위 순회
	void PostOrder(Node* node)
	{
		if (node == NULL) return;

		PostOrder(node->Left);

		PostOrder(node->Right);

		cout << " " << node->Data << " ";
	}

private:
	// 트리 삭제
	void Destory(Node* node) 
	{
		if (node == NULL) return;

		Destory(node->Left);
		Destory(node->Right);

		DestoryNode(&node);
	}

public:
	// 노드 생성
	static Node* CreateNode(T data) 
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;

		return node;
	}
	// 노드 삭제
	static void DestoryNode(Node** node) 
	{
		delete* node;
		*node = NULL;
	}

public:
	// 루트 설정
	void Root(Node* node) { root = node; }

public:
	struct Node 
	{
		T Data;

		Node* Left;
		Node* Right;
	};

private:
	Node* root;
};