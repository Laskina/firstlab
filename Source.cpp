/*Задача связности.Предположим,что имеется последовательность пар целых чисел (пара p-q интерпритируется что р связано с q.)
Если р связано с q,a q c r,то предпологается,что р связано с r Задача состоит в ниписании задачи для искключения лишних пар из набора:
когда программа получает очередную пару p-q она должна добавлять эту пару только в том случае,если из предыдущих пар не 
следует,что p-q связаны.*/
/*Автор:Ласкина Н.В*/

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
/*Процедура для связывания*/
void MakeRelation(int cur_top, int new_top) {
	if (matr[cur_top][new_top]) return;
	matr[cur_top][new_top] = true;
	for (int i = 0; i < max_n; ++i) {
		if (matr[i][cur_top]) MakeRelation(i, new_top);
	}
}
/*Связывание пар*/
void AddPair(Pair pair) {
	int p = pair.p, q = pair.q;
	if (matr[p][q] == true)
		return;
	MakeRelation(p, q);
	vec.push_back(pair);
}
/*Считывание пар*/
Pair ReadPair() {
	Pair pair;
	cin >> pair.p >> pair.q;
	return pair;
}
/*Количество пар,которые хочет обработать пользователь*/
int main() {
	cout << "How many pairs do you want?" << endl;
	
	int n;
	do {
		cin >> n;
	}
	/*Ввод самих пар*/
	while (n <= 0 || n > max_n);
	cout << "Enter pairs" << endl;
	for (int i = 0; i < n; ++i) {
		Pair p;
		p = ReadPair();
		AddPair(p);
	}
	/*Вывод*/
	cout << "Result:" << endl;
	for (auto &pair : vec) {
		cout << pair.p << " " << pair.q << endl;
	}
	system("pause");
	return 0;
}