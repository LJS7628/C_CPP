#pragma once

#include <iostream>
using namespace std;

template<typename T>
class BTree
{
public:
	struct Node;

public:

	// 기본 생성자 및 소멸자
	BTree() {}
	~BTree() {}

	// 노드 삽입
	void Insert(Node** parent, Node* child)
	{
		// 부모의 값 보다 자식의 값이 큰 경우 오른쪽 삽입
		if ((*parent)->Data < child->Data)
		{
			// 오른쪽 자식이 없을 때
			if ((*parent)->Right == NULL)
				(*parent)->Right = child;
			else
				// 오른쪽 자식이 없을 때 까지 재귀 탐색
				Insert(&(*parent)->Right, child);
		}
		// 부모의 값이 자식의 값보다 큰 경우 왼쪽 삽입
		else if ((*parent)->Data > child->Data)
		{
			// 왼쪽 자식이 없을 때
			if ((*parent)->Left == NULL)
				(*parent)->Left = child;
			else
				// 왼쪽 자식이 없을 때 까지 재귀 탐색
				Insert(&(*parent)->Left, child);
		}
	}

	// 노드 탐색
	Node* Search(Node* node, T data, int& depth)
	{
		if (node == NULL)
			return NULL;

		depth++;

		// 탐색 완료
		if (node->Data == data)
			return node;

		// 노드 값이 찾는 값보다 작다면 왼쪽 탐색
		else if (node->Data > data)
			return Search(node->Left, data, depth);

		// 노느 값이 찾는 값보다 크다면 오른쪽 탐색
		else if (node->Data < data)
			return Search(node->Right, data, depth);

		return NULL;
	}

	// 중위 순회
	void InOrder(Node* node, int depth)
	{
		if (node == NULL)
			return;

		depth++;

		InOrder(node->Left, depth);

		cout << " " << node->Data << "|" << depth;

		InOrder(node->Right, depth);
	}

	// 노드 제거
	Node* Remove(Node* node, Node* parent, T data)
	{
		Node* remove = NULL;
		if (node == NULL)
			return NULL;

		if (node->Data > data)
		{
			remove = Remove(node->Left, node, data);
		}
		else if (node->Data < data)
		{
			remove = Remove(node->Right, node, data);
		}
		else //탐색 완료, 노드 삭제
		{
			remove = node;

			if (node->Left == NULL && node->Right == NULL)
			{
				if (parent->Left == node)
					parent->Left = NULL;
				else
					parent->Right = NULL;
			}
			else
			{
				if (node->Left != NULL && node->Right != NULL) //양쪽 모두 존재
				{
					Node* minNode = SearchMinValue(node->Right);

					minNode = Remove(node, NULL, minNode->Data);
					//cout << "minNode : " << minNode->Data << endl;
					node->Data = minNode->Data;

					return minNode;
				}
				else //한쪽만 존재
				{
					Node* temp = NULL;

					if (node->Left != NULL)
						temp = node->Left;
					else
						temp = node->Right;

					if (parent->Left == node)
						parent->Left = temp;
					else
						parent->Right = temp;
				}
			}//if(node->Left)
		} //if(node->Data)

		return remove;
	}

	// 최소값 찾기 => 가장 왼쪽 리프 노드
	Node* SearchMinValue(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->Left == NULL)
			return node;
		else
			return SearchMinValue(node->Left);
	}

	Node* Root() { return root; }
	void Root(Node* root) { this->root = root; }

public:
	//노드 생성
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;

		return node;
	}

	//노드 삭제
	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}

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