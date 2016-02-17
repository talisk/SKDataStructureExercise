//
// Created by 孙恺 on 16/2/17.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;

void initNumbers(vector<int> &array) {
    int number;
    cout<<"Input integer number to add data to array,\nand nonnumeric to end."<<endl;
    while (cin>>number) {
        array.push_back(number);
    }
}

void calculate(vector<int> &array) {
    int sum = array[0], maxSum = sum, beginIndex = 0, endIndex = 0, begin = 0, end = 0;
    for (int i = 1; i < array.size(); ++i) {
        if (sum > 0) {
            sum += array[i];
            end = i;
        } else {
            sum = array[i];
            begin= i;
        }
        if (sum > maxSum) {
            maxSum = sum;
            beginIndex = begin;
            endIndex = end;
        }

    }
    cout<<"MaxSum = "<<maxSum<<endl;
    for (int i = beginIndex; i <= endIndex; ++i) {
        cout<<array[i]<<", ";
    }
}

int main() {
    initNumbers(numbers);
    calculate(numbers);
    return 0;
}