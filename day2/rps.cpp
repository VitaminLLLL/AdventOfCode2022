#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

int result(int opponent, int my) {
	switch(opponent) {
	case 1:
		switch (my){
		case 1:
			return 3;
		case 2:
			return 6;
		case 3:
			return 0;
		}
	case 2:
		switch (my){
		case 1:
			return 0;
		case 2:
			return 3;
		case 3:
			return 6;
		}
	case 3:
		switch (my){
		case 1:
			return 6;
		case 2:
			return 0;
		case 3:
			return 3;
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
	map<char, int> my_map = {
	    { 'X', 1 },
	    { 'Y', 2 },
	    { 'Z', 3 }
	};
	map<char, int> opponent_map = {
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
		points += my_map[my] + result(opponent_map[opponent], my_map[my]);
		//cout<<points<<endl;
	}
	cout << "Total points: " << points << endl;
	return 0;
}
