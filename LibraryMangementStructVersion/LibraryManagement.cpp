#include "init.h"

using namespace std;

int main() {
	resizeConsole(1050, 600);

	Reader readers[MXN];
	int count_reader = 0;

	Book books[MXN];
	int count_book = 0;

	BorrowCard bCards[MXN];
	int count_borrow = 0;

	// init data
	init_book(books, count_book, "book_data.txt");
	init_reader(readers, count_reader, "reader_data.txt");
	init_borrow_book(bCards, books, count_borrow, count_book, "borrow_book_data.txt");

	while (1) {
		system("cls");
		show_logo();
		show_main_menu();
		int option;
		scanf_s("%d", &option);

		switch (option) {	
			case 1:
				reader_menu(readers, count_reader);
				break;

			case 2:
				book_menu(books, count_book);
				break;

			case 3:
				borrow_book(bCards, readers, books, count_borrow, count_reader, count_book);
				break;

			case 4:
				return_book(bCards, books, count_borrow, count_book);
				break;

			case 5:
				static_menu(books, readers, bCards, count_book, count_reader, count_borrow);
				break;
		}
		scanf_s("%*c");
	}
}

