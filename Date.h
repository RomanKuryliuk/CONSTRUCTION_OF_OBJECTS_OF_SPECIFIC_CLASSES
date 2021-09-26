#pragma once

class Date
{
private:
	int day, mounth, year;

public:
	Date();
	Date(int, int, int);
	Date(Date&);
	~Date();

	int get_day();
	int get_mounth();
	int get_year();

	Date& set_day(int);
	Date& set_mounth(int);
	Date& set_year(int);

	void show();
};

