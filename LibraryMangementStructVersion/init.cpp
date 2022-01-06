#include "init.h"

void init_reader(Reader readers[], int& count_reader, const char path[]) {
	FILE* fi;
	fopen_s(&fi, path, "r");
	if (fi != NULL) {
		while (!feof(fi)) {
			fscanf_s(fi, "Ma doc gia: %s \n", readers[count_reader].id, 20);
			fscanf_s(fi, "Ten doc gia: %[^\n]\n", readers[count_reader].name, 40);
			fscanf_s(fi, "CMND: %s\n", readers[count_reader].idCard, 20);
			fscanf_s(fi, "Ngay sinh: %d/%d/%d \n",
				&readers[count_reader].birthday.day,
				&readers[count_reader].birthday.month,
				&readers[count_reader].birthday.year);

			fscanf_s(fi, "Gioi tinh: %d\n", &readers[count_reader].gender);
			fscanf_s(fi, "Dia chi: %[^\n]\n", readers[count_reader].address, 40);
			fscanf_s(fi, "Email: %s\n", readers[count_reader].email, 40);

			fscanf_s(fi, "Ngay lap the: %d/%d/%d \n\n",
				&readers[count_reader].registerDay.day,
				&readers[count_reader].registerDay.month,
				&readers[count_reader].registerDay.year);
			
			//printf("%s \n", readers[count_reader].name);
			count_reader++;
		}
		fclose(fi);
	}
}

void init_book(Book books[], int& count_book, const char path[]) {
	FILE* fi;
	fopen_s(&fi, path, "r");

	if (fi != NULL) {
		while (!feof(fi)) {
			fscanf_s(fi, "Ten sach: %[^\n]\n", books[count_book].name, 100);
			fscanf_s(fi, "Tac gia: %[^\n]\n", books[count_book].author, 40);
			fscanf_s(fi, "NXB: %[^\n]\n", books[count_book].publicCompany, 40);
			fscanf_s(fi, "ISBN: %[^\n]\n", books[count_book].ISBN, 20);
			fscanf_s(fi, "Nam xuat ban: %d\n", &books[count_book].publicYear);
			fscanf_s(fi, "The loai: %[^\n]\n", books[count_book].category, 40);
			fscanf_s(fi, "Gia: %f\n", &books[count_book].price);
			fscanf_s(fi, "So luong: %d\n", &books[count_book].quantity);

			//printf("%s\n", books[count_book].name);
			count_book++;
		}
		fclose(fi);
	}
}

void init_borrow_book(BorrowCard bCards[], int& count_borrow, const char path[]) {
	FILE* fi;
	fopen_s(&fi, path, "r");

	if (fi != NULL) {
		while (!feof(fi)) {
			fscanf_s(fi, "Ma phieu: %s\n", bCards[count_borrow].id, 100);
			fscanf_s(fi, "Ma doc gia: %s\n", bCards[count_borrow].bReader.id, 20);
			fscanf_s(fi, "Ten doc gia: %[^\n]\n", bCards[count_borrow].bReader.name, 100);
			fscanf_s(fi, "So luong muon: %d\n", &bCards[count_borrow].bQuantity);

			for (int i = 0; i < bCards[count_borrow].bQuantity; ++i) {
				fscanf_s(fi, "ISBN: %s\n", bCards[count_borrow].bBook[i].ISBN, 100);
			}
			fscanf_s(fi, "Ngay muon: %d/%d/%d \n", &bCards[count_borrow].bDate.day,
				&bCards[count_borrow].bDate.month, &bCards[count_borrow].bDate.year);

			fscanf_s(fi, "Tinh trang: %[^\n]\n", bCards[count_borrow].status, 20);
			if (strcmp(bCards[count_borrow].status, "da tra") == 0) {
				fscanf_s(fi, "Ngay tra: %d/%d/%d \n", &bCards[count_borrow].rDate.day,
					&bCards[count_borrow].rDate.month, &bCards[count_borrow].rDate.year);
				fscanf_s(fi, "So sach bi mat: %d\n", &bCards[count_borrow].lostQuantity);

				for (int i = 0; i < bCards[count_borrow].lostQuantity; ++i) {
					fscanf_s(fi, "ISBN: %s\n", bCards[count_borrow].lBook[i].ISBN, 100);
				}
				fscanf_s(fi, "Tien phat: %lf\n\n", &bCards[count_borrow].fine);
			} else {
				bCards[count_borrow].fine = 0;
				fscanf_s(fi, "\n");
			}

			//printf("%f \n", bCards[count_borrow].fine);
			count_borrow++;
		}
		fclose(fi);
	}
}