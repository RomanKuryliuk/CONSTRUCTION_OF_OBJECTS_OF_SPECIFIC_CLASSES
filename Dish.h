#pragma once

#include "Category.cpp"
#include "Cook.h"

class Dish
{
private:
	char* name;
	int price, time;
	Category category;
	Cook cook;
public:
	Dish();
	Dish(char*, int, int, Category&, Cook&);
	Dish(Dish&);
	~Dish();

	char* get_name();
	int get_price();
	int get_time();
	Category& get_category();
	Cook& get_cook();

	Dish& set_name(char*);
	Dish& set_price(int);
	Dish& set_time(int);
	Dish& set_category(Category&);
	Dish& set_cook(Cook&);

	void show();
};

