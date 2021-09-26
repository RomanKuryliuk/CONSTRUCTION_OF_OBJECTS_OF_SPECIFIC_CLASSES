#include <locale.h>
#include <iostream>
#include <conio.h>

#include "Order.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Ukrainian");

	cout << "За замовчуванням" << endl;
	Order order1;

	cout << "Повний вивiд" << endl;
	order1.show();
	cout << "скорочений вивiд" << endl;
	order1.short_show();

	cout << "З параметрами" << endl;

	char* name = new char;
	cout << "Введiть iм'я замовлення" << endl;
	cin >> name;

	int day = 0, mounth = 0, year = 0;
	cout << "Введiть день, мiсяць i рiк через пробiл" << endl;
	cin >> day >>  mounth >> year;
	Date date(day, mounth, year);

	int number;
	cout << "Введiть кiлькiсть страв у замовленнi" << endl;
	cin >> number;

	Dish* dishes = new Dish[number+1];
	char* name_dish = new char;
	int price = 0, time = 0, category = 0;
	char* name_cook = new char, * surname_cook = new char;
	cout << "Вводьте iм'я страви, цiну, час приготування, категорiя, iм'я i прiзвище кухаря (кожне з нового рядка)" << endl;
	for (int i = 0; i < number; i++) {
		cout << i + 1 << " страва:" << endl;
		cin >> name_dish >> price >> time >> category >> name_cook >> surname_cook;
		enum Category temp_category;
		switch (category) {
		case 0:
			temp_category = NONE;
			break;
		case 1:
			temp_category = COLD_SNACKS;
			break;
		case 2:
			temp_category = FIRST_COURSES;
			break;
		case 3:
			temp_category = SECOND_COURSES;
			break;
		case 4:
			temp_category = DESSERTS;
			break;
		case 5:
			temp_category = DRINKS;
			break;
		default:
			break;
		}
		Cook temp_cook(name_cook, surname_cook);
		Dish temp_dish(name_dish, price, time, temp_category, temp_cook);
		dishes[i].set_name(name_dish);
		dishes[i].set_price(price);
		dishes[i].set_time(time);
		dishes[i].set_category(temp_category);
		dishes[i].set_cook(temp_cook);
	}

	Order order2(name, date, number, dishes);
	cout << "Повний вивiд" << endl;
	order2.show();
	cout << "Скорочений вивiд" << endl;
	order2.short_show();

	_getch();
}