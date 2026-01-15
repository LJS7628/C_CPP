/*
그래프(Graph)
		노드 끼리의 관계가 1:1이 아닌 자료구조
		사이클이 가능
			-사이클
			노드를 따라가다보면, 자기 자신이 다시 나올 수 있는 구조
			사이클이 있는 그래프는 "순환 그래프"
		시작점 이라는 개념이 모호

트리(Tree)
	특별한 그래프
	방향성이 있는 그래프
		-노드끼리의 연결이 단방향
	사이클이 불가능
		-비순환 그래프
	시작점 이라는 개념이 있음(Root 노드)
	계층구조

용어
	Node		        : 트리를 구성하는 각 단위
	Root        Node	: 트리의 최상위 노드
	Leaf        Node	: 자식이 없는 노드
	Nonterminal Node	: 자식이 있는 노드

	<다른 노드와의 관계>
	Parent     Node : 내 바로 위의 노드
	Child      Node : 내 바로 아래의 노드
	Sibling    Node : 나와 부모가 같은 노드들
	Ancestor   Node : 내 부모노드를 포함한 윗 단계 노드들
	Descendant Node : 내 자식노드를 포함한 아랫단계 노드들

	<트리의 생김새>
	Sub-Tree	: 트리 안의 특정 노드부터 행당 노드의 자손을 포함하면
				  트리 모양인데, 이를 서브트리 라고 부름

	Forest		: 여러개의 트리를 동시에 관리하는 경우

	level		: Root 노드를 1-level 이라 하였을때, 단계별 총 수를 의미
	Depth		: 특정 노드가 위치한 깊이(위치한 level)
	Height		: 해당 노드부터 시작한 서브트리가 총 몇층인지
	Degree(차수): 노드 : 노드의 차수 는 해당 노드가 몇개의 자식을 가지고 있는지
				  트리 : 트리에 포함된 노드들의 차수 중 가장 높은 차수
						 트리에 포함된 노드에 허용되는 최대 차수

이진트리(Binary Tree)
	차수가 2인 트리
		(트리에 포함된 모든 노드의 자식이 최대 2개인 트리)

이진 탐색 트리(Binary Search Tree)
	이진트리이되, 임의의 노드의 왼쪽 자손은 모두 자신보다 작고
				  오른쪽 자손은 모두 자신보다 큰 트리

이진트리의 노드
	| left | data | right |
	왼쪽 자식과 오르쪽 자식, 그리고 데이터를 저장

Skewed Binary Tree(편향 트리)
	한쪽으로 기울어진 트리
	모든 지식이 한쪽방향에만 있는 트리
	각종 트리를 이용한 알고리즘에 불리

Complete Binary Tree(완전 이진 트리)
	마지막 level을 제외한 모든 level이 가득 차 있는 트리
	마지막 level은 왼쪽부터 차야 함

Full Binary Tree
	모든 level이 가득 차있는 트리


바이너리 트리 순회(Traversal)
	전위 순회(Preorder traversal)  A B D E C F
		1. 현재 노드 방문
		2. 왼쪽 노드로 이동
		3. 오른쪽 노드로 이동
	중위 순회(Inorder traversal)   D B E A F C
		1. 왼쪽 노드 이동
		2. 현재 노드 이동
		3. 오른쪽 노드 이동
	후위 순회(Postorder traversal)  D E B F C A
		1. 왼쪽 노드 이동
		2. 오른쪽 노드 이동
		3. 현재 노드 방문


이진 탐색 트리(BST  : Binary Search Tree)
	노드의 왼쪽 자손은 노드보다 작음
	노드의 오른쪽 자손은 노드보다 큼

	데이터 삽입시 해당 조건에 맞도록 삽입하여야 함

	삽입/탐색시 시간 복잡도 O(log n)

삽입
	1. 현재 노드의 데이터와 삽입하려는 값을 비교
	2.1 만약 삽입하려는 값이 더 작다면
		왼쪽노드로 이동 (1번 부터 다시 시작)
	2.2 만약 삽입하려는 값이 더 크다면
		오른쪽노드로 이동 (1번 부터 다시 시작)
	2.3 현재 노드가 비어있다면
		이 위치에 삽입

탐색
	0. 현재 노드가 비어있다면, NULL을 반환
	1. 현재 노드의 데이터와 삽입하려는 값을 비교
	2.1 만약 삽입하려는 값이 더 작다면
		왼쪽노드로 이동 (1번 부터 다시 시작)
	2.2 만약 삽입하려는 값이 더 크다면
		오른쪽노드로 이동 (1번 부터 다시 시작)
	2.3 현재 노드가 비어있다면
		이 위치에 삽입

*/

#include <stdio.h>
struct node {
	char data;
	struct node* left;
	struct node* right;

};
typedef struct node NODE, * pNODE;

void preorder(pNODE curr);
void inorder(pNODE curr);
void postorder(pNODE curr);

pNODE get_node(char data);
pNODE insert(pNODE curr, char data);
pNODE search(pNODE curr, char data);
int main() {
	NODE A = { .data = 'A' };
	NODE B = { .data = 'B' };
	NODE C = { .data = 'C' };
	NODE D = { .data = 'D' };
	NODE E = { .data = 'E' };
	NODE F = { .data = 'F' };

	pNODE root = &A;
	root->left = &B;
	root->right = &C;

	B.left = &D;
	B.right = &E;
	C.left = &F;

	root->right->left = &F;

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	root = NULL;
	root = insert(root, 'D');
	root = insert(root, 'B');
	root = insert(root, 'A');
	root = insert(root, 'C');
	root = insert(root, 'E');
	root = insert(root, 'F');

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	pNODE tmp = search(root, 'C');
	if (tmp != NULL) {
		printf("%c\n", tmp->data);
	}
	else {
		printf("탐색 실패!\n");
	}

	tmp = search(root, 'K');
	if (tmp != NULL) {
		printf("%c\n", tmp->data);
	}
	else {
		printf("탐색 실패!\n");
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

}
pNODE search(pNODE curr, char data) {
	if (curr == NULL) {
		return NULL;
	}
	if (curr->data > data) {
		return search(curr->left, data);
	}
	else if (curr->data < data) {
		return search(curr->right, data);
	}
	else if (curr->data == data) {
		return curr;
	}

}
pNODE insert(pNODE curr, char data) {
	//	2.3 현재 노드가 비어있다면
	//	이 위치에 삽입
	if (curr == NULL) {
		pNODE new = get_node(data);
		return new;
	}
	//1. 현재 노드의 데이터와 삽입하려는 값을 비교
	if (curr->data > data) {
		//	2.1 만약 삽입하려는 값이 더 작다면
		//	왼쪽노드로 이동(1번 부터 다시 시작)
		curr->left = insert(curr->left, data);
	}
	if (curr->data < data) {
		//	2.2 만약 삽입하려는 값이 더 크다면
		//	오른쪽노드로 이동(1번 부터 다시 시작)
		curr->right = insert(curr->right, data);
	}

	return curr;
}
pNODE get_node(char data) {
	pNODE new = malloc(sizeof(NODE));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}
void preorder(pNODE curr) {
	//0.탈출조건
	if (curr == NULL) return;
	//1.현재 노드 방문
	printf("%c:", curr->data);
	//2. 왼쪽 노드로 이동
	preorder(curr->left);
	//3. 오른쪽 노드로 이동
	preorder(curr->right);
}

void inorder(pNODE curr) {
	//0.탈출조건
	if (curr == NULL) return;
	//2. 왼쪽 노드로 이동
	inorder(curr->left);
	//1.현재 노드 방문
	printf("%c:", curr->data);
	//3. 오른쪽 노드로 이동
	preorder(curr->right);
}

void postorder(pNODE curr) {
	//0.탈출조건
	if (curr == NULL) return;
	//2. 왼쪽 노드로 이동
	postorder(curr->left);
	//3. 오른쪽 노드로 이동
	postorder(curr->right);
	//1.현재 노드 방문
	printf("%c:", curr->data);
}