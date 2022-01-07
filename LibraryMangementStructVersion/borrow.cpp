#include "init.h"


void update_borrow_book(BorrowCard bCards[], int count_borrow, const char path[]) {
    FILE* fo;
    fopen_s(&fo, path, "w");

    if (fo != NULL) {
        for (int i = 0; i < count_borrow; ++i) {
            fprintf(fo, "Ma phieu: %s\n", bCards[i].id);
            fprintf(fo, "Ma doc gia: %s\n", bCards[i].bReader.id);
            fprintf(fo, "Ten doc gia: %s\n", bCards[i].bReader.name);
            fprintf(fo, "So luong muon: %d\n", bCards[i].bQuantity);

            for (int j = 0; j < bCards[i].bQuantity; ++j) {
                fprintf(fo, "ISBN: %s\n", bCards[i].bBook[j].ISBN);
            }
            fprintf(fo, "Ngay muon: %d/%d/%d \n", bCards[i].bDate.day,
                bCards[i].bDate.month, bCards[i].bDate.year);

            fprintf(fo, "Tinh trang: %s\n", bCards[i].status);
            if (strcmp(bCards[i].status, "da tra") == 0) {
                fprintf(fo, "Ngay tra: %d/%d/%d \n", bCards[i].rDate.day,
                    bCards[i].rDate.month, bCards[i].rDate.year);
                fprintf(fo, "So sach bi mat: %d\n", bCards[i].lostQuantity);

                for (int i = 0; i < bCards[i].lostQuantity; ++i) {
                    fprintf(fo, "ISBN: %s\n", bCards[i].lBook[i].ISBN);
                }
                fprintf(fo, "Tien phat: %0.0lf\n\n", bCards[i].fine);
            }
            else {
                fprintf(fo, "\n");
            }
        }
        fclose(fo);
    }
}

// Borrow a book
void borrow_book(BorrowCard bCards[], Reader readers[], Book books[], int& count_borrow, int count_reader, int count_book) {
    system("cls");
    char _readerId[20] = { 0 };
    gotoxy(3, 2);
    colorFont(9);
    printf("Nhap ma doc gia muon muon sach: ");
    colorFont(12);
    scanf_s("%s", _readerId, 20);
    colorFont(9);

    bool foundReader = false;
    for (int i = 0; i < count_reader; ++i) {
        if (strcmp(readers[i].id, _readerId) == 0) {
            foundReader = true;
            bCards[count_borrow].bReader = readers[i];
            gotoxy(3, 3);
            printf("__________________________________________________________________________");

            for (int i = 4; i <= 13; ++i) {
                gotoxy(2, i);
                printf("|");
            }
            for (int i = 4; i <= 13; ++i) {
                gotoxy(77, i);
                printf("|");
            }
            gotoxy(3, 4);
            colorFont(9);
            printf("Ten doc gia: ");
            colorFont(12);
            printf("%s", readers[i].name);

            gotoxy(40, 4);
            colorFont(9);
            printf("ID: ");
            colorFont(12);
            printf("%s", readers[i].id);

            gotoxy(3, 6);
            colorFont(9);
            printf("CMND: ");
            colorFont(12);
            printf("%s", readers[i].idCard);

            gotoxy(40, 6);
            colorFont(9);
            printf("Ngay sinh: ");
            colorFont(12);
            printf("%02d/%02d/%04d", readers[i].birthday.day, readers[i].birthday.month, readers[i].birthday.year);

            gotoxy(3, 8);
            colorFont(9);
            printf("Gioi tinh: ");
            colorFont(12);
            if (readers[i].gender == 1) {
                printf("Nam");
            } else {
                printf("Nu");
            }

            gotoxy(40, 8);
            colorFont(9);
            printf("Email: ");
            colorFont(12);
            printf("%s", readers[i].email);

            gotoxy(3, 10);
            colorFont(9);
            printf("Ngay lap the: ");
            colorFont(12);
            printf("%d/%d/%d", readers[i].registerDay.day, readers[i].registerDay.month, readers[i].registerDay.year);

            gotoxy(40, 10);
            colorFont(9);
            printf("Ngay het han the: ");
            colorFont(12);
            printf("%02d/%02d/%04d", readers[i].registerDay.day, readers[i].registerDay.month, readers[i].registerDay.year + 4);

            gotoxy(3, 12);
            colorFont(9);
            printf("Dia chi: ");
            colorFont(12);
            printf("%s", readers[i].address);
            gotoxy(3, 13);
            colorFont(9);
            printf("__________________________________________________________________________");

            strcpy(bCards[count_borrow].bReader.id, readers[i].id);
        }
    }

    if (!foundReader) {
        system("cls");
        gotoxy(4, 5);
        colorFont(12);
        printf("Khong tim thay doc gia co ma nhu tren");
        scanf_s("%*c");
        return;
    }

    colorFont(9);
    gotoxy(3, 15);
    printf("Nhap so luong sach can muon: ");
    colorFont(12);
    scanf_s("%d", &bCards[count_borrow].bQuantity);
    colorFont(9);
    int cnt = 16;

    for (int i = 0; i < bCards[count_borrow].bQuantity; ++i) {
        gotoxy(3, cnt);
        char _ISBN[20] = { 0 };
        colorFont(9);
        printf("Nhap vao ISBN cua sach thu %d: ", i + 1);
        colorFont(12);
        scanf_s("%s", _ISBN, 20);

        colorFont(9);
        bool foundISBN = false;
        for (int j = 0; j < count_book; ++j) {
            gotoxy(51, cnt);
            if (strcmp(_ISBN, books[j].ISBN) == 0) {
                foundISBN = true;
                bCards[count_borrow].bBook[i] = books[j];
                //strcpy(bCards[count_borrow].bBook[i].ISBN, books[j].ISBN);
                colorFont(14);
                printf("%s", books[j].name);
                books[j].quantity--;
                colorFont(9);
            }
        }
            
        if (!foundISBN) {
            --i;
            gotoxy(40, 15);
            colorFont(12);
            printf("Khong tim thay sach, nhap lai ISBN!");
            colorFont(9);
            gotoxy(32, cnt);
            printf("                                 ");
            gotoxy(33, cnt);
        }
        else {
            gotoxy(40, 15);
            printf("                                          ");
            ++cnt;
        }
    }

    gotoxy(3, cnt++);
    colorFont(9);
    printf("Nhap ngay muon sach (dd/mm/yyyy): ");
    colorFont(14);
    scanf_s("%02d/%02d/%04d", &bCards[count_borrow].bDate.day, &bCards[count_borrow].bDate.month,
                        &bCards[count_borrow].bDate.year);
    gotoxy(3, cnt++);
    Date curr_date = bCards[count_borrow].bDate;

    for (int i = 1; i <= 7; ++i) {
        next_day(curr_date);
    }

    colorFont(9);
    printf("Ngay du kien ban phai tra sach: ");
    colorFont(14);
    printf("%02d/%02d/%04d", curr_date.day, curr_date.month, curr_date.year);
    colorFont(9);
    
    gotoxy(3, cnt++);
    char cardId[20] = "HCMUS-";
    char num_char[8];
    sprintf(num_char, "%d", count_borrow + 1);
    strcat(cardId, num_char);

    printf("Ma phieu muon cua ban la: ");
    colorFont(14);
    printf("%s", cardId);
    colorFont(9);
    strcpy(bCards[count_borrow].id, cardId);
    bCards[count_borrow].fine = 0;
    strcpy(bCards[count_borrow].status, "chua tra");
    ++count_borrow;
    update_borrow_book(bCards, count_borrow, "borrow_book_data.txt");
    update_book_data(books, count_book, "book_data.txt");
    scanf_s("%*c");
}


void return_book(BorrowCard bCards[], Book books[], int& count_borrow, int count_book) {
    system("cls");
    gotoxy(3, 1);
    colorFont(9);
    printf("Nhap ma phieu: ");
    colorFont(12);
    char cardId[20] = { 0 };
    scanf_s("%s", cardId, 20);
    int pos = 0;
    bool found = false;
    for (int i = 0; i < count_borrow; ++i) {
        if (strcmp(cardId, bCards[i].id) == 0) {
            found = true, pos = i;
            gotoxy(40, 1);
            colorFont(9);
            printf("Trang thai phieu: ");
            colorFont(14);
            printf(bCards[i].status);

            gotoxy(3, 3);
            colorFont(9);
            printf("Ten doc gia: ");
            colorFont(12);
            printf("%s", bCards[i].bReader.name);

            gotoxy(40, 3);
            colorFont(9);
            printf("ID: ");
            colorFont(12);
            printf("%s \n", bCards[i].bReader.id);
        }
    }
    
    if (!found) {
        gotoxy(3, 5);
        printf("Khong tim thay ma phieu!");
        gotoxy(3, 6);
        printf("Nhan enter de quay lai");
        scanf_s("%*c");
        return;
    }

    colorFont(9);
    gotoxy(3, 5);
    printf("Cac sach da muon");
    gotoxy(3, 6);
    printf("________________________________________________________________\n");
    gotoxy(3, 7);
    printf("|%-20s| ", "ISBN");
    printf("%-40s |", "Ten sach");
    gotoxy(3, 8);
    printf("|____________________|__________________________________________|\n");

    int line = 9;
    for (int i = 0; i < bCards[pos].bQuantity; ++i) {
        gotoxy(3, line++);
        printf("|%-20s| ", bCards[pos].bBook[i].ISBN);
        for (int j = 0; j < count_book; ++j) {
            if (strcmp(bCards[pos].bBook[i].ISBN, books[j].ISBN) == 0) {
                printf("%-40s |", books[j].name);
                if (strcmp(bCards[pos].status, "chua tra") == 0) {
                    books[j].quantity++;
                }
            }
        }
        gotoxy(3, line++);
        printf("|____________________|__________________________________________|\n");
    }

    line++;
    if (found) {
        if (strcmp(bCards[pos].status, "da tra") == 0) {
            gotoxy(3, line++);
            colorFont(9);
            printf("Ngay muon sach: ");
            colorFont(14);
            printf("%02d/%02d/%04d", bCards[pos].bDate.day, bCards[pos].bDate.month, bCards[pos].bDate.year);

            Date date = bCards[pos].bDate;
            for (int i = 1; i <= 7; ++i) {
                next_day(date);
            }
            gotoxy(3, line++);
            colorFont(9);
            printf("Ngay tra du kien: ");
            colorFont(14);
            printf("%02d/%02d/%04d", date.day, date.month, date.year);

            gotoxy(3, line++);
            colorFont(9);
            printf("Ngay tra thuc te: ");
            colorFont(14);
            printf("%02d/%02d/%04d", bCards[pos].rDate.day, bCards[pos].rDate.month, bCards[pos].rDate.year);

            line++;
            gotoxy(3, line++);
            colorFont(9);
            printf("So luong sach bi mat: ");
            colorFont(14);
            printf("%d", bCards[pos].lostQuantity);
            if (bCards[pos].lostQuantity != 0) {
                colorFont(9);
                gotoxy(3, line++);
                printf("Cac sach bi mat");
                gotoxy(3, line++);
                printf("________________________________________________________________________________\n");
                gotoxy(3, line++);
                printf("|%-20s| ", "ISBN");
                printf("%-40s |", "Ten sach");
                printf("%-13s |", "Gia");
                gotoxy(3, line++);
                printf("|____________________|__________________________________________|______________|\n");

                for (int i = 0; i < bCards[pos].lostQuantity; ++i) {
                    gotoxy(3, line++);
                    printf("|%-20s| ", bCards[pos].lBook[i].ISBN);
                    for (int j = 0; j < count_book; ++j) {
                        if (strcmp(bCards[pos].lBook[i].ISBN, books[j].ISBN) == 0) {
                            printf("%-40s |", books[j].name);
                            printf("%-13.0lf |", books[j].price);
                        }
                    }
                    gotoxy(3, line++);
                    printf("|____________________|__________________________________________|______________|\n");
                }
            }

            line++;
            gotoxy(3, line++);
            colorFont(9);
            printf("So tien nop phat la: ");
            colorFont(14);
            printf("%0.0lf", bCards[pos].fine);
        } else {
            gotoxy(3, line++);
            colorFont(9);
            printf("Ngay muon sach: ");
            colorFont(14);
            printf("%02d/%02d/%02d", bCards[pos].bDate.day, bCards[pos].bDate.month, bCards[pos].bDate.year);

            Date date = bCards[pos].bDate;
            for (int i = 1; i <= 7; ++i) {
                next_day(date);
            }
            gotoxy(3, line++);
            colorFont(9);
            printf("Ngay tra du kien: ");
            colorFont(14);
            printf("%02d/%02d/%04d", date.day, date.month, date.year);

            gotoxy(3, line++);
            colorFont(9);
            printf("Nhap ngay tra thuc te (dd/mm/yyy): ");
            colorFont(14);
            scanf_s("%d/%d/%d", &bCards[pos].rDate.day, &bCards[pos].rDate.month, &bCards[pos].rDate.year);

            line++;
            gotoxy(3, line++);
            colorFont(9);
            printf("Nhap so luong sach bi mat: ");
            colorFont(14);
            scanf_s("%d", &bCards[pos].lostQuantity);

            for (int i = 0; i < bCards[pos].lostQuantity; ++i) {
                gotoxy(3, line);
                colorFont(9);
                printf("Nhap ISBN cua sach bi mat thu %d: ", i + 1);
                colorFont(12);
                scanf_s("%s", bCards[pos].lBook[i].ISBN, 20);

                bool check = false;
                while (1) {
                    for (int j = 0; j < bCards[pos].bQuantity; ++j) {
                        if (strcmp(bCards[pos].bBook[j].ISBN, bCards[pos].lBook[i].ISBN) == 0) {
                            check = true;
                        }
                    }

                    if (check) {
                        break;
                    }
                    else {
                        gotoxy(3, line);
                        colorFont(9);
                        printf("Nhap lai ISBN, ban dang khong muon sach nay:                            ");
                        colorFont(12);
                        gotoxy(int(strlen("Nhap lai ISBN, ban dang khong muon sach nay:")) + 4, line);
                        scanf_s("%s", bCards[pos].lBook[i].ISBN, 20);
                    }
                }
                line++;
            }
            line++;

            if (bCards[pos].lostQuantity != 0) {
                colorFont(9);
                gotoxy(3, line++);
                printf("Cac sach bi mat");
                gotoxy(3, line++);
                printf("________________________________________________________________________________\n");
                gotoxy(3, line++);
                printf("|%-20s| ", "ISBN");
                printf("%-40s |", "Ten sach");
                printf("%-13s |", "Gia");
                gotoxy(3, line++);
                printf("|____________________|__________________________________________|______________|\n");

                for (int i = 0; i < bCards[pos].lostQuantity; ++i) {
                    gotoxy(3, line++);
                    printf("|%-20s| ", bCards[pos].lBook[i].ISBN);
                    for (int j = 0; j < count_book; ++j) {
                        if (strcmp(bCards[pos].lBook[i].ISBN, books[j].ISBN) == 0) {
                            printf("%-40s |", books[j].name);
                            printf("%-13.0lf |", books[j].price);
                            books[j].quantity--;
                            bCards[pos].fine += (2.0 * books[j].price);
                        }
                    }
                    gotoxy(3, line++);
                    printf("|____________________|__________________________________________|______________|\n");
                }
            }

            bCards[pos].fine += (5000 * 1.0 * distance(bCards[pos].rDate, date));

            line++;
            gotoxy(3, line++);
            colorFont(9);
            printf("So tien nop phat la: ");
            colorFont(14);
            printf("%0.0lf", bCards[pos].fine);
            strcpy(bCards[pos].status, "da tra");
            update_book_data(books, count_book, "book_data.txt");
        }
    }
    update_borrow_book(bCards, count_borrow, "borrow_book_data.txt");
    scanf_s("%*c");
}

