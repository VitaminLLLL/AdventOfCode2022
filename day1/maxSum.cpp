#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void) 
{
	ifstream input;
	input.open("input.txt", ios::in);
	if(!input.is_open()) {
		cerr<<"input cannot open."<<endl;
	}
	int max = 0;
	int sum = 0;
	string value;
	while(getline(input, value)) {
		if(value.empty()) {
			max = (sum > max) ? sum : max;
			sum = 0;
		} else {
			sum += stoi(value);
		}
	}
	//in case last line wasn't empty
	max = (sum > max) ? sum : max;
	cout << "Maximum value: " << max << endl;
	return 0;
}