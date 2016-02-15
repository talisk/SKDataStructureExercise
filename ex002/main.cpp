#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack stack1 = stack();

    stack1.push(5);
    cout<<stack1.min();
    stack1.push(2);
    cout<<stack1.min();
    stack1.pop();
    cout<<stack1.min();
    stack1.push(3);
    cout<<stack1.min();
    stack1.pop();
    cout<<stack1.min();
    stack1.push(6);
    cout<<stack1.min();
    stack1.pop();
    cout<<stack1.min();
    stack1.push(1);
    cout<<stack1.min();

    return 0;
}