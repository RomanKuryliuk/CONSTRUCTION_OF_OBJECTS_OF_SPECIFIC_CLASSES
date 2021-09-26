#include <string>
#include <iostream>

#include "Order.h"

using namespace std;

Order::Order()
{
	this->name = new char[7];
	strcpy_s(this->name, sizeof "noname", "noname");

	this->number = 0;

	this->dishes = new Dish[0];
}

Order::Order(char* name, Date date, int number, Dish* dishes)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->date = date;

	this->number = number;

	for (int i = 0; i < this->number; i++) {
		this->dishes[i] = dishes[i];
	}
}

Order::Order(Order& order)
{
	this->name = new char[strlen(order.name) + 1];
	strcpy_s(this->name, strlen(order.name) + 1, order.name);

	this->date = order.date;

	this->number = order.number;

	for (int i = 0; i < this->number; i++) {
		this->dishes[i] = order.dishes[i];
	}
}

Order::~Order()
{
	if (this->name) {
		delete[] name;
	}
	if (this->dishes) {
		delete[] dishes;
	}
}

char* Order::get_name()
{
	return this->name;
}

Date& Order::get_date()
{
	return this->date;
}

int Order::get_number()
{
	return this->number;
}

Dish* Order::get_dishes()
{
	return this->dishes;
}

Order& Order::set_name(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

Order& Order::set_date(Date& date)
{
	this->date = date;
	return *this;
}

Order& Order::set_number(int number)
{
	this->number = number;
	return *this;
}

Order& Order::set_dishes(Dish*)
{
	delete[] dishes;
	for (int i = 0; i < this->number; i++) {
		this->dishes[i] = dishes[i];
	}
	return *this;
}

void Order::add_dish(Dish& dish)
{
	dishes[this->number] = dish;
	this->number++;
}

void Order::show()
{
	cout << name << ", ";
	this->date.show();
	cout << ", " << number << ", " << "dishes:" << endl;
	for (int i = 0; i < this->number; i++) {
		dishes[i].show();
		cout << ", ";
	}
	cout << endl;
}

void Order::short_show()
{
	cout << name << ", ";
	this->date.show();
	cout << ", ";

	int temp = 0;
	for (int i = 0; i < this->number; i++) {
		temp += this->dishes[i].get_time();
	}

	cout << temp << "сек" << endl;
}
