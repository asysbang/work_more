#include "module/config.h"
#include  <fstream>
#include  <iostream>
using namespace std;

int loadDataFromFile() {
	ifstream fin("/usr/lib/work-more/cfg/list.txt");
	int i = 0;
	string str;
	while (getline(fin, str)) {
		if (i >= 50) {
			break;
		}
		cout << "===" << str << endl;
	}
	return 0;
}

int loadListData(char** list) {
	ifstream fin("/usr/lib/work-more/cfg/list.txt");
	int i = 0;
	string str;
	while (getline(fin, str)) {
		if (i >= 50) {
			break;
		}
		int len = str.length();
		list[i] = (char *) malloc((len + 1) * sizeof(char));
		str.copy(list[i], len, 0);
		i++;
	}
	return i;
}

