#ifndef NUMBER_OF_1_BETWEEN_1_AND_N_H
#define NUMBER_OF_1_BETWEEN_1_AND_N_H
#include <iostream>
#include <cmath>
using namespace std;
int nLength(int n) {
	int count = 0;
	int temp = n;
	while (temp != 0) {
		temp = temp / 10;
		count++;
	}
	return count;
}
int nThreshold(int n) {
	return pow(10, n - 1) * 2 - 1;
}

int NumberOf1Between1AndN(int n) {
	int length = nLength(n);
	int threshold = nThreshold(length);
	cout<<length<<" "<<threshold<<endl;
	int result = 0;
	if (n >= threshold) {
		for (int index = 0; index != length; ++index) {
			result += pow(10, index);
		}
	}
	else {
		for (int index = 0; index != (length - 1); ++index) {
			cout<<index<<" "<<(length - 1)<<endl;
			result += pow(10, index);
			cout<<result<<endl;
		}
		result += (n - pow(10, length - 1) + 1);
	}
	return result;
}
#endif
