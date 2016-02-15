//
// Created by 孙恺 on 16/2/15.
//

#include "stack.h"
#include <cstdlib>

int stack::min() {
    return this->top->minValue;
}

void stack::push(int value) {
    pLNode node = (pLNode)malloc(sizeof(LNode));

    if (!this->size)
        node->minValue = value;
    else
        node->minValue = (value < this->top->minValue) ? value : this->top->minValue;
    node->next = this->top;
    node->value = value;
    this->top = node;
}

void stack::pop() {
    pLNode temp = this->top;
    this->top = this->top->next;
    this->size--;
    free(temp);
}

stack::stack() {
    this->top = NULL;
    this->size = 0;
    this->minNode->next = NULL;
}
