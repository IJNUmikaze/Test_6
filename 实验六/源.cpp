#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
bool fx(int n) {//�ж��Ƿ�Ϊ����
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ofstream outfile("ASCII.txt", ios::out | ios::_Nocreate | ios::trunc);//�������������ASCII.txt�ļ�
	if (!outfile) {
		cerr << "Open Error" << endl;
	}
	outfile << "������ı�:" << endl;
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
	cout << "�Ƿ�����ı�:(Y��Ϊ�ǣ�N��Ϊ��)";
	char c;
	cin >> c;
	int b[100] = {};
	mark = 0;
	int i = 0;
	if (c == 'y' || c == 'Y'){
		ifstream infile("ASCII.txt", ios::in | ios::_Nocreate);
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
	fstream bit("Binary.txt", ios::out | ios::in | ios::_Nocreate);
	if (!bit) {
		cerr << "Open Error" << endl;
	}
	for (int j = 0; j < i ; j++) {
		bit.write((char*)&b[j], sizeof(int));
	}
	int m[100] = {};
	//bit.clear();
	cout << bit.tellg() << endl;
	bit.seekp(0, ios::end);
	cout << bit.tellg() << endl;
	bit.peek();
	cout << bit.tellg() << endl;
	for (int j = 0; j < i; j++) {
		if (bit.eof()) {
			break;
		}
		bit.read((char*)&m[j], sizeof(int));
		cout << bit.tellg() << endl;
	}
	mark = 0;
	for (int j = 0; j < i; j++) {
		mark++;
		cout << setw(6) << m[j];
		if (mark % 10 == 0) {
			cout << endl;
		}
	}
	if (mark % 10 != 0) {
		cout << endl;
	}
	bit.clear();
	bit.close();
	return 0;
}