#pragma once

struct Date {
	int day, month, year;
};

bool isLeapYear(int year);

void next_day(Date& date);

int rdn(Date date);

int distance(Date d1, Date d2);

Date get_today();