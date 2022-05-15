#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream bit("Binary.txt", ios::in | ios::out | ios::binary);
	int b[100] = {};
	for (int i = 0; i < 6; i++) {
		bit.read((char*)&b[i], sizeof(int));
	}
	if (!bit) {
		cerr << "Open Error" << endl;
	}
	else {
		for (int i = 0; i < 25; i++) {
			bit.read((char*)&b[i], sizeof(int));
			cout << bit.tellg() << endl;
		}
	}
	return 0;
}