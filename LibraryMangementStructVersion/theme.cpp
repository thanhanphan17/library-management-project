#include "init.h"

// Resize the console windows with width and height
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Colorize the font, n is color code
void colorFont(int n) {
    HANDLE color;
    color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, n);
}

// Set cursor pointer to the position x asis and y asis in the console
void gotoxy(short x, short y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Show the logo "Library" draw by ascii character
void show_logo() {
    resizeConsole(1050, 600);
    printf("\n");
    colorFont(6);
    printf("                ___      _   ___  \n");
    printf("               || |     (_) || |                                 \n");
    printf("               || |      _  || |__    _ __     __ __   _____   _   __    \n");
    colorFont(11);
    printf("               || |     | | || '_ \\  || '__|  / _` || || '__| | | | ||  \n");
    printf("               || |____ | | || |_) | || |    | (_| || || |    | |_| ||   \n");
    colorFont(13);
    printf("               ||______||_| ||_.__/  ||_|     \\__,_|| ||_|     \\__, || \n");
    printf("                                                                __/ ||   \n");
    printf("                                                               |___//    \n");
    colorFont(14);
    printf("\n                         Ho Chi Minh University of Science\n");
}


void show_main_menu() {
    colorFont(9);
    gotoxy(10, 12);
    printf("( 1 ) Quan ly doc gia");
    gotoxy(10, 14);
    printf("( 2 ) Quan ly sach");
    gotoxy(10, 16);
    printf("( 3 ) Lap phieu muon sach");

    gotoxy(50, 12);
    printf("( 4 ) Lap phieu tra sach");
    gotoxy(50, 14);
    printf("( 5 ) Thong ke");
    gotoxy(50, 16);
    printf("( 6 ) Thong tin tac gia");

    gotoxy(30, 18);
    printf("Nhap lua chon [ ]");
    colorFont(12);
    gotoxy(45, 18);
}
