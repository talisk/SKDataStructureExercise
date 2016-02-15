#include <iostream>
#include <deque>

using namespace std;

typedef struct BSTreeNode {
    int m_nValue; // value of node
    BSTreeNode *m_pLeft; // left child of node
    BSTreeNode *m_pRight; // right child of node
}BSTreeNode, *pBSTreeNode;

deque<pBSTreeNode> orderedQueue;

void createBSTree(pBSTreeNode &root) {
    int c;
    cin>>c;

    if (c == -1) {
        root = NULL;
        return;
    } else {
        root = (pBSTreeNode)malloc(sizeof(BSTreeNode));
        root->m_nValue = c;
        createBSTree(root->m_pLeft);
        createBSTree(root->m_pRight);
    }
    return;
}

void displayBSTree(pBSTreeNode &root) {
    if (root) {
        cout<<root->m_nValue<<endl;
        displayBSTree(root->m_pLeft);
        displayBSTree(root->m_pRight);
    } else {
        return;
    }
}

void transfer(pBSTreeNode &root) {
    if (root->m_pLeft) {
        transfer(root->m_pLeft);
    }
    orderedQueue.push_back(root);
    if (root->m_pRight) {
        transfer(root->m_pRight);
    } else {
        return;
    }
}

int main() {
    pBSTreeNode root;
    createBSTree(root);
//    displayBSTree(root);
    transfer(root);

    while (!orderedQueue.empty()) {
        cout<<orderedQueue.front()->m_nValue<<((orderedQueue.size()-1)?"=":"");
        orderedQueue.pop_front();
    }

    return 0;
}