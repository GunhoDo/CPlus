#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termio.h>
void print(char a[][4]);
void rand_sort(char a[][4]);
int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}
int main(int argc, char* argv[])
{
    char a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 32}
    };
    int b, c, d;
    if (atoi(argv[1]) == 1) {
        print(a);
    }
    else if (atoi(argv[1]) == 2)
    {
        rand_sort(a);
        print(a);
        c = getch();
        printf("%c\n", c);
        if (c == 105) {
            for (int i = 0; i < 15; i++)
                if (a[i / 4][i % 4] == 32)
                    b = i;
            c = b - 4;
            d = a[b / 4][b % 4];
            a[b / 4][b % 4] = a[c / 4][c % 4];
            a[c / 4][c % 4] = d;
            print(a);
        }
        else if (c == 106) {

        }
        else if (c == 107) {

        }
        else {

        }

    }
}
void print(char a[][4])
{
    for (int i = 0; i < 15; i++) {
        if (a[i / 4][i % 4] == 32) {
            printf("%4c", a[i / 4][i % 4]);
            if (i % 4 == 0)
                printf("\n");
        }
        else {
            printf("%4d", a[i / 4][i % 4]);
            if (i % 4 == 3)
                printf("\n");
        }
    }
    printf("\n");
}
void rand_sort(char a[][4])
{
    int tmp, r1, r2;
    srand(time(NULL));
    for (int i = 0; i < 14; i++) {
        r1 = rand() % 14;
        r2 = rand() % 14;
        tmp = a[r1 / 4][r1 % 4];
        a[r1 / 4][r1 % 4] = a[r2 / 4][r2 % 4];
        a[r2 / 4][r2 % 4] = tmp;
    }
}
