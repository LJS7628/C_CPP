/*
이진탐색트리
	삭제
		1. 리프노드를 삭제할때
		2. 자식이 하나인 노드를 삭제할때
		3. 자식이 두개인 노드를 삭제할때

	리프노드를 삭제할때
		삭제할 노드의 부모노드를 찾음
		부모노드가 삭제할 노드 대신에
		NULL를 가르키도록 함

	자식이 하나인 노드를 삭제할때
		삭제할 노드의 부모노드를 찾음
		내가 왼쪽자식이 있다면
			부모노드가 삭제할 노드 대신에
			왼쪽 자식을 가르킴
		내가 오른쪽 자식이 있다면
			부모노드가 삭제할 노드 대신에
			오른쪽 자식을 가르킴

	자식이 하나인 경우와 리프노드인 경우는 동일
		왼쪽 자식이 없을때, 리프노드라면 오른쪽 자식이 없음
		부모가 오른쪽 자식을 가르켜도, 아무것도 못 가르키는게 동일
		따라서 같은 조건으로 수행 가능

삭제 알고리즘
	자식노드가 1개거나 없는 경우
		pNODE curr		: 현재 노드
		int data		: 삭제할 노드가 가진 값

	다음 노드를 물어보면서, 만약 다음노드가 삭제할 노드라면
		해당 노드 대신에 왼쪽/오른쪽 자식 이라 대답
	다음 노드가 삭제할 노드가 아니라면
		다음노드를 그대로 대답

	1. 현재 노드의 값과 data를 비교해서

	2.1 data가 더 작다면
		왼쪽 노드로 재귀하며 이동
		1 번 부터 반복

	2.2 data가 더 크다면
		오른쪽 노드로 재귀하며 이동
		1번 부터 반복
	2.3 data와 같아면
		1) 왼쪽 자식이 없다면
			오른쪽 자식을 부모가 curr대신 사용하도록
		2)	오른쪽 자식이 없다면
			왼쪽 자식을 부모가 curr대신 사용하도록
		3) 다 아니라면(즉, 양쪽 자식이 다 있다면)
			미구현 이므로 printf로 미구현임을 출력

	자식노드가 2개인 경우
		1) 해당 노드의 오른쪽 자손 중 가장 작은 값을 탐색
		i)		오른쪽으로 한번 전진
		ii)		왼쪽 자식이 없을때 까지 왼쪽으로 전진
		iii)	왼쪽 자식이 없는 노드
				즉, 오른쪽 자손중 가장 왼쪽에 있는 노드

		2) 해당 노드의 값을 1)에서 찾은 값으로 변경
		3) 1)에서 찾은 노드를 삭제(delete 로 삭제)
			시작이 root 나 curr부터 시작하면
			2)에서 값을 1)과 똑같이 바꿨으므로
			현재노드가 삭제됨
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
pNODE delete(pNODE curr, char data);
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

	root = NULL;
	root = insert(root, 'J');
	root = insert(root, 'B');
	root = insert(root, 'A');
	root = insert(root, 'D');
	root = insert(root, 'C');
	root = insert(root, 'N');
	root = insert(root, 'L');
	root = insert(root, 'M');
	root = insert(root, 'P');
	root = insert(root, 'O');
	root = insert(root, 'S');
	root = insert(root, 'R');
	root = insert(root, 'Q');
	root = insert(root, 'T');

	preorder(root); //전위 : J:B:A:D:C:N:L:M:P:O:S:R:Q:T
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");

	printf("\n========================================\n");

	inorder(root);
	printf("\n");
	root = delete(root, 'A');
	inorder(root);
	printf("\n");
	root = delete(root, 'D');
	inorder(root);
	printf("\n");
	root = delete(root, 'L');
	inorder(root);
	printf("\n");
	root = delete(root, 'P');
	inorder(root);
	printf("\n");
	root = delete(root, 'J');
	inorder(root);
	printf("\n");

}
pNODE delete(pNODE curr, char data) {
	if (curr == NULL) return;
	if (curr->data > data) {
		curr->left = delete(curr->left, data);
		return curr;
	}
	else if (curr->data < data) {
		curr->right = delete(curr->right, data);
		return curr;
	}
	else if (curr->data == data) {
		if (curr->left == NULL) {
			curr = curr->right;
			return curr;
		}
		else if (curr->right == NULL) {
			curr = curr->left;
			return curr;
		}
		else {
			pNODE min = curr->right;  // curr=P  min=curr->right = S
			while (min->left != NULL) {
				min = min->left;
			} //min = Q
			curr->data = min->data;  // curr = Q(원래 P인것)  min = Q(진짜 Q)
			curr->right = delete(curr->right, min->data);
			free(min);
			return curr;
		}
	}
	return curr;
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