//
// Created by 孙恺 on 16/2/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dataArray;

void input(int count) {
    int number;
    cout<<"Input integer number to add data to array,\nand nonnumeric to end."<<endl;
    while (cin>>number) {
        if (dataArray.size() < count) {
            dataArray.push_back(number);
            sort(dataArray.begin(),dataArray.end());
        }
        else {
            if (dataArray[dataArray.size()-1] > number) {
                dataArray[dataArray.size()-1] = number;
                sort(dataArray.begin(),dataArray.end());
            }
        }
    }
}

int main() {
    input(5);
    for (int i = 0; i < dataArray.size(); ++i) {
        cout<<dataArray[i]<<", "<<endl;
    }
    return 0;
}