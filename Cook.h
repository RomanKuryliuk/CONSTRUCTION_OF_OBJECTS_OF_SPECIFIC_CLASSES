#pragma once

class Cook {
private:
	char* name, * surname;

public:
	Cook();
	Cook(char*, char*);
	Cook(Cook&);
	~Cook();
	char* get_name();
	char* get_surname();
	Cook& set_name(char*);
	Cook& set_surname(char*);
	void show();
};