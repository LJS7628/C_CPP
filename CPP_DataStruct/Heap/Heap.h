#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Heap 
{
public:
	struct Node;

public:
	// 생성자 및 소멸자
	Heap(int capacity)
		: capacity(capacity) 
	{
		nodes = new Node[capacity];
		size = 0;
	}
	
	~Heap() 
	{
		delete nodes;
		nodes = nullptr;
	}

	//부모 반환
	int Parent(int index) 
	{
		return (int)((index - 1) / 2);
	}

	// 왼쪽 자식 반환
	int LeftChild(int index)
	{
		return index * 2 + 1;
	}

	// 노드 교환
	void SwapNode(int index1, int index2) 
	{
		Node* temp = new Node();
		memcpy(temp, &nodes[index1], sizeof(Node));
		memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
		memcpy(&nodes[index2], temp, sizeof(Node));

		delete temp;
	}

	// 노드 삽입
	void Insert(Node data) 
	{
		int current = size;
		int parent = Parent(current);

		// 가득 찼다면
		if (size == capacity) 
		{
			// 용량을 2배로 하고 기존 힙을 복사
			Node* temp = new Node[capacity * 2];
			memcpy(temp,nodes,sizeof(Node)*capacity);

			//삭제
			delete[] nodes;
			nodes = temp;

			//용량 갱신
			capacity *=2;
		}

		nodes[current] = data;

		// 힙 성질을 유지하기 위해 최소값을 부모로 설정
		while (current > 0 && nodes[current].Data < nodes[parent].Data) 
		{
			SwapNode(current, parent);

			current = parent;
			parent = Parent(current);
		}

		size++;
	}

	// 힙 출력
	void Print() 
	{
		for (int i = 0; i < size; i++) 
		{
			int parent = -1;
			if (i > 0)
				parent = Parent(i);

			cout << nodes[i].Data << "|" << parent << ",";
		}
		cout << endl << endl;
	}

	// 최소값 삭제 (루트 삭제)
	Node RemoveMin()
	{
		int parent = 0;
		int left = 0;
		int right = 0;

		// 루트 노드 임시 보관
		Node result;
		memcpy(&result, &nodes[0], sizeof(Node));

		size--;
		SwapNode(0, size); // 마지막 노드와 루트를 바꿈

		//자식 인덱스 계산 
		left = LeftChild(0);
		right = left + 1;

		// 자식들과 비교하며 아래로 내려가기
		while (true)
		{
			int selected = 0;

			// 자식이 하나도 없으면  종료
			if (left >= size)
				break;

			// 왼쪽 자식만 있는 경우
			if (right >= size)
			{
				selected = left;
			}
			// 왼쪽, 오른쪽 자식 둘 다 있는 경우: 더 작은 자식을 선택
			else
			{
				if (nodes[left].Data > nodes[right].Data)
					selected = right; // 오른쪽이 더 작으므로 오른쪽 선택
				else
					selected = left;  // 왼쪽이 더 작거나 같으므로 왼쪽 선택
			}

			// 부모와 선택된 자식 비교
			if (nodes[selected].Data < nodes[parent].Data)
			{
				// 자식이 더 작으면 위치를 바꿈 
				SwapNode(parent, selected);

				// 바뀐 위치를 새로운 부모로 설정
				parent = selected;
			}
			else
				// 부모가 자식보다 작거나 같으면 정렬 완료
				break;

			// 다음 자식 노드들의 인덱스 갱신
			left = LeftChild(parent);
			right = left + 1;
		}

		// 처음 보관했던 최솟값 반환
		return result;
	}


	// 비어있는지 체크
	bool Empty() { return size == 0; }

public:
	struct Node 
	{
		T Data;

		Node() {}
		Node(T data) { Data = data; }
	};

private:
	Node* nodes;

	int capacity;
	int size;
};