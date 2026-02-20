#include"BinaryTree.h"

int main() 
{
	// 트리 만들기
	BTree<char> tree;
	BTree<char>::Node* A = tree.CreateNode('A');
	BTree<char>::Node* B = tree.CreateNode('B');
	BTree<char>::Node* C = tree.CreateNode('C');
	BTree<char>::Node* D = tree.CreateNode('D');
	BTree<char>::Node* E = tree.CreateNode('E');
	BTree<char>::Node* F = tree.CreateNode('F');
	BTree<char>::Node* G = tree.CreateNode('G');

	tree.Root(A);

	A->Left = B;

	B->Left = C;
	B->Right = D;

	A->Right = E;

	E->Left = F;
	E->Right = G;

	// 순회별 출력
	cout << "-- PreOrder -- " << endl;
	tree.PreOrder(A);
	cout << endl << endl;

	cout << "-- InOrder -- " << endl;
	tree.InOrder(A);
	cout << endl << endl;

	cout << "-- PostOrder -- " << endl;
	tree.PostOrder(A);
	cout << endl << endl;

	return 0;

}