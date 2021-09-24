#include <string>
#include <iostream>

#include "Cook.h"

using namespace std;

Cook::Cook()
{
	this->name = new char[7];
	strcpy_s(this->name, sizeof "noname", "noname");
	this->surname = new char[10];
	strcpy_s(this->surname, sizeof "nosurname", "nosurname");
}

Cook::Cook(char* name, char* surname)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

Cook::Cook(Cook& temp)
{
	this->name = new char[strlen(temp.get_name()) + 1];
	strcpy_s(this->name, strlen(temp.get_name()) + 1, temp.get_name());
	this->surname = new char[strlen(temp.get_surname()) + 1];
	strcpy_s(this->surname, strlen(temp.get_surname()) + 1, temp.get_surname());
}

Cook::~Cook()
{
	if (this->name) {
		delete[] this->name;
	}
	if (this->surname) {
		delete[] this->surname;
	}
}

char* Cook::get_name()
{
	return this->name;
}

char* Cook::get_surname()
{
	return this->surname;
}

Cook& Cook::set_name(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return *this;
}

Cook& Cook::set_surname(char* surname)
{
	delete[] this->surname;
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
	return *this;
}

void Cook::show()
{
	cout << "Cook" << name << ", " << surname << endl;
}
