#pragma once
#include "init.h"

struct BorrowCard {
	char id[100];
	Date bDate, rDate;
	char status[20];
	int bQuantity, lostQuantity;
	double fine;
	Book bBook[10];
	Book lBook[10];
	Reader bReader;
};

void update_borrow_book(BorrowCard bCards[], int count_borrow, const char path[]);

void borrow_book(BorrowCard bCards[], Reader readers[], Book books[], int& count_borrow, int count_reader, int count_book);

void return_book(BorrowCard bCards[], Book books[], int& count_borrow, int count_book);
