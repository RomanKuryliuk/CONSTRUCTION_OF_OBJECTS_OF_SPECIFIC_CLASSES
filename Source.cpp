#include <locale.h>
#include <iostream>

#include "Date.h"

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Ukrainian");

	cout << "TEST" << endl << endl << "Data" << endl << endl;

	cout << "�� �������������" << endl;
	Date date1;
	date1.show();

	cout << "� ����������" << endl;
	cout << "������ ����, ����� � ��" << endl;
	int day, mounth, year;
	cin >> day >> mounth >> year;
	Date date2(day, mounth, year);
	date2.show();

	cout << "���������" << endl;
	Date date3(date2);
	date3.show();
}