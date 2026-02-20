#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Graph 
{
public:
	struct Edge;
	struct Node;

public:
	// 노드 추가
	void AddNode(Node* node) 
	{
		Node* nodeList = Head;
		// 첫 노드인 경우
		if (nodeList != NULL) 
		{
			while (nodeList->Next != NULL)
				nodeList = nodeList->Next;

			nodeList->Next = node;
		}
		// 노드가 있는 경우
		else 
		{
			Head = node;
		}

		node->Index = Count++;
	}

	// 엣지 추가
	void AddEdge(Node* node, Edge* edge) 
	{
		// 첫 엣지인 경우
		if (node->Edge != NULL) 
		{
			Edge* edgeList = node->Edge;

			while (edgeList->Next != NULL)
				edgeList = edgeList->Next;

			edgeList->Next = edge;
		}
		// 엣지가 있는 경우
		else 
		{
			node->Edge = edge;
		}
	}

	// 그래프 출력
	void Print() 
	{
		Node* node = NULL;
		Edge* edge = NULL;

		if ((node = Head) == NULL)
			return;

		while (node != NULL) 
		{
			cout << node->Data << " : ";

			if ((edge = node->Edge) == NULL) 
			{
				node = node->Next;
				cout << endl;

				continue;
			}

			while (edge != NULL) 
			{
				cout << edge->Target->Data;
				edge = edge->Next;
			}

			cout << endl;

			node = node->Next;

		}

		cout << endl;
	}

public:
	// 엣지 생성
	static Edge* CreateEdge(Node* start, Node* target) 
	{
		Edge* edge = new Edge();
		edge->Start = start;
		edge->Target = target;
		edge->Next = NULL;

		return edge;
	}

	// 노드 생성
	static Node* CreateNode(T data) 
	{
		Node* node = new Node();
		node->Data = data;

		return node;
	}

public:
	struct Edge 
	{
		Node* Start = NULL;
		Node* Target = NULL;
		Edge* Next = NULL;
	};

	struct Node 
	{
		T Data;
		int Index = -1;

		Node* Next = NULL;
		Edge* Edge = NULL;
	};

private:
	Node* Head = NULL;
	int Count = 0;
};