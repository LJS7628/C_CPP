/*
 연결 리스트(Linked List)
	논리적인 선형구조를 가지는 리스트

	물리적인 선형구조
		실제로 데이터가 연속적으로 위치하는 구조
		다음 데이터는 +1 과 같이, 연산으로 표현 가능

	논리적인 선형구조
		실제 데이터는 순서와 상관없이 위치하는 구조
		다음 데이터가 어디에 있는지를 알고 있고,
		해당 정보를 따라가면, 선형구조와 같이 보이는 구조

	노드(Node)
		자료구조에서 각 데이터의 단위
		노드에는 다음과 같은 두가지 정보가 담겨 있음
		*데이터
		*다음 노드의 위치(논리적인 선형구조를 만들 수 있음)

단일 연결 리스트 / 이중 연결 리스트
	단일 연결 리스트 : 노드가 다음 노드만 알고 있음
	이중 연결 리스트 : 노드가 다음 노드와 이전 노드를 알고 있음

	단일 연결 리스트의 구조가 비교적 간단한 편
	하지만, 역방향 탐색이 불가능함
		삽입/삭제 과정에서 이전 노드를 기억해야 함
		이중 연결 리스트를 사용하면 단점이 해결굄

연결 리스트의 구조
	head : 연결리스트의 시작점(가장 앞에 있는 노드의 위치)
	tail : 연결리스트의 끝점(가장 뒤에 있는 노드의 위치)

단일 연결리스트의 기능과 속성
	head
		리스트의 가장 앞 노드의 위치
	append
		리스트의 가장 뒤에 값을 추가하는 삽입
		입력
				head
				data
	insert
		리스트의 원하는 위치에 값을 추가하는 삽입
	delete
		리스트의 원하는 값을 삭제
	search
		리스트에서 원하느 값을 가진 노드를 반환
	modify
		리트스에서 특정 데이터를 가진 노드의 데이터를 수정
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* next;
}NODE, * pNODE;

pNODE get_node(char data);
void append(pNODE* phead, char data);
pNODE append2(pNODE phead, char data);
int main() {
	pNODE head = NULL;
	append(&head, 'A');
	append(&head, 'B');
	append(&head, 'C');
	append(&head, 'D');

	for (pNODE i = head; i != NULL; i = i->next) {
		printf("%c:", i->data);
	}
	printf("\n");
	//A:B:C:D:

	head = NULL;
	head = append2(head, 'A');
	head = append2(head, 'B');
	head = append2(head, 'C');
	head = append2(head, 'D');

	for (pNODE i = head; i != NULL; i = i->next) {
		printf("%c:", i->data);
	}
	printf("\n");
	//A:B:C:D:
}

pNODE get_node(char data) {
	pNODE new = malloc(sizeof(NODE));
	new->data = data;
	new->next = NULL;
	return new;
}

void append(pNODE* phead, char data) {
	//0. 만약 리스트가 비어있다면
	if (*phead == NULL) {
		*phead = get_node(data);
		return;
	}
	//1. 현재 가장 마지막 노드를 확인
	pNODE tail = *phead;
	while (tail->next != NULL) { //tail != NULL 은 안됨!
		tail = tail->next;//tail 을 다음 노드로 전진
	}
	//tail이 가장 마지막 노드를 가르키고 있음

	// 2. 현재 가장 마지막 노드의
	// 다음노드를 새로만든 노드로 저장
	tail->next = get_node(data);
}

pNODE append2(pNODE curr, char data) {
	//1. 현재 노드가 비어있는지 확인
	//(현재 노드가 비어있다면, 이전 노드가 마지막 노드)
	if (curr == NULL) {
		//새로운 노드라고 대답
		return get_node(data);
	}

	//내 다음노드는 뭐야?(재귀)
	curr->next = append2(curr->next, data);

	//올바른 다음 노드를 대답
	//올바른 다음 노드 : 자기 자신
	return curr;
}