#include <locale.h>
#include <iostream>

#include "Date.h"

using namespace std;

int main() {
	
	setlocale(LC_ALL, "Ukrainian");

	cout << "TEST" << endl << endl << "Data" << endl << endl;

	cout << "За замовчуванням" << endl;
	Date date1;
	date1.show();

	cout << "З параметром" << endl;
	cout << "Введіть день, місяць і рік" << endl;
	int day, mounth, year;
	cin >> day >> mounth >> year;
	Date date2(day, mounth, year);
	date2.show();

	cout << "Копіювання" << endl;
	Date date3(date2);
	date3.show();
}