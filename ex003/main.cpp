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
    int sum = 0, maxSum = 0;
    for (int i = 0; i < array.size(); ++i) {

        if (sum == 0 && array[i] < 0) continue;

        if (i != 0 && i != array.size() - 1)
            if ((array[i] > 0 && array[i] + array[i-1] > 0) ||
                (array[i] > 0 && array[i] + array[i+1] > 0) ||
                (array[i] < 0 && array[i+1] + array[i] > 0) ||
                (array[i] < 0 && array[i-1] + array[i] > 0)) {
                sum += array[i];
                if (sum > maxSum) maxSum = sum;
            } else
                sum = 0;

        else if (i == 0)
            if (array[1] + array[0]>0) {
                sum += array[i];
                if (sum > maxSum) maxSum = sum;
            }
            else sum = 0;

        else
            if (array[i-1] + array[i]>0) {
                sum += array[i];
                if (sum > maxSum) maxSum = sum;
            }
            else continue;
    }
    cout<<"The max sum = "<<maxSum<<endl;
}

int main() {
    initNumbers(numbers);
    calculate(numbers);
    return 0;
}