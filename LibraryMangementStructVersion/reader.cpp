#pragma once
#include "init.h"

using namespace std;

// Update all information in file
void update_reader_data(Reader readers[], int count_reader, const char path[]) {
	FILE* fo;
	fopen_s(&fo, path, "wt");

	if (fo != NULL) {
		for (int i = 0; i < count_reader; ++i) {
			fprintf(fo, "Ma doc gia: %s\n", readers[i].id);
			fprintf(fo, "Ten doc gia: %s\n", readers[i].name);
			fprintf(fo, "CMND: %s\n", readers[i].idCard);
			fprintf(fo, "Ngay sinh: %d/%d/%d\n",
				readers[i].birthday.day,
				readers[i].birthday.month,
				readers[i].birthday.year);

			fprintf(fo, "Gioi tinh: %d\n", readers[i].gender);
			fprintf(fo, "Dia chi: %s\n", readers[i].address);
			fprintf(fo, "Email: %s\n", readers[i].email);
			fprintf(fo, "Ngay lap the: %d/%d/%d\n\n",
				readers[i].registerDay.day,
				readers[i].registerDay.month,
				readers[i].registerDay.year);
		}
		fclose(fo);
	}
}

void reader_menu(Reader readers[], int &count_reader) {
	while (1) {
		system("cls");
		show_logo();
		colorFont(9);
		gotoxy(10, 12);
		printf("( 1 ) Danh sach doc gia");
		gotoxy(10, 14);
		printf("( 2 ) Them doc gia");
		gotoxy(10, 16);
		printf("( 3 ) Chinh sua thong tin doc gia");

		gotoxy(50, 12);
		printf("( 4 ) Xoa thong tin doc gia");
		gotoxy(50, 14);
		printf("( 5 ) Tim kiem doc gia");
		gotoxy(50, 16);
		printf("( 6 ) Tro lai menu chinh");

		gotoxy(30, 18);
		printf("Nhap lua chon [ ]");
		colorFont(12);
		gotoxy(45, 18);

		int option;
		scanf_s("%d", &option);
		colorFont(9);
		switch (option) {
			case 1:
				show_reader(readers, count_reader);
				break;

			case 2:
				add_reader(readers, count_reader);
				break;

			case 3:
				modify_reader_information(readers, count_reader);
				break;

			case 4:
				delete_reader(readers, count_reader);
				break;

			case 5:
				find_reader_menu(readers, count_reader);
				break;

			case 6:
				return;
		}

		scanf_s("%*c");
	}
}

void add_reader(Reader readers[], int& count_reader) {
	char option;
	do {
		system("cls");
		gotoxy(1, 0);
		printf("Them doc gia vao thu vien");
		gotoxy(1, 1);
		colorFont(9);
		printf("Nhap ma doc gia: ");
		colorFont(12);
		scanf_s("%s", readers[count_reader].id, 20);

		// Check reader's id, if it existed input again
		while (true) {
			bool check = false;
			for (int i = 0; i < count_reader ; ++i) {
				if (strcmp(readers[count_reader].id, readers[i].id) == 0) {
					check = true;
					gotoxy(1, 1);
					colorFont(9);
					colorFont(9);
					printf("Ma doc gia bi trung, nhap lai ma doc gia:           ");
					colorFont(12);
					gotoxy(43, 1);
					scanf_s("%s", &readers[count_reader].id, 20);
				}
			}
			if (!check) {
				break;
			}
		}

		scanf_s("%*c");
		gotoxy(1, 2);
		colorFont(9);
		printf("Nhap ten doc gia: ");
		colorFont(12);
		scanf_s("%[^\n]", readers[count_reader].name, 40);

		gotoxy(1, 3);
		colorFont(9);
		printf("Nhap CMND/CCCD: ");
		colorFont(12);
		scanf_s("\n%s", readers[count_reader].idCard, 20);
		
		// Check id card, if it existed input again
		while (true) {
			bool check = false;
			for (int i = 0; i < count_reader; ++i) {
				//printf("%d %d \n", strlen(readers[count_reader].idCard), strlen(readers[i].idCard));
				if (strcmp(readers[count_reader].idCard, readers[i].idCard) == 0) {
					check = true;
					gotoxy(1, 3);
					colorFont(9);
					printf("So cmnd/cccd bi trung, vui long nhap lai:           ");
					colorFont(12);
					gotoxy(43, 3);
					scanf_s("\n%[^\n]", readers[count_reader].idCard, 20);
				}
			}
			if (!check) {
				break;
			}
		}

		gotoxy(1, 4);
		colorFont(9);
		printf("Nhap ngay thang nam sinh (dd/mm/yyyy): ");
		colorFont(12);
		scanf_s("%d/%d/%d", &readers[count_reader].birthday.day,
			&readers[count_reader].birthday.month, &readers[count_reader].birthday.year);

		gotoxy(1, 5);
		colorFont(9);
		printf("Nhap gioi tinh (nam 1, nu 0): ");
		colorFont(12);
		scanf_s("%d", &readers[count_reader].gender);

		scanf_s("%*c");
		gotoxy(1, 6);
		colorFont(9);
		printf("Nhap dia chi: ");
		colorFont(12);
		scanf_s("%[^\n]", readers[count_reader].address, 40);

		gotoxy(1, 7);
		colorFont(9);
		printf("Nhap email: ");
		colorFont(12);
		scanf_s("\n%s", readers[count_reader].email, 40);

		// Check email, if email is existed input again
		while (true) {
			bool check = false;
			for (int i = 0; i < count_reader; ++i) {
				if (strcmp(readers[count_reader].email, readers[i].email) == 0) {
					check = true;
					gotoxy(1, 3);
					colorFont(9);
					printf("Email da duoc su dung, vui long nhap lai:                                 ");
					colorFont(12);
					gotoxy(43, 3);
					scanf_s("\n%[^\n]", readers[count_reader].email, 20);
				}
			}
			if (!check) {
				break;
			}
		}

		gotoxy(1, 8);
		colorFont(9);
		printf("Nhap ngay lap the (dd/mm/yyy): ");
		colorFont(12);
		scanf_s("%d/%d/%d", &readers[count_reader].registerDay.day,
			&readers[count_reader].registerDay.month, &readers[count_reader].registerDay.year);

		count_reader++;
		sort_reader(readers, count_reader);
		update_reader_data(readers, count_reader, "reader_data.txt");
		
		printf(" Ban co muon them doc gia khong? (y/n): ");
		option = _getch();
	} while (option != 'n' && option != 'N');
}

void show_reader(Reader readers[], int& count_reader) {
	while (1) {
		colorFont(9);
		system("cls");
		gotoxy(1, 1);
		printf("(1) Xem thong tin chi tiet cua doc gia \n");
		gotoxy(1, 2);
		printf("(2) Tro ve menu \n");
		gotoxy(1, 3);
		printf("    Nhap lua chon cua ban [ ] \n\n");
		printf("Danh sach doc gia \n");
		gotoxy(0, 6);
		printf("____________________________________________________________________________________________________________________________________________\n");
		printf("| %-20s| ", "MA DOC GIA");
		printf(" %-30s|", "TEN DOC GIA");
		printf(" %-15s|", "CMND");
		printf(" %-30s|", "EMAIL");
		printf(" %-33s |", "DIA CHI");
		gotoxy(0, 8);
		printf("|_____________________|________________________________|________________|_______________________________|___________________________________|\n");
		for (int i = 0; i < count_reader; ++i) {
			printf("| %-20s| ", readers[i].id);
			printf(" %-30s|", readers[i].name);
			printf(" %-15s|", readers[i].idCard);
			printf(" %-30s|", readers[i].email);
			printf(" %-33s |", readers[i].address);
			printf("\n");
			printf("|_____________________|________________________________|________________|_______________________________|___________________________________|\n");
		}
		gotoxy(28, 3);
		int option;
		colorFont(12);
		scanf_s("%d", &option);
		switch (option) {
			case 1:
				show_reader_detail(readers, count_reader);
				break;

			case 2:
				return;
		}
		colorFont(9);
		scanf_s("%*c");
	}
}

void show_reader_detail(Reader readers[], int& count_reader) {
	system("cls");
	colorFont(9);
	gotoxy(3, 2);
	printf("Nhap ma doc gia de xem thong tin chi tiet: ");
	colorFont(12);
	char _id[20] = { 0 };
	scanf_s("%s", _id, 20);

	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		if (strcmp(_id, readers[i].id) == 0) {
			found = true;

			gotoxy(3, 4);
			colorFont(9);
			printf("Ten doc gia: ");
			colorFont(14);
			printf("%s", readers[i].name);

			gotoxy(40, 4);
			colorFont(9);
			printf("ID: ");
			colorFont(14);
			printf("%s", readers[i].id);

			gotoxy(3, 6);
			colorFont(9);
			printf("CMND/CCCD: ");
			colorFont(14);
			printf("%s", readers[i].idCard);


			gotoxy(40, 6);
			colorFont(9);
			printf("Ngay sinh: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].birthday.day, 
				readers[i].birthday.month, readers[i].birthday.year);

			gotoxy(3, 8);
			colorFont(9);
			printf("Gioi tinh: ");
			colorFont(14);
			if (readers[i].gender == 1) {
				printf("Nam");
			} else {
				printf("Nu");
			}

			gotoxy(40, 8);
			colorFont(9);
			printf("Email: ");
			colorFont(14);
			printf("%s", readers[i].email);

			gotoxy(3, 10);
			colorFont(9);
			printf("Ngay lap the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year);

			gotoxy(40, 10);
			colorFont(9);
			printf("Ngay het han the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year + 4);

			gotoxy(3, 12);
			colorFont(9);
			printf("Dia chi: ");
			colorFont(14);
			printf("%s", readers[i].address);
		}
	}

	colorFont(12);
	if (!found) {
		gotoxy(3, 4);
		printf("Khong tim thay doc gia");
		gotoxy(3, 5);
		printf("Nhan enter de quay lai!");
	} else {
		gotoxy(3, 14);
		printf("Nhan enter de quay lai!");
	}
	scanf_s("%*c");
	colorFont(9);
	return;
}

void modify_reader_information(Reader readers[], int& count_reader) {
	system("cls");
	show_logo();
	colorFont(9);
	gotoxy(10, 10);
	printf("Nhap CMND/CCCD cua doc gia can thay doi thong tin: ");
	char _idCard[MXN] = {0};
	
	colorFont(12);
	scanf_s("%*c");
	scanf_s("%[^\n]", _idCard, 12);
	
	colorFont(9);
	int pos = 0;
	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		if (strcmp(_idCard, readers[i].idCard) == 0) {
			pos = i;
			found = true;
			printf("____________________________________________________________________________________________________________________________________________\n");
			printf("| %-20s| ", "MA DOC GIA");
			printf(" %-30s|", "TEN DOC GIA");
			printf(" %-15s|", "CMND");
			printf(" %-30s|", "EMAIL");
			printf(" %-33s |", "DIA CHI");
			printf("|_____________________|________________________________|________________|_______________________________|___________________________________|\n");

			printf("| %-20s| ", readers[i].id);
			printf(" %-30s|", readers[i].name);
			printf(" %-15s|", readers[i].idCard);
			printf(" %-30s|", readers[i].email);
			printf(" %-33s |", readers[i].address);
			printf("\n");
			printf("|_____________________|________________________________|________________|_______________________________|___________________________________|\n");
		}
	}

	gotoxy(1, 17);
	if (found) {
		printf("( 1 ) Thay doi ma doc gia");
		gotoxy(1, 18);
		printf("( 2 ) Thay doi ten doc gia");
		gotoxy(1, 19);
		printf("( 3 ) Thay doi CMND/CCCD");
		gotoxy(1, 20);
		printf("( 4 ) Thay doi ngay thang nam sinh (dd/mm/yyyy)");
		gotoxy(1, 21);
		printf("( 5 ) Thay doi gioi tinh");
		gotoxy(1, 22);
		printf("( 6 ) Thay doi email");
		gotoxy(1, 23);
		printf("( 7 ) Thay doi dia chi");
		gotoxy(1, 24);
		printf("( 8 ) Thay doi ngay lap the");

		gotoxy(1, 25);
		printf("( 9 ) Thoat");
		gotoxy(1, 26);
		printf("Nhap lua chon [ ]");
		gotoxy(16, 26);
		int option;
		int line = 27;
		while (1) {
			colorFont(12);
			scanf_s("%d", &option);
			switch (option) {
				case 1:
					colorFont(9);
					gotoxy(1, line++);
					printf("Ma doc gia cu: ");
					colorFont(14);
					printf("%s", readers[pos].id);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap ma doc gia moi: ");
					colorFont(14);
					scanf_s("%s", readers[pos].id, 20);

					while (true) {
						bool check = false;
						for (int i = 0; i < count_reader; ++i) {
							if (i == pos) continue;
							if (strcmp(readers[pos].id, readers[i].id) == 0) {
								check = true;
								gotoxy(1, line - 1);
								colorFont(9);
								printf("Ma doc gia bi trung, nhap lai ma doc gia:           ");
								colorFont(12);
								gotoxy(43, line - 1);
								scanf_s("%s", readers[pos].id, 20);
							}
						}
						if (!check) {
							break;
						}
					}

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 2:
					colorFont(9);
					gotoxy(1, line++);
					printf("Ten doc gia cu: ");
					colorFont(14);
					printf("%s", readers[pos].name);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap ten doc gia moi: ");
					colorFont(14);
					scanf_s("%*c");
					scanf_s("%[^\n]", readers[pos].name, 40);

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 3:
					colorFont(9);
					gotoxy(1, line++);
					printf("So cmnd/cccd cu: ");
					colorFont(14);
					printf("%s", readers[pos].idCard);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap so CMND/CCCD moi: ");
					colorFont(14);
					scanf_s("%s", readers[pos].idCard, 12);

					// Check id card, if it existed input again
					while (true) {
						bool check = false;
						for (int i = 0; i < count_reader; ++i) {
							if (i == pos) continue;
							if (strcmp(readers[pos].idCard, readers[i].idCard) == 0) {
								check = true;
								gotoxy(1, line - 1);
								colorFont(9);
								printf("So cmnd/cccd bi trung, vui long nhap lai:                ");
								colorFont(12);
								gotoxy(43, line - 1);
								scanf_s("\n%[^\n]", readers[pos].idCard, 20);
							}
						}
						if (!check) {
							break;
						}
					}

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 4:
					colorFont(9);
					gotoxy(1, line++);
					printf("Ngay sinh cu: ");
					colorFont(14);
					printf("%02d/%02d/%04d", readers[pos].birthday.day,
						readers[pos].birthday.month, readers[pos].birthday.year);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap ngay sinh moi: ");
					colorFont(14);
					scanf_s("%d/%d/%d", &readers[pos].birthday.day,
						&readers[pos].birthday.month, &readers[pos].birthday.year);

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 5:
					colorFont(9);
					gotoxy(1, line++);
					printf("Gioi tinh cu: ");
					colorFont(14);
					if (readers[pos].gender == 1) {
						printf("Nam");
					} else {
						printf("Nu");
					}

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap gioi tinh moi (1: nam, 0: nu): ");
					colorFont(14);
					scanf_s("%d", &readers[pos].gender);

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 6:
					colorFont(9);
					gotoxy(1, line++);
					printf("Email cu: ");
					colorFont(14);
					printf("%s", readers[pos].email);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap email moi: ");
					colorFont(14);
					scanf_s("%*c");
					scanf_s("%s", readers[pos].email, 40);

					while (true) {
						bool check = false;
						for (int i = 0; i < count_reader; ++i) {
							if (i == pos) continue;
							if (strcmp(readers[pos].email, readers[i].email) == 0) {
								check = true;
								gotoxy(1, line - 1);
								colorFont(9);
								printf("Email da duoc su dung, vui long nhap lai:                                ");
								colorFont(12);
								gotoxy(43, line - 1);
								scanf_s("\n%[^\n]", readers[pos].email, 40);
							}
						}

						if (!check) {
							break;
						}
					}

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 7:
					colorFont(9);
					gotoxy(1, line++);
					printf("Dia chi cu: ");
					colorFont(14);
					printf("%s", readers[pos].address);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap dia chi moi: ");
					colorFont(14);
					scanf_s("%*c");
					scanf_s("%[^\n]", readers[pos].address, 40);

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 8:
					colorFont(9);
					gotoxy(1, line++);
					printf("Ngay lap the cu: ");
					colorFont(14);
					printf("%02d/%02d/%04d", readers[pos].registerDay.day,
						readers[pos].registerDay.month, readers[pos].registerDay.year);

					colorFont(9);
					gotoxy(1, line++);
					printf("Nhap ngay sinh moi: ");
					colorFont(14);
					scanf_s("%d/%d/%d", &readers[pos].registerDay.day,
						&readers[pos].registerDay.month, &readers[pos].registerDay.year);

					gotoxy(1, line++);
					printf("Da thay doi thong tin");
					scanf_s("%*c");
					scanf_s("%*c");
					break;

				case 9:
					return;
			}
			// clear lines
			for (int i = 27; i <= line; ++i) {
				gotoxy(0, i);
				printf("                                                                                      ");
			}

			line = 27;
			gotoxy(16, 26);
			printf(" ");
			gotoxy(16, 26);

			update_reader_data(readers, count_reader, "reader_data.txt");
		}
	} else {
		colorFont(12);
		gotoxy(10, 12);
		printf("Khong tim thay doc gia");
	}

	scanf_s("%*c");
	return;
}

void sort_reader(Reader readers[], int count_reader) {
	bool haveSwap = false;
	for (int i = 0; i < count_reader - 1; ++i) {
		haveSwap = false;
		for (int j = 0; j < count_reader - i - 1; j++) {
			if (strcmp(readers[j].id, readers[j + 1].id) > 0) {
				std::swap(readers[j], readers[j + 1]);
				haveSwap = true;
			}
		}

		if (haveSwap == false) {
			break;
		}
	}
}

void delete_reader(Reader readers[], int& count_reader) {
	system("cls");
	show_logo();
	gotoxy(5, 14);
	char _idCard[20] = { 0 };

	colorFont(9);
	printf("Nhap cmnd/cccd cua doc gia can xoa: ");
	colorFont(12);
	scanf_s("%s", _idCard, 20);
	
	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		//printf("%d %d \n", strlen(_idCard), strlen(readers[i].idCard));
		if (strcmp(_idCard, readers[i].idCard) == 0) {
			found = true;
			for (int k = i; k < count_reader - 1; ++k) {
				readers[k] = readers[k + 1];
			}
		}
	}
	
	if (found) {
		count_reader--;
	}

	gotoxy(5, 16);
	colorFont(12);
	if (!found) {
		printf("Khong tim thay doc gia");
	} else {
		printf("Da xoa doc gia khoi danh sach");
	}
	update_reader_data(readers, count_reader, "reader_data.txt");
	scanf_s("%*c");
}

void find_reader_menu(Reader readers[], int count_reader) {
	while (1) {
		system("cls");
		show_logo();
		colorFont(9);
		gotoxy(10, 12);
		printf("( 1 ) Tim bang CMND/CCCD");
		gotoxy(10, 14);
		printf("( 2 ) Tim bang ho ten");
		gotoxy(10, 16);
		printf("( 3 ) Tim theo email");
		gotoxy(10, 18);
		printf("( 4 ) Tro ve menu chinh");
		gotoxy(10, 20);
		printf("Nhap lua chon [ ]");
		colorFont(12);
		gotoxy(25, 20);

		int option;
		scanf_s("%d", &option);
		switch (option) {
			case 1:
				find_by_idCard(readers, count_reader);
				break;

			case 2:
				find_by_name(readers, count_reader);
				break;

			case 3:
				find_by_email(readers, count_reader);
				break;

			case 4:
				return;
		}
		scanf_s("%*c");
	}
}

void find_by_idCard(Reader readers[], int count_reader) {
	system("cls");
	show_logo();
	char _idCard[20] = { 0 };

	gotoxy(8, 12);
	colorFont(9);
	printf("Nhap vao cmnd de tim doc gia: ");
	colorFont(12);
	scanf_s("%s", _idCard, 20);

	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		if (strcmp(_idCard, readers[i].idCard) == 0) {
			found = true;
			gotoxy(8, 15);
			colorFont(9);
			printf("Ten doc gia: ");
			colorFont(14);
			printf("%s", readers[i].name);

			gotoxy(40, 15);
			colorFont(9);
			printf("ID: ");
			colorFont(14);
			printf("%s", readers[i].id);

			gotoxy(8, 17);
			colorFont(9);
			printf("CMND/CCCD: ");
			colorFont(14);
			printf("%s", readers[i].idCard);


			gotoxy(40, 17);
			colorFont(9);
			printf("Ngay sinh: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].birthday.day,
				readers[i].birthday.month, readers[i].birthday.year);

			gotoxy(8, 19);
			colorFont(9);
			printf("Gioi tinh: ");
			colorFont(14);
			if (readers[i].gender == 1) {
				printf("Nam");
			} else {
				printf("Nu");
			}

			gotoxy(40, 19);
			colorFont(9);
			printf("Email: ");
			colorFont(14);
			printf("%s", readers[i].email);

			gotoxy(8, 21);
			colorFont(9);
			printf("Ngay lap the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year);

			gotoxy(40, 21);
			colorFont(9);
			printf("Ngay het han the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year + 4);

			gotoxy(8, 23);
			colorFont(9);
			printf("Dia chi: ");
			colorFont(14);
			printf("%s", readers[i].address);
		}
	}
	if (!found) {
		gotoxy(8, 14);
		colorFont(12);
		printf("Khong tim thay doc gia!");
		colorFont(9);
	} else {
		gotoxy(8, 25);
		colorFont(12);
		printf("Nhan enter de quay lai!");
		colorFont(9);
	}

	scanf_s("%*c");
}

void find_by_name(Reader readers[], int count_reader) {
	system("cls");
	show_logo();
	char _name[40] = { 0 };

	gotoxy(8, 12);
	colorFont(9);
	printf("Nhap ten doc gia can tim: ");
	colorFont(12);
	scanf_s("%*c");
	scanf_s("%[^\n]", _name, 40);
	to_lower(_name);

	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		char tmp_name[40] = { 0 };
		strcpy(tmp_name, readers[i].name);
		to_lower(tmp_name);

		if (strcmp(_name, tmp_name) == 0) {
			found = true;
			gotoxy(8, 15);
			colorFont(9);
			printf("Ten doc gia: ");
			colorFont(14);
			printf("%s", readers[i].name);

			gotoxy(40, 15);
			colorFont(9);
			printf("ID: ");
			colorFont(14);
			printf("%s", readers[i].id);

			gotoxy(8, 17);
			colorFont(9);
			printf("CMND/CCCD: ");
			colorFont(14);
			printf("%s", readers[i].idCard);


			gotoxy(40, 17);
			colorFont(9);
			printf("Ngay sinh: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].birthday.day,
				readers[i].birthday.month, readers[i].birthday.year);

			gotoxy(8, 19);
			colorFont(9);
			printf("Gioi tinh: ");
			colorFont(14);
			if (readers[i].gender == 1) {
				printf("Nam");
			} else {
				printf("Nu");
			}

			gotoxy(40, 19);
			colorFont(9);
			printf("Email: ");
			colorFont(14);
			printf("%s", readers[i].email);

			gotoxy(8, 21);
			colorFont(9);
			printf("Ngay lap the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year);

			gotoxy(40, 21);
			colorFont(9);
			printf("Ngay het han the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year + 4);

			gotoxy(8, 23);
			colorFont(9);
			printf("Dia chi: ");
			colorFont(14);
			printf("%s", readers[i].address);
		}
	}
	if (!found) {
		gotoxy(8, 14);
		colorFont(12);
		printf("Khong tim thay doc gia!");
		colorFont(9);
	} else {
		gotoxy(8, 25);
		colorFont(12);
		printf("Nhan enter de quay lai!");
		colorFont(9);
	}

	scanf_s("%*c");
}

void find_by_email(Reader readers[], int count_reader) {
	system("cls");
	show_logo();
	char _email[40] = { 0 };

	gotoxy(8, 12);
	colorFont(9);
	printf("Nhap vao email de tim doc gia: ");
	colorFont(12);
	scanf_s("%s", _email, 40);
	to_lower(_email);

	bool found = false;
	for (int i = 0; i < count_reader; ++i) {
		char tmp_email[40] = { 0 };
		strcpy(tmp_email, readers[i].email);
		to_lower(tmp_email);

		if (strcmp(_email, tmp_email) == 0) {
			found = true;
			gotoxy(8, 15);
			colorFont(9);
			printf("Ten doc gia: ");
			colorFont(14);
			printf("%s", readers[i].name);

			gotoxy(40, 15);
			colorFont(9);
			printf("ID: ");
			colorFont(14);
			printf("%s", readers[i].id);

			gotoxy(8, 17);
			colorFont(9);
			printf("CMND/CCCD: ");
			colorFont(14);
			printf("%s", readers[i].idCard);


			gotoxy(40, 17);
			colorFont(9);
			printf("Ngay sinh: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].birthday.day,
				readers[i].birthday.month, readers[i].birthday.year);

			gotoxy(8, 19);
			colorFont(9);
			printf("Gioi tinh: ");
			colorFont(14);
			if (readers[i].gender == 1) {
				printf("Nam");
			} else {
				printf("Nu");
			}

			gotoxy(40, 19);
			colorFont(9);
			printf("Email: ");
			colorFont(14);
			printf("%s", readers[i].email);

			gotoxy(8, 21);
			colorFont(9);
			printf("Ngay lap the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year);

			gotoxy(40, 21);
			colorFont(9);
			printf("Ngay het han the: ");
			colorFont(14);
			printf("%02d/%02d/%04d", readers[i].registerDay.day,
				readers[i].registerDay.month, readers[i].registerDay.year + 4);

			gotoxy(8, 23);
			colorFont(9);
			printf("Dia chi: ");
			colorFont(14);
			printf("%s", readers[i].address);
		}
	}
	if (!found) {
		gotoxy(8, 14);
		colorFont(12);
		printf("Khong tim thay doc gia!");
		colorFont(9);
	} else {
		gotoxy(8, 25);
		colorFont(12);
		printf("Nhan enter de quay lai!");
		colorFont(9);
	}

	scanf_s("%*c");
}
