//
// Created by 孙恺 on 16/2/20.
//

#include <iostream>

using namespace std;

#ifndef COUNT
#define COUNT 10
#endif

int numbers[COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int countI(int number[], int i) {
    int k = 0;
    for (int j = 0; j < COUNT; ++j)
        (number[j] == i)?(k++):(k);
    return k;
}

int adjust(int number[]) {
    int modifyFlag = 0;
    for (int i = 0; i < COUNT; ++i) {
        if (number[i] != countI(number, i)) modifyFlag = 1;
        number[i] = countI(number, i);
    }
    return modifyFlag;
}

int main(int argc, char const *argv[]) {

    while (adjust(numbers)) {
        for (int j = 0; j < COUNT; ++j) {
            cout << numbers[j] << ",";
        }
        cout << endl;
    }

    return 0;
}