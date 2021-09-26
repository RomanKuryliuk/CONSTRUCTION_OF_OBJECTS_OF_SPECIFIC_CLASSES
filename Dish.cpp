#include <string>
#include <iostream>

#include "Dish.h"

using namespace std;

Dish::Dish()
{
	this->name = new char[7];
	strcpy_s(this->name, sizeof "noname", "noname");

	price = 0;
	time = 0;

	this->category = NONE;
}

Dish::Dish(char* name, int price, int time, Category& category, Cook& cook)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->price = price;
	this->time = time;

	this->category = category;

	this->cook = cook;
}

Dish::Dish(Dish& dish)
{
	this->name = new char[strlen(dish.name) + 1];
	strcpy_s(this->name, strlen(dish.name) + 1, dish.name);

	this->price = dish.price;
	this->time = dish.time;

	this->category = dish.category;

	this->cook = dish.cook;
}

Dish::~Dish()
{
	if (this->name) {
		delete[] this->name;
	}
}

char* Dish::get_name()
{
	return this->name;
}

int Dish::get_price()
{
	return this->price;
}

int Dish::get_time()
{
	return this->time;
}

Category& Dish::get_category()
{
	return this->category;
}

Cook& Dish::get_cook()
{
	return this->cook;
}

Dish& Dish::set_name(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

Dish& Dish::set_price(int price)
{
	this->price = price;
	return *this;
}

Dish& Dish::set_time(int time)
{
	this->time = time;
	return *this;
}

Dish& Dish::set_category(Category& category)
{
	this->category = category;
	return *this;
}

Dish& Dish::set_cook(Cook& cook)
{
	this->cook = cook;
	return *this;
}

void Dish::show()
{
	cout << name << ", " << price << " грн, " << time << "сек, " << category << ", ";
	cook.show();
	cout << endl;
}
