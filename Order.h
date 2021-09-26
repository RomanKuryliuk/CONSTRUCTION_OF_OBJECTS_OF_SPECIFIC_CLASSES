#pragma once

#include "Date.h"
#include "Dish.h"

class Order
{
private:
	char* name;
	Date date;
	int number;
	Dish* dishes;

public:
	Order();
	Order(char*, Date, int, Dish*);
	Order(Order&);
	~Order();

	char* get_name();
	Date& get_date();
	int get_number();
	Dish* get_dishes();

	Order& set_name(char*);
	Order& set_date(Date&);
	Order& set_number(int);
	Order& set_dishes(Dish*);

	void add_dish(Dish&);

	void show();
	void short_show();
};

