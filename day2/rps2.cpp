#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int result(int opponent, char my) {
	switch(my) {
	case 'X':
		switch (opponent){
		case 1:
			return 3;
		case 2:
			return 1;
		case 3:
			return 2;
		}
	case 'Y':
		switch (opponent){
		case 1:
			return 1 + 3;
		case 2:
			return 2 + 3;
		case 3:
			return 3 + 3;
		}
	case 'Z':
		switch (opponent){
		case 1:
			return 2 + 6;
		case 2:
			return 3 + 6;
		case 3:
			return 1 + 6;
		}
	}
	return 0;
}

int main(void) {
	ifstream input;
	input.open("input.txt", ios::in);
	if(!input.is_open()) {
		cerr<<"input cannot open."<<endl;
		return -1;
	}
	string line;
	int points = 0;
	map<char, int> map = {
	    { 'A', 1 },
	    { 'B', 2 },
	    { 'C', 3 }
	};
	while(getline(input, line) && !line.empty()) {
		istringstream iss(line);
    	char opponent, my;
    	if (!(iss >> opponent >> my)) { 
    		cerr<<"input cannot open."<<endl;
			return -1;
		}
		//cout << my<<endl;
		points += result(map[opponent], my);
		//cout<<points<<endl;
	}
	cout << "Total points: " << points << endl;
	return 0;
}
