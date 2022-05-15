#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
bool fx(int n) {//判断是否为质数
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ofstream outfile("ASCII.txt", ios::out | ios::_Nocreate | ios::trunc);
	if (!outfile) {
		cerr << "Open Error" << endl;
	}
	outfile << "输出到文本:" << endl;
	int mark = 0;
	for (int i = 2; i <= 100; i++) {
		if (fx(i)) {
			mark++;
			outfile.setf(ios::left);
			outfile << setw(6) << i;
			if (mark % 10 == 0) {
				outfile << endl;
			}
		}
	}
	outfile.close();
	char c;
	c = 'y';
	int b[100] = {};
	mark = 0;
	int i = 0;
	if (c == 'y' || c == 'Y') {
		ifstream infile("ASCII.txt", ios::in);
		if (!infile) {
			cerr << "Open Error" << endl;
		}
		char c;
		while (infile.get(c)) {
			if (c == '\n') {
				break;
			}
		}
		while (infile >> b[i]) {
			mark++;
			cout.setf(ios::left);
			cout << setw(6) << b[i];
			if (mark % 10 == 0) {
				cout << endl;
			}
			i++;
		}
		if (mark % 10 != 0) {
			cout << endl;
		}
		infile.clear();
		infile.close();
	}
	fstream bit("Binary.txt", ios::out | ios::in|ios::binary);
	if (!bit) {
		cerr << "Open Error" << endl;
	}
	/*for (int j = 0; j < i; j++) {
		bit.write((char*)&b[j], sizeof(int));
	}*/
	/*int o[4] = {};
	for (int i = 0; i < 6; i++) {
		o[i] = 7 * i;
	}
	for (int i = 0; i < 6; i++) {
		bit.write((char*)&o[i], sizeof(int));
	}*/
	int p = 100;
	bit.write((char*)&p, sizeof(int));
	p = 105;
	bit.write((char*)&p, sizeof(int));
	p = 106;
	bit.write((char*)&p, sizeof(int));
	bit.seekp(0, ios::end);
	cout << bit.tellg() << endl;
	int o = 86;
	bit.write((char*)&o, sizeof(int));
	int m[100] = {};
	for (int i = 0; i < 100; i++) {
		m[i] = -1;
	}
	for (int j = 0; j < 10; j++) {
		if (bit.eof()) {
			break;
		}
		cout << bit.tellg() << endl;
		bit.read((char*)&m[j], sizeof(int));
		cout << bit.tellg() << endl;
	}
	bit.clear();
	bit.flush();
	cout << bit.tellg() << endl;
	bit.flush();
	//bit.seekp(0, ios::cur);
	cout << bit.tellg() << endl;
	//char ch;
	//bit.get(ch);
	cout << bit.tellg() << endl;
	for (int j = 0; j < i+2; j++) {
		if (bit.eof()) {
			break;
		}
		bit.read((char*)&m[j], sizeof(int));
		cout << bit.tellg() << endl;
	}
	bit.clear();
	bit.close();
	return 0;
}