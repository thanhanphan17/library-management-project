#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "reader.h"
#include "book.h"
#include "theme.h"
#include "date.h"
#include "borrow.h"
#include "static.h"
#include "str_process.h"

const int MXN = 20;

void init_reader(Reader readers[], int& count_reader, const char path[]);

void init_book(Book books[], int& count_book, const char path[]);

void init_borrow_book(BorrowCard bCards[], Book books[], int& count_borrow, int count_book, const char path[]);

