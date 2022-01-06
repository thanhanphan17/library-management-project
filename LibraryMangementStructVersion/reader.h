#pragma once
#include "date.h"

struct Reader {
	int gender;
	Date birthday;
	Date registerDay;
	char id[20], idCard[20], email[40];
	char name[40], address[40];
};


void update_reader_data(Reader readers[], int count_reader, const char path[]);

void reader_menu(Reader readers[], int& count_reader);

void sort_reader(Reader readers[], int count_reader);

void add_reader(Reader readers[], int& count_reader);

void show_reader(Reader readers[], int& count_reader);

void show_reader_detail(Reader readers[], int& count_reader);

void modify_reader_information(Reader readers[], int& count_reader);

void delete_reader(Reader readers[], int& count_reader);

void find_reader_menu(Reader readers[], int count_reader);

void find_by_idCard(Reader readers[], int count_reader);

void find_by_name(Reader readers[], int count_reader);

void find_by_email(Reader readers[], int count_reader);