#pragma once
#include "init.h"

void sort_category(char category[][100], int quantity[100], int count_book) {
    for (int i = 0; i < count_book - 1; ++i) {
        for (int j = i + 1; j < count_book; ++j) {
            if (strcmp(category[j], category[i]) < 0) {
                char cTmp[MXN] = { 0 };
                strcpy(cTmp, category[i]);
                strcpy(category[i], category[j]);
                strcpy(category[j], cTmp);
                int iTmp = quantity[i];
                quantity[i] = quantity[j];
                quantity[j] = iTmp;
            }
        }
    }
}

void static_menu(Book books[], Reader readers[], BorrowCard bCards[], int count_book, int count_reader, int count_borrow) {
	while (1) {
		system("cls");
		show_logo();

        colorFont(9);
        gotoxy(10, 12);
        printf("( 1 ) Thong ke so luong sach");
        gotoxy(10, 14);
        printf("( 2 ) Thong ke so luong doc gia");
        gotoxy(10, 16);
        printf("( 3 ) Thong ke so luong sach dang duoc muon");
        gotoxy(10, 18);
        printf("( 4 ) Thong ke so luong doc gia bi tre han");
        gotoxy(10, 20);
        printf("( 5 ) Tro ve menu chinh");
        gotoxy(30, 22);
        printf("Nhap lua chon [ ]");
        colorFont(12);
        gotoxy(45, 22);

        int option;
        scanf_s("%d", &option);

        switch (option) {
            case 1:
                static_book(books, count_book);
;                break;
            
            case 2:
                static_reader(readers, count_reader);
                break;

            case 3:
                static_borrow_book(bCards, count_borrow);
                break;

            case 4:
                static_borrow_reader(bCards, count_borrow);
                break;

            case 5:
                return;
        }

        scanf_s("%*c");
	}
}

void static_book(Book books[], int count_book) {
    system("cls");

    show_logo();

    if (count_book == 0) {
        colorFont(9);
        gotoxy(10, 12);
        printf("Khong co sach nao trong thu vien");
        gotoxy(10, 13);
        printf("Nhan enter de quay lai!");
        scanf_s("%*c");
        return;
    }
    
    int total_book = 0, quantity[100] = { 0 };
    char category[100][100];
    
    for (int i = 0; i < count_book; ++i) {
        total_book += books[i].quantity;
        quantity[i] = books[i].quantity;
        strcpy(category[i], books[i].category);
    }

    gotoxy(10, 12);
    colorFont(9);
    printf("So luong sach co trong thu vien la: ");
    colorFont(12);
    printf("%d", total_book);

    sort_category(category, quantity, count_book);
    count_book++;
    strcpy(category[count_book], "pta-tmp");
    count_book--;

    colorFont(9);
    gotoxy(10, 13);
    printf("________________________________________________________");
    gotoxy(10, 14);
    printf("|%-40s| ", "The loai");
    printf("%-12s |", "So luong");
    gotoxy(10, 15);
    printf("|________________________________________|______________|");

    int line = 16;
    gotoxy(10, line);
    int cnt = 0;

    for (int i = 1; i <= count_book; ++i) {
        if (strcmp(category[i], category[i - 1]) == 0) {
            cnt += quantity[i - 1];
        }
        else {
            cnt += quantity[i - 1];
            gotoxy(10, line++);
            printf("|%-40s| ", category[i - 1]);
            printf("%-12d |", cnt);
            gotoxy(10, line++);
            printf("|________________________________________|______________|");
            cnt = 0;
        }
    }
    
    gotoxy(10, line + 2);
    printf("Nhan enter de quay lai!");
    scanf_s("%*c");
}

void static_reader(Reader readers[], int count_reader) {
    system("cls");

    show_logo();

    if (count_reader == 0) {
        colorFont(9);
        gotoxy(10, 12);
        printf("Khong co doc gia nao trong thu vien");
        gotoxy(10, 13);
        printf("Nhan enter de quay lai!");
        scanf_s("%*c");
        return;
    }

    int male = 0, female = 0;
    for (int i = 0; i < count_reader; ++i) {
        if (readers[i].gender == 1) {
            male++;
        }
    }
    female = count_reader - male;

    int line = 12;
    gotoxy(10, line++);
    colorFont(9);
    printf("Tong so doc gia trong thu vien la: ");
    colorFont(12);
    printf("%d", count_reader);

    colorFont(9);
    gotoxy(10, line++);
    printf("______________________________________________");
    gotoxy(10, line++);
    printf("|%-30s| ", "Gioi tinh");
    printf("%-12s |", "So luong");
    gotoxy(10, line++);
    printf("|______________________________|______________|");

    gotoxy(10, line++);
    printf("|%-30s| ", "Nam");
    printf("%-12d |", male);
    gotoxy(10, line++);
    printf("|______________________________|______________|");

    gotoxy(10, line++);
    printf("|%-30s| ", "Nu");
    printf("%-12d |", female);
    gotoxy(10, line++);
    printf("|______________________________|______________|");

    gotoxy(10, line++);
    printf("Nhan enter de quay lai!");
    scanf_s("%*c");
}

void static_borrow_book(BorrowCard bCards[], int count_borrow) {
    system("cls");
    show_logo();

    bool found = false;
    for (int i = 0; i < count_borrow; ++i) {
        if (strcmp("chua tra", bCards[i].status) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        colorFont(9);
        gotoxy(10, 12);
        printf("Khong co sach nao dang duoc muon");
        gotoxy(10, 13);
        printf("Nhan enter de quay lai!");
        scanf_s("%*c");
        return;
    }

    int line = 12;
    char book_name[100][100];
    int count_not_returned = 0, total_borrow = 0;
    for (int i = 0; i < count_borrow; ++i) {
        if (strcmp(bCards[i].status, "chua tra") == 0) {
            total_borrow += bCards[i].bQuantity;
            for (int j = 0; j < bCards[i].bQuantity; ++j) {
                strcpy(book_name[count_not_returned++], bCards[i].bBook[j].name);
            }
        }
    }

    gotoxy(10, line++);
    colorFont(9);
    printf("So luong sach dang duoc muon la: ");
    colorFont(12);
    printf("%d", total_borrow);

    sort_book(book_name, count_not_returned);
    count_not_returned++;
    strcpy(book_name[count_not_returned], "pta-tmp");
    count_not_returned--;
    gotoxy(10, line++);
    colorFont(9);
    printf("_________________________________________________________");
    gotoxy(10, line++);
    printf("|%-40s| ", "Ten sach");
    printf("%-12s |", "So luong muon");
    gotoxy(10, line++);                               
    printf("|________________________________________|_______________|");

    int cnt = 1;
    for (int i = 1; i <= count_not_returned; ++i) {
        if (strcmp(book_name[i], book_name[i - 1]) == 0) {
            ++cnt;
        }
        else {
            gotoxy(10, line++);
            printf("|%-40s| ", book_name[i - 1]);
            printf("%-13d |", cnt);
            gotoxy(10, line++);
            printf("|________________________________________|_______________|");
            cnt = 1;
        }
    }

    scanf_s("%*c");
}


void static_borrow_reader(BorrowCard bCards[], int count_borrow) {
    system("cls");
    show_logo();
    
    int line = 13;
    
    bool found = false;
    for (int i = 0; i < count_borrow; ++i) {
        if (strcmp("chua tra", bCards[i].status) == 0) {
            found = true;
            break;
        }
    }

    if (!found) {
        colorFont(9);
        gotoxy(10, 12);
        printf("Khong co sach nao dang duoc muon");
        gotoxy(10, 13);
        printf("Nhan enter de quay lai!");
        scanf_s("%*c");
        return;
    }

    gotoxy(10, line++);
    colorFont(9);
    printf("_____________________________________________________________________");
    gotoxy(10, line++);
    printf("|%-40s| ", "Ten doc gia");
    printf("%-12s | ", "So ngay tre");
    printf("%-10s |", "Ma phieu");
    gotoxy(10, line++);
    printf("|________________________________________|______________|____________|");
    Date today = get_today();
    
    int count_late = 0;
    for (int i = 0; i < count_borrow; ++i) {
        if (strcmp("chua tra", bCards[i].status) == 0) {
            if (distance(today, bCards[i].bDate) != 0) {
                count_late++;
                gotoxy(10, line++);
                printf("|%-40s| ", bCards[i].bReader.name);
                printf("%-12d | ", distance(today, bCards[i].bDate));
                printf("%-10s |", bCards[i].id);
                gotoxy(10, line++);
                printf("|________________________________________|______________|____________|");
            }
        }
    }
    gotoxy(10, 12);
    colorFont(9);
    printf("So luong doc gia bi tre han la: ");
    colorFont(12);
    printf("%d", count_late);

    colorFont(9);
    gotoxy(10, line + 2);
    printf("Nhan enter de quay lai!");
    scanf_s("%*c");
}

void sort_book(char book_name[][100], int count_not_return) {
    for (int i = 0; i < count_not_return - 1; ++i) {
        for (int j = i + 1; j < count_not_return; ++j) {
            if (strcmp(book_name[j], book_name[i]) < 0) {
                char cTmp[100] = { 0 };
                strcpy(cTmp, book_name[i]);
                strcpy(book_name[i], book_name[j]);
                strcpy(book_name[j], cTmp);
            }
        }
    }
}