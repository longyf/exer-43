#ifndef NUMBER_OF_1_BETWEEN_1_AND_N_H
#define NUMBER_OF_1_BETWEEN_1_AND_N_H
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
vector<int> convert(int n) {
	//change the number to a vector
	int temp = 0;
	stack<int> stack1;
	while (n != 0) {
		temp = n;
		n /= 10;
		stack1.push(temp - n * 10);
	}
	vector<int> v1;
	while (!stack1.empty()) {
		v1.push_back(stack1.top());
		stack1.pop();
	}
	return v1;
}

int convertBack(vector<int> &v1, int begin, int end) {
	//change vector to a number.
	int sum = 0;
	int weight = 1;
	for (int i = end; i != begin - 1; i--) {
		sum += (v1[i] * weight);
		weight *= 10;
	}
	return sum;
}

//Debuge
void print(const vector<int> &v1) {
	//print the vector
	for (auto iter = v1.begin(); iter != v1.end(); iter++) {
		cout<<*iter;
	}
	cout<<endl;
}

int obtainNumber(vector<int> &v1, int begin, int end) {
	if (end == begin && v1[begin] == 0) return 0;
	if (end == begin && v1[begin] != 0) return 1;
	int number = convertBack(v1, begin, end);

	//Highest digit is 1.
	int numHighest = 0;
	if (v1[begin] > 1) {
		numHighest = pow(10, end - begin);
	}
	else if (v1[begin] == 1){
		//v1[begin] == 0, can not excute this sentence.
		//The highest digit is not 1 in this case.
		numHighest = number - pow(10, end - begin) + 1;
	}
	//Other digits are 1.
	int numOther = v1[begin] * (end - begin) * pow(10, end - begin - 1);
	//Remove the highest digit.
	int numNext = obtainNumber(v1, begin + 1, end);

	return numHighest + numOther + numNext;
}

int NumberOf1Between1AndN(int n) {
	if (n <= 0) return 0;
	vector<int> v1 = convert(n);
	int begin = 0;
	int end = v1.size() - 1;
	return obtainNumber(v1, begin, end);
}
#endif
