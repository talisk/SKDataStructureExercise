//
// Created by 孙恺 on 16/2/15.
//

#ifndef EX002_STACK_H
#define EX002_STACK_H

typedef struct LNode {
    int value;
    struct LNode *next;
    int minValue;
}LNode, *pLNode;

class stack {
public:

    pLNode top;
    int size;

    stack();
    void pop();
    void push(int value);
    int min();

private:
    pLNode minNode;
};


#endif //EX002_STACK_H
