/*������ ���������.�����������,��� ������� ������������������ ��� ����� ����� (���� p-q ���������������� ��� � ������� � q.)
���� � ������� � q,a q c r,�� ��������������,��� � ������� � r ������ ������� � ��������� ������ ��� ����������� ������ ��� �� ������:
����� ��������� �������� ��������� ���� p-q ��� ������ ��������� ��� ���� ������ � ��� ������,���� �� ���������� ��� �� 
�������,��� p-q �������.*/
/*�����:������� �.�*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int p;
	int q;
} Pair;

const int max_n = 10;

vector<Pair> vec;
vector< vector <bool> > matr(max_n+1,vector<bool>(max_n+1));
/*��������� ��� ����������*/
void MakeRelation(int cur_top, int new_top) {
	if (matr[cur_top][new_top]) return;
	matr[cur_top][new_top] = true;
	for (int i = 0; i < max_n; ++i) {
		if (matr[i][cur_top]) MakeRelation(i, new_top);
	}
}
/*���������� ���*/
void AddPair(Pair pair) {
	int p = pair.p, q = pair.q;
	if (matr[p][q] == true)
		return;
	MakeRelation(p, q);
	vec.push_back(pair);
}
/*���������� ���*/
Pair ReadPair() {
	Pair pair;
	cin >> pair.p >> pair.q;
	return pair;
}
/*���������� ���,������� ����� ���������� ������������*/
int main() {
	cout << "How many pairs do you want?" << endl;
	
	int n;
	do {
		cin >> n;
	}
	/*���� ����� ���*/
	while (n <= 0 || n > max_n);
	cout << "Enter pairs" << endl;
	for (int i = 0; i < n; ++i) {
		Pair p;
		p = ReadPair();
		AddPair(p);
	}
	/*�����*/
	cout << "Result:" << endl;
	for (auto &pair : vec) {
		cout << pair.p << " " << pair.q << endl;
	}
	system("pause");
	return 0;
}