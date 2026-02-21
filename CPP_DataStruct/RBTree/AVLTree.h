#pragma once
#include <vector>
#include <algorithm>

struct AVLNode
{
    int data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    AVLNode* root = nullptr;

    int getHeight(AVLNode* node)
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(AVLNode* node)
    {
        if (node)
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    AVLNode* rotateRight(AVLNode* y)
    {
        AVLNode* x = y->left;
        y->left = x->right;
        x->right = y;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x)
    {
        AVLNode* y = x->right;
        x->right = y->left;
        y->left = x;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insert(AVLNode* node, int value)
    {
        // 1. 일반적인 BST 삽입
        if (!node) return new AVLNode(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);

        // 2. 높이 업데이트
        updateHeight(node);

        // 3. 균형 체크 및 회전
        int balance = getBalanceFactor(node);

        // LL Case
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // RR Case
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // LR Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

public:
    void insert(int value)
    {
        root = insert(root, value);
    }

    // 중위 순회로 정렬된 결과 출력
    void inorderSort(std::vector<int>& result)
    {
        inorder(root, result);
    }

    void inorder(AVLNode* node, std::vector<int>& result)
    {
        if (node)
        {
            inorder(node->left, result);
            result.push_back(node->data);
            inorder(node->right, result);
        }
    }
};