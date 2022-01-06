#pragma once

struct Book {
	char name[100], author[40], publicCompany[40], ISBN[20], category[40];
	int publicYear, quantity;
	float price;
};

void update_book_data(Book books[], int count_book, const char path[]);

void sort_book(Book books[], int count_book);

void book_menu(Book books[], int& count_book);

void show_book(Book books[], int count_book);

void show_book_detail(Book books[], int count_book);

void add_book(Book books[], int& count_book);

void modify_book_information(Book books[], int count_book);

void delete_book(Book books[], int& count_book);

void find_book(Book books[], int count_book);

void find_by_ISBN(Book books[], int count_book);

void find_by_name(Book books[], int count_book);