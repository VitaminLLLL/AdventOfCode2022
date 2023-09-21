#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define TOP (3)

void updateTop(int* top, int sum) {
	static int times = 0;
	if(times < TOP) {
		top[times] = sum;
		times++;
		return;
	}
	// find minimum to update
	int minIndex = 0;
	for(int i = 1; i < TOP; i++) {
		if(top[minIndex] > top[i]) {
			minIndex = i;
		}
	}
	top[minIndex] = (top[minIndex] < sum) ? sum : top[minIndex];
	return;
}

int main(void) 
{
	ifstream input;
	input.open("input.txt", ios::in);
	if(!input.is_open()) {
		cerr<<"input cannot open."<<endl;
	}
	int top[TOP];
	for(int i = 0; i < TOP; i++) {
		top[i] = 0;
	}
	int sum = 0;
	string value;
	while(getline(input, value)) {
		if(value.empty()) {
			updateTop(top, sum);
			sum = 0;
		} else {
			sum += stoi(value);
		}
	}
	//in case last line wasn't empty
	int topSum = 0;
	for(int i = 0; i < TOP; i++) {
		topSum += top[i];
	}
	cout << "Maximum top " << TOP <<" value sum: " << topSum << endl;
	return 0;
}