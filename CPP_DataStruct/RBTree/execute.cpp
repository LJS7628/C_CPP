#include <iostream>
#include "AVLTree.h"
#include "RBTree.h"

/// <summary>
/// AVL 트리란 자가 균형 이진 탐색 트리로, 모든 노드에서 왼쪽 오른쪽 서브 트리 높이 차이가
/// 최대 1을 넘지 않도록 유지하는 트리이다. 삽입/삭제시 왼쪽/오른쪽 회전을 통해 균형을 맞춘다.
///  RB 트리는 AVL 트리의 한종류로 노드마다 빨강,검정 색상을 가지고 규칙에 따라 균형을 유지한다.
/// 핵심 규칙은 - 루트와 모든 리프 노드는 검정색이며, 빨강 노드의 자식은 무조건 검정이다. 루프에서 리프까지 검정노드의 수가 동일해야 한다.
/// </summary>


int main()
{
    AVLTree tree;
    std::vector<int> values = { 10, 20, 30, 40, 50, 25 };
    for (int value : values)
    {
        tree.insert(value);
    }
    std::vector<int> sortedValues;
    tree.inorderSort(sortedValues);
    for (int value : sortedValues)
    {
        std::cout << value << " ";
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    RedBlackTree rbt;

    // 데이터 삽입
    std::vector<int> data = { 20, 10, 30, 5, 15, 25, 35 };

    std::cout << "\n=== 레드-블랙 트리 삽입 과정 ===" << std::endl;

    for (int value : data)
    {
        std::cout << "\n 삽입: " << value << std::endl;
        rbt.Insert(value);

        // 기본 출력 (R/B 표기)
        std::cout << "출력:" << std::endl;
        rbt.DisplayColorTree();

        std::cout << "------------------------" << std::endl;
    }

    // 정렬된 결과 출력
    std::cout << "\n=== 정렬된 결과 (중위 순회) ===" << std::endl;
    rbt.InOrderTraversal(rbt.getRoot());


    return 0;
}



