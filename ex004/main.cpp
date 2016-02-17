//
// Created by 孙恺 on 16/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> resultArray;

typedef struct BinaryTreeNode {
    int m_nValue; // value of node
    BinaryTreeNode *m_pLeft; // left child of node
    BinaryTreeNode *m_pRight; // right child of node
}BinaryTreeNode, *pBinaryTreeNode;

void createBinaryTree(pBinaryTreeNode &root) {
    int c;
    cin>>c;

    if (c == -1) {
        root = NULL;
        return;
    } else {
        root = (pBinaryTreeNode)malloc(sizeof(BinaryTreeNode));
        root->m_nValue = c;
        createBinaryTree(root->m_pLeft);
        createBinaryTree(root->m_pRight);
    }
    return;
}

void displayBinaryTree(pBinaryTreeNode &root) {
    if (root) {
        cout<<root->m_nValue<<endl;
        displayBinaryTree(root->m_pLeft);
        displayBinaryTree(root->m_pRight);
    } else {
        return;
    }
}

int find(pBinaryTreeNode &root, int number, int depth) {
    int remaining;
    if (root) {
        remaining = number - root->m_nValue;
        if (remaining > 0) {
            if (find(root->m_pLeft, remaining, depth+1) == 1) {
                resultArray.push_back(root->m_nValue);
                if (depth == 1) resultArray.push_back(-1);
            }
            if (find(root->m_pRight, remaining, depth+1) == 1) {
                resultArray.push_back(root->m_nValue);
                if (depth == 1) resultArray.push_back(-1);
            }
        } else if (remaining < 0) {
            return 0;
        } else {
            resultArray.push_back(root->m_nValue);
            if (depth == 1) resultArray.push_back(-1);
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    pBinaryTreeNode root;
    createBinaryTree(root);
//    displayBinaryTree(root);

    find(root, 22, 0);

    for (int i = (int)resultArray.size()-2; i >= 0; --i) {
        if (resultArray[i] == -1) {
            cout<<endl<<"10";
            continue;
        }
        cout<<","<<resultArray[i];
    }
    return 0;
}