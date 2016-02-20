//
// Created by 孙恺 on 16/2/20.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct LNode {
    int m_nValue;
    struct LNode *next;
}LNode, *pLNode;

#define LLCOUNT0 3
#define LLCOUNT1 6
#define LLPBCOUNT 4

vector<vector<int>> fakeValue;

void createExampleLinkList(pLNode head, int type, pLNode publicLL) {
    pLNode point = head;

    for (int i = 0; i < fakeValue[type].size(); ++i) {
        pLNode node = (pLNode)malloc(sizeof(LNode));
        node->m_nValue = fakeValue[type][i];
        point->next = node;
        point = node;
    }
    point->next = NULL;
    if (publicLL) {
        point->next = publicLL->next;
    }
}

void initFakeValue() {
    vector<int> vec;
    for (int i = 0; i < LLCOUNT0; ++i) {
        vec.push_back(0);
    }
    fakeValue.push_back(vec);
    vec.clear();

    for (int i = 0; i < LLCOUNT1; ++i) {
        vec.push_back(1);
    }
    fakeValue.push_back(vec);
    vec.clear();

    for (int i = 0; i < LLPBCOUNT; ++i) {
        vec.push_back(2);
    }
    fakeValue.push_back(vec);
}

void displayLinkList(pLNode &head) {
    pLNode point = head->next;
    while (point) {
        cout<<point->m_nValue<<",";
        point = point->next;
    }
    cout<<endl;
}

pLNode findPublicNode(pLNode head0, pLNode head1) {

    for (pLNode point0 = head0->next; point0; point0 = point0->next) {
        for (pLNode point1 = head1->next; point1; point1 = point1->next) {
            if (point0 == point1) {
                return point0;
            }
        }
    }
    return NULL;
}

int main() {
    initFakeValue();    // 初始化样例数据

    // 三个链表的头结点
    pLNode LL0 = (pLNode)malloc(sizeof(LNode)),
           LL1 = (pLNode)malloc(sizeof(LNode)),
           PUBLL = (pLNode)malloc(sizeof(LNode));

    createExampleLinkList(PUBLL, 2, NULL);  // 创建两个链表的公共部分
    createExampleLinkList(LL0, 0, PUBLL);   // 创建LL0, 并在其后追加公共链表
    createExampleLinkList(LL1, 1, PUBLL);   // 创建LL1, 并在其后追加公共链表

    cout<<"Example LinkList:"<<endl;
    displayLinkList(LL0);
    displayLinkList(LL1);
//    displayLinkList(PUBLL);
    cout<<endl;

    if (pLNode result = findPublicNode(LL0, LL1)) {
        cout<<"- Found intersection:\n- Address - "<<result<<"\n- Value - "<<result->m_nValue<<endl;
    }

    return 0;
}