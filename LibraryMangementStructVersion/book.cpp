#include "init.h"


void update_book_data(Book books[], int count_book, const char path[]) {
    FILE* fo;
    fopen_s(&fo, path, "wt");

    if (fo != NULL) {
        for (int i = 0; i < count_book; ++i) {
            fprintf(fo, "Ten sach: %s\n", books[i].name);
            fprintf(fo, "Tac gia: %s\n", books[i].author);
            fprintf(fo, "NXB: %s\n", books[i].publicCompany);
            fprintf(fo, "ISBN: %s\n", books[i].ISBN);
            fprintf(fo, "Nam xuat ban: %d\n", books[i].publicYear);
            fprintf(fo, "The loai: %s\n", books[i].category);
            fprintf(fo, "Gia: %0.0f\n", books[i].price);
            fprintf(fo, "So luong: %d\n\n", books[i].quantity);
        }
        fclose(fo);
    }
}

void book_menu(Book books[], int& count_book) {
    while (1) {
        system("cls");
        show_logo();
        colorFont(9);
        gotoxy(10, 12);
        printf("( 1 ) Danh sach sach hien co");
        gotoxy(10, 14);
        printf("( 2 ) Them sach");
        gotoxy(10, 16);
        printf("( 3 ) Thay doi thong tin sach");

        gotoxy(50, 12);
        printf("( 4 ) Xoa sach");
        gotoxy(50, 14);
        printf("( 5 ) Tim sach");
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
                show_book(books, count_book);
                break;

            case 2:
                add_book(books, count_book);
                break;

            case 3:
                modify_book_information(books, count_book);
                break;

            case 4:
                delete_book(books, count_book);
                break;

            case 5:
                find_book(books, count_book);
                break;

            case 6:
                return;
        }
        scanf_s("%*c");
    }
}

void show_book(Book books[], int count_book) {
    while (1) {
        colorFont(9);
        system("cls");
        gotoxy(1, 1);
        printf("(1) Xem thong tin chi tiet cua sach\n");
        gotoxy(1, 2);
        printf("(2) Tro ve menu\n");
        gotoxy(1, 3);
        printf("    Nhap lua chon cua ban [ ] \n\n");
        printf("Danh sach sach trong thu vien \n");
        gotoxy(0, 6);

        printf("____________________________________________________________________________________________________________________________________________\n");
        printf("| %-15s| ", "ISBN");
        printf(" %-40s|", "TEN SACH");
        printf(" %-30s|", "TAC GIA");
        printf(" %-25s |", "THE LOAI");
        printf(" %-17s |", "GIA");
        gotoxy(0, 8);
        printf("|________________|__________________________________________|_______________________________|___________________________|___________________|\n");
       
        for (int i = 0; i < count_book; ++i) {
            printf("| %-15s| ", books[i].ISBN);
            printf(" %-40s|", books[i].name);
            printf(" %-30s|", books[i].author);
            printf(" %-25s |", books[i].category);
            printf(" %-17.0f |", books[i].price);
            printf("\n");
            printf("|________________|__________________________________________|_______________________________|___________________________|___________________|\n");
        }
        
        gotoxy(28, 3);
        int option;
        colorFont(12);

        scanf_s("%d", &option);
        switch (option) {
            case 1:
                show_book_detail(books, count_book);
                break;

            case 2:
                return;
        }
        colorFont(9);
        
        scanf_s("%*c");
    }
}

void show_book_detail(Book books[], int count_book) {
    system("cls");
    colorFont(9);
    gotoxy(3, 2);
    printf("Nhap ISBN cua sach can xem thong tin: ");
    colorFont(12);
    char _ISBN[20] = { 0 };
    scanf_s("%s", _ISBN, 20);

    bool found = false;
    for (int i = 0; i < count_book; ++i) {
        if (strcmp(_ISBN, books[i].ISBN) == 0) {
            found = true;

            gotoxy(3, 4);
            colorFont(9);
            printf("Ten sach: ");
            colorFont(14);
            printf("%s", books[i].name);

            gotoxy(40, 6);
            colorFont(9);
            printf("Tac gia: ");
            colorFont(14);
            printf("%s", books[i].author);

            gotoxy(3, 6);
            colorFont(9);
            printf("Nha xuat ban: ");
            colorFont(14);
            printf("%s", books[i].publicCompany);


            gotoxy(40, 8);
            colorFont(9);
            printf("Nam xuat ban: ");
            colorFont(14);
            printf("%d", books[i].publicYear);

            gotoxy(3, 8);
            colorFont(9);
            printf("The loai: ");
            colorFont(14);
            printf("%s", books[i].category);

            gotoxy(40, 10);
            colorFont(9);
            printf("Gia: ");
            colorFont(14);
            printf("%.0f", books[i].price);

            gotoxy(3, 10);
            colorFont(9);
            printf("So luong: ");
            colorFont(14);
            printf("%d", books[i].quantity);
        }
    }

    colorFont(12);
    if (!found) {
        gotoxy(3, 4);
        printf("Khong tim thay sach");
        gotoxy(3, 5);
        printf("Nhan enter de quay lai!");
    }
    else {
        gotoxy(3, 12);
        printf("Nhan enter de quay lai!");
    }

    scanf_s("%*c");
    colorFont(9);
    return;
}

void sort_book(Book books[], int count_book) {
    bool haveSwap = false;
    for (int i = 0; i < count_book - 1; ++i) {
        haveSwap = false;
        for (int j = 0; j < count_book - i - 1; j++) {
            if (strcmp(books[j].ISBN, books[j +1].ISBN) >  0) {
                std::swap(books[j], books[j + 1]);
                haveSwap = true;
            }
        }

        if (haveSwap == false) {
            break;
        }
    }
}

void add_book(Book books[], int& count_book) {
    char option;
    do {
        system("cls");
        colorFont(9);
        printf(" Them sach vao thu vien");
        gotoxy(1, 1);
        printf("Nhap ten sach: ");
        colorFont(12);
        scanf_s("%*c");
        scanf_s("%[^\n]", books[count_book].name, 100);

        colorFont(9);
        gotoxy(1, 2);
        scanf_s("%*c");
        printf("Nhap ten tac gia: ");
        colorFont(12);
        scanf_s("%[^\n]", books[count_book].author, 40);

        colorFont(9);
        gotoxy(1, 3);
        scanf_s("%*c");
        printf("Nhap ten nha xuat ban: ");
        colorFont(12);
        scanf_s("%[^\n]", books[count_book].publicCompany, 20);

        colorFont(9);
        gotoxy(1, 4);
        scanf_s("%*c");
        printf("Nhap ma ISBN: ");
        colorFont(12);
        scanf_s("%[^\n]", books[count_book].ISBN, 20);

        while (true) {
            bool check = false;
            for (int i = 0; i < count_book; ++i) {
                if (strcmp(books[count_book].ISBN, books[i].ISBN) == 0) {
                    check = true;
                    gotoxy(1, 4);
                    colorFont(9);
                    printf("ISBN bi trung lap, vui long nhap lai:                                ");
                    colorFont(12);
                    gotoxy(39, 4);
                    scanf_s("\n%[^\n]", books[count_book].ISBN, 20);
                }
            }

            if (!check) {
                break;
            }
        }

        colorFont(9);
        gotoxy(1, 5);
        printf("Nhap nam xuat ban: ");
        colorFont(12);
        scanf_s("%d", &books[count_book].publicYear);

        colorFont(9);
        gotoxy(1, 6);
        scanf_s("%*c");
        printf("Nhap the loai sach: ");
        colorFont(12);
        scanf_s("%[^\n]", books[count_book].category, 30);

        colorFont(9);
        gotoxy(1, 7);
        printf("Nhap gia sach: ");
        colorFont(12);
        scanf_s("%f", &books[count_book].price);

        colorFont(9);
        gotoxy(1, 8);
        printf("Nhap so luong: ");
        colorFont(12);
        scanf_s("%d", &books[count_book].quantity);

        count_book++;
        sort_book(books, count_book);
        update_book_data(books, count_book, "book_data.txt");

        printf("Ban co muon them sach khac khong? (y/n)");
        option = _getch();
    } while (option != 'n' && option != 'N');
}

void modify_book_information(Book books[], int count_book) {
    system("cls");
    show_logo();
    colorFont(9);
    gotoxy(10, 10);
    printf("Nhap ISBN cua sach can thay doi thong tin (gom 13 so): ");
    colorFont(12);

    char _ISBN[20] = { 0 };
    scanf_s("%s", _ISBN, 20);

    colorFont(9);
    int pos = 0;
    bool found = false;
    for (int i = 0; i < count_book; ++i) {
        if (strcmp(books[i].ISBN, _ISBN) == 0) {
            pos = i;
            found = true;
            printf("____________________________________________________________________________________________________________________________________________\n");
            printf("| %-15s| ", "ISBN");
            printf(" %-40s|", "TEN SACH");
            printf(" %-30s|", "TAC GIA");
            printf(" %-25s |", "THE LOAI");
            printf(" %-17s |", "GIA");
            printf("|________________|__________________________________________|_______________________________|___________________________|___________________|\n");

            printf("| %-15s| ", books[i].ISBN);
            printf(" %-40s|", books[i].name);
            printf(" %-30s|", books[i].author);
            printf(" %-25s |", books[i].category);
            printf(" %-17.0f |", books[i].price);
            printf("\n");
            printf("|________________|__________________________________________|_______________________________|___________________________|___________________|\n");
        }
    }

    gotoxy(1, 17);
    if (found) {
        printf("( 1 ) Thay doi ten sach");
        gotoxy(1, 18);
        printf("( 2 ) Thay doi tac gia");
        gotoxy(1, 19);
        printf("( 3 ) Thay doi NXB");
        gotoxy(1, 20);
        printf("( 4 ) Thay doi ISBN");
        gotoxy(1, 21);
        printf("( 5 ) Thay doi nam xuat ban");
        gotoxy(1, 22);
        printf("( 6 ) Thay doi the loai");
        gotoxy(1, 23);
        printf("( 7 ) Thay doi gia");
        gotoxy(1, 24);
        printf("( 8 ) Thay doi so luong");

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
                    printf("Ten sach cu: ");
                    colorFont(14);
                    printf("%s", books[pos].name);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap ten sach moi: ");
                    colorFont(14);
                    scanf_s("%*c");
                    scanf_s("%[^\n]", books[pos].name, 100);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 2:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Ten tac gia cu: ");
                    colorFont(14);
                    printf("%s", books[pos].author);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap ten tac gia moi: ");
                    colorFont(14);
                    scanf_s("%*c");
                    scanf_s("%[^\n]", books[pos].author, 40);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 3:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("NXB cu: ");
                    colorFont(14);
                    printf("%s", books[pos].publicCompany);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap ten NXB moi: ");
                    colorFont(14);
                    scanf_s("%*c");
                    scanf_s("%[^\n]", books[pos].publicCompany, 40);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 4:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("ISBN cu: ");
                    colorFont(14);
                    printf("%s", books[pos].ISBN);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap ISBN moi: ");
                    colorFont(14);
                    scanf_s("%s", books[pos].ISBN, 20);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;
               
                case 5:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nam xuat ban cu: ");
                    colorFont(14);
                    printf("%d", books[pos].publicYear);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap nam xuat ban moi: ");
                    colorFont(14);
                    scanf_s("%d", &books[pos].publicYear);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 6:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("The loai sach cu: ");
                    colorFont(14);
                    printf("%s", books[pos].category);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap the loai moi: ");
                    colorFont(14);
                    scanf_s("%*c");
                    scanf_s("%[^\n]", books[pos].category, 40);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 7:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Gia sach cu: ");
                    colorFont(14);
                    printf("%0.0f", books[pos].price);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap gia moi: ");
                    colorFont(14);
                    scanf_s("%f", &books[pos].price);

                    gotoxy(1, line++);
                    printf("Da thay doi thong tin");
                    scanf_s("%*c");
                    scanf_s("%*c");
                    break;

                case 8:
                    colorFont(9);
                    gotoxy(1, line++);
                    printf("So luong cu: ");
                    colorFont(14);
                    printf("%d", books[pos].quantity);

                    colorFont(9);
                    gotoxy(1, line++);
                    printf("Nhap so luong moi: ");
                    colorFont(14);
                    scanf_s("%d", &books[pos].quantity);

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

            update_book_data(books, count_book, "book_data.txt");
        }
    }

    scanf_s("%*c");
}

void delete_book(Book books[], int &count_book) {
    system("cls");
    show_logo();
    gotoxy(5, 12);
    char _ISBN[20] = { 0 };

    colorFont(9);
    printf("Nhap ISBN cua doc gia can xoa: ");
    colorFont(12);
    scanf_s("%s", _ISBN, 20);

    bool found = false;
    for (int i = 0; i < count_book; ++i) {
        if (strcmp(_ISBN, books[i].ISBN) == 0) {
            found = true;
            for (int k = i; k < count_book - 1; ++k) {
                books[k] = books[k + 1];
            }
        }
    }

    if (found) {
        count_book--;
    }
    
    gotoxy(5, 14);
    colorFont(12);
    if (!found) {
        printf("Khong tim thay sach");
    }
    else {
        printf("Da xoa sach khoi danh sach");
    }
    update_book_data(books, count_book, "book_data.txt");
    scanf_s("%*c");
}

void find_book(Book books[], int count_book) {
    while (1) {
        system("cls");
        show_logo();
        colorFont(9);
        gotoxy(10, 12);
        printf("( 1 ) Tim bang ISBN");
        gotoxy(10, 14);
        printf("( 2 ) Tim bang ten");
        gotoxy(10, 16);
        printf("( 3 ) Tro ve menu chinh");
        gotoxy(10, 18);
        printf("Nhap lua chon [ ]");
        colorFont(12);
        gotoxy(25, 18);

        int option;
        scanf_s("%d", &option);

        switch (option) {
            case 1:
                find_by_ISBN(books, count_book);
                break;

            case 2:
                find_by_name(books, count_book);
                break;

            case 3:
                return;
        }

        scanf_s("%*c");
    }
}

void find_by_ISBN(Book books[], int count_book) {
    system("cls");
    show_logo();

    colorFont(9);
    gotoxy(10, 12);
    printf("Nhap ISBN cua sach can tim: ");
    colorFont(12);
    char _ISBN[20] = { 0 };
    scanf_s("%s", _ISBN, 20);

    bool found = false;
    for (int i = 0; i < count_book; ++i) {
        if (strcmp(_ISBN, books[i].ISBN) == 0) {
            found = true;

            gotoxy(10, 14);
            colorFont(9);
            printf("Ten sach: ");
            colorFont(14);
            printf("%s", books[i].name);

            gotoxy(50, 16);
            colorFont(9);
            printf("Tac gia: ");
            colorFont(14);
            printf("%s", books[i].author);

            gotoxy(10, 16);
            colorFont(9);
            printf("Nha xuat ban: ");
            colorFont(14);
            printf("%s", books[i].publicCompany);


            gotoxy(50, 18);
            colorFont(9);
            printf("Nam xuat ban: ");
            colorFont(14);
            printf("%d", books[i].publicYear);

            gotoxy(10, 18);
            colorFont(9);
            printf("The loai: ");
            colorFont(14);
            printf("%s", books[i].category);

            gotoxy(50, 20);
            colorFont(9);
            printf("Gia: ");
            colorFont(14);
            printf("%.0f", books[i].price);

            gotoxy(10, 20);
            colorFont(9);
            printf("So luong: ");
            colorFont(14);
            printf("%d", books[i].quantity);
        }
    }

    colorFont(12);
    if (!found) {
        gotoxy(10, 14);
        printf("Khong tim thay sach");
        gotoxy(10, 15);
        printf("Nhan enter de quay lai!");
    }
    else {
        gotoxy(10, 22);
        printf("Nhan enter de quay lai!");
    }

    scanf_s("%*c");
    colorFont(9);
    return;
}

void find_by_name(Book books[], int count_book) {
    system("cls");
    show_logo();

    colorFont(9);
    gotoxy(10, 12);
    printf("Nhap ten sach can tim: ");
    colorFont(12);
    char _name[100] = { 0 };
    scanf_s("%*c");
    scanf_s("%[^\n]", _name, 100);
    to_lower(_name);

    bool found = false;
    for (int i = 0; i < count_book; ++i) {
        char tmp_name[100] = { 0 };
        strcpy(tmp_name, books[i].name);
        to_lower(tmp_name);
        if (strcmp(_name, tmp_name) == 0) {
            found = true;

            gotoxy(10, 14);
            colorFont(9);
            printf("Ten sach: ");
            colorFont(14);
            printf("%s", books[i].name);

            gotoxy(50, 16);
            colorFont(9);
            printf("Tac gia: ");
            colorFont(14);
            printf("%s", books[i].author);

            gotoxy(10, 16);
            colorFont(9);
            printf("Nha xuat ban: ");
            colorFont(14);
            printf("%s", books[i].publicCompany);


            gotoxy(50, 18);
            colorFont(9);
            printf("Nam xuat ban: ");
            colorFont(14);
            printf("%d", books[i].publicYear);

            gotoxy(10, 18);
            colorFont(9);
            printf("The loai: ");
            colorFont(14);
            printf("%s", books[i].category);

            gotoxy(50, 20);
            colorFont(9);
            printf("Gia: ");
            colorFont(14);
            printf("%.0f", books[i].price);

            gotoxy(10, 20);
            colorFont(9);
            printf("So luong: ");
            colorFont(14);
            printf("%d", books[i].quantity);
        }
    }

    colorFont(12);
    if (!found) {
        gotoxy(10, 14);
        printf("Khong tim thay sach");
        gotoxy(10, 15);
        printf("Nhan enter de quay lai!");
    }
    else {
        gotoxy(10, 22);
        printf("Nhan enter de quay lai!");
    }

    scanf_s("%*c");
    colorFont(9);
    return;
}