#pragma once
#include <iostream>
#include <vector>

enum class eColor
{
    Red,
    Black,
    End,
};

struct Node
{
    int Data;
    eColor Color;

    Node* Left;
    Node* Right;
    Node* Parent;

    Node(int data)
        : Data(data)
        , Color(eColor::Red)
        , Left(nullptr)
        , Right(nullptr)
        , Parent(nullptr)
    {
    }
};

class RedBlackTree
{
public:
    RedBlackTree()
    {
        NIL = new Node(0);
        NIL->Color = eColor::Black;
        mRoot = NIL;
    }

    void LeftRotate(Node* x)
    {
        Node* y = x->Right;  // y는 x의 오른쪽 자식

        // 1단계: y의 왼쪽 서브트리를 x의 오른쪽으로 이동
        x->Right = y->Left;
        if (y->Left != NIL)
        {
            y->Left->Parent = x;
        }

        // 2단계: y의 부모를 x의 부모로 설정
        y->Parent = x->Parent;
        if (x->Parent == NIL)
        {
            mRoot = y;  // x가 루트였다면 y가 새 루트
        }
        else if (x == x->Parent->Left)
        {
            x->Parent->Left = y;
        }
        else
        {
            x->Parent->Right = y;
        }

        // 3단계: x를 y의 왼쪽 자식으로 설정
        y->Left = x;
        x->Parent = y;
    }

    void RightRotate(Node* y)
    {
        Node* x = y->Left;   // x는 y의 왼쪽 자식

        // 1단계: x의 오른쪽 서브트리를 y의 왼쪽으로 이동
        y->Left = x->Right;
        if (x->Right != NIL)
        {
            x->Right->Parent = y;
        }

        // 2단계: x의 부모를 y의 부모로 설정
        x->Parent = y->Parent;
        if (y->Parent == NIL)
        {
            mRoot = x;  // y가 루트였다면 x가 새 루트
        }
        else if (y == y->Parent->Left)
        {
            y->Parent->Left = x;
        }
        else
        {
            y->Parent->Right = x;
        }

        // 3단계: y를 x의 오른쪽 자식으로 설정
        x->Right = y;
        y->Parent = x;
    }

    void Insert(int data)
    {
        Node* newNode = new Node(data);
        newNode->Left = NIL;
        newNode->Right = NIL;

        Node* y = NIL;
        Node* x = mRoot;

        // 새로운 노드를 삽입할 위치를 찾음
        // 재귀 함수로 대체 가능
        while (x != NIL)
        {
            y = x;
            if (newNode->Data < x->Data)
            {
                x = x->Left;
            }
            else
            {
                x = x->Right;
            }
        }

        // 부모노드 설정
        newNode->Parent = y;

        // 트리가 비어있다면 새 노드가 루트
        if (y == NIL)
        {
            mRoot = newNode;
        }
        else if (newNode->Data < y->Data)
        {
            y->Left = newNode;
        }
        else
        {
            y->Right = newNode;
        }

        newNode->Color = eColor::Red;  // 새 노드는 빨간색으로 삽입
        InsertFixup(newNode);          // 삽입 후 균형 맞추기
    }

    /* 모든 노드는 빨강(RED) 또는 검정(BLACK)이다.
       루트 노드는 항상 검정(BLACK)이다.
       모든 리프 노드(NIL)는 검정(BLACK)이다.
       빨강(RED) 노드의 자식은 반드시 검정(BLACK)이다.
       (연속으로 빨강 노드가 올 수 없다)
       루트에서 모든 리프까지의 경로에서
       검정 노드의 개수는 동일해야 한다.*/

    void InsertFixup(Node* z)
    {
        while (z->Parent->Color == eColor::Red)
        {

            if (z->Parent == z->Parent->Parent->Left)
            {
                Node* y = z->Parent->Parent->Right;  // 삼촌 노드
                if (y->Color == eColor::Red)  // Case 1: 삼촌이 빨간색
                {
                    z->Parent->Color = eColor::Black; //recoloring
                    y->Color = eColor::Black;
                    z->Parent->Parent->Color = eColor::Red;
                    z = z->Parent->Parent;
                }
                else
                {
                    // restruturing
                    if (z == z->Parent->Right)  // Case 2: 삼촌이 검은색이고, z가 오른쪽 자식
                    {
                        z = z->Parent;
                        LeftRotate(z);
                    }
                    // Case 3: 삼촌이 검은색이고, z가 왼쪽 자식
                    z->Parent->Color = eColor::Black;
                    z->Parent->Parent->Color = eColor::Red;
                    RightRotate(z->Parent->Parent);
                }
            }
            else
            {
                Node* y = z->Parent->Parent->Left;  // 삼촌 노드
                if (y->Color == eColor::Red)  // Case 1: 삼촌이 빨간색
                {
                    // recoloring
                    z->Parent->Color = eColor::Black;
                    y->Color = eColor::Black;
                    z->Parent->Parent->Color = eColor::Red;
                    z = z->Parent->Parent;
                }
                else
                {
                    //restruturing
                    if (z == z->Parent->Left)  // Case 2: 삼촌이 검은색이고, z가 왼쪽 자식
                    {
                        z = z->Parent;
                        RightRotate(z);
                    }
                    // Case 3: 삼촌이 검은색이고, z가 오른쪽 자식
                    z->Parent->Color = eColor::Black;
                    z->Parent->Parent->Color = eColor::Red;
                    LeftRotate(z->Parent->Parent);
                }
            }
        }
        mRoot->Color = eColor::Black;  // 루트는 항상 검은색
    }

    Node* Search(int data)
    {
        Node* current = mRoot;
        while (current != NIL && data != current->Data)
        {
            if (data < current->Data)
            {
                current = current->Left;
            }
            else
            {
                current = current->Right;
            }
        }
        return current;  // 찾으면 해당 노드, 못 찾으면 NIL 반환
    }

    void InOrderTraversal(Node* node)
    {
        if (node != NIL)
        {
            InOrderTraversal(node->Left);
            std::cout << node->Data << " ";
            InOrderTraversal(node->Right);
        }
    }

    void PrintColorTree(Node* node, int depth = 0)
    {
        // ANSI 색상 코드 정의
        const std::string RED_COLOR = "\033[31m";      // 빨강
        const std::string BLACK_COLOR = "\033[30m";    // 검정 (기본)
        const std::string RESET_COLOR = "\033[0m";     // 색상 리셋
        const std::string BOLD = "\033[1m";            // 굵게

        if (node != NIL)
        {
            PrintColorTree(node->Right, depth + 1);

            for (int i = 0; i < depth; ++i) std::cout << "   ";
            std::cout << (node->Color == eColor::Red ? RED_COLOR : BLACK_COLOR)
                << BOLD << node->Data << "(" << (node->Color == eColor::Red ? "R" : "B") << ")"
                << RESET_COLOR << "\n";

            PrintColorTree(node->Left, depth + 1);
        }
    }

    void DisplayColorTree()
    {
        PrintColorTree(mRoot);
    }

    Node* getRoot() { return mRoot; }

private:
    Node* mRoot;
    Node* NIL;  // 센티널 노드 (모든 리프를 대체)
};


