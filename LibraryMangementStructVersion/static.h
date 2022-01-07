#pragma once
#include "init.h"

void static_menu(Book books[], Reader readers[], BorrowCard bCards[], int count_book, int count_reader, int count_borrow);

void static_book(Book books[], int count_book);

void static_reader(Reader readers[], int count_reader);

void static_borrow_book(BorrowCard bCards[], int count_borrow);

void static_borrow_reader(BorrowCard bCards[], int count_borrow);

void sort_category(char category[][100], int quantity[100], int count_book);

void sort_book(char book_name[][100], int count_not_return);