#include "BTree.h"

typedef BTree<int> Tree;

int main()
{
	// 루트 생성 및 설정
	Tree tree;
	Tree::Node* root = Tree::CreateNode(12);
	tree.Root(root);

	// 트리 만들기
	tree.Insert(&root, Tree::CreateNode(22));
	tree.Insert(&root, Tree::CreateNode(99));
	tree.Insert(&root, Tree::CreateNode(42));
	tree.Insert(&root, Tree::CreateNode(17));
	tree.Insert(&root, Tree::CreateNode(3));
	tree.Insert(&root, Tree::CreateNode(98));
	tree.Insert(&root, Tree::CreateNode(34));
	tree.Insert(&root, Tree::CreateNode(75));
	tree.Insert(&root, Tree::CreateNode(32));
	tree.Insert(&root, Tree::CreateNode(1));

	// 중위 순회로 확인
	tree.InOrder(root, 0);

	// 탐색
	int depth = 0;
	Tree::Node* node = tree.Search(root, 98, depth);
	cout << endl << endl << "찾음 : " << node->Data << ", " << depth << "번에 찾음" << endl;

	// 삭제
	node = tree.Remove(root, NULL, 42);
	cout << "삭제할 노드 : " << node->Data << endl;
	Tree::DestroyNode(&node);

	// 재확인
	tree.InOrder(root, 0);
	cout << endl << endl;

	return 0;
}