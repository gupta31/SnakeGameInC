#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD p;
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void boundary()
{
    printf("%c", 218);  // 218 is '┌─'
    for (int i = 1; i < 167; i++)
    {
        printf("%c", 196); //196 is '──'
    }
    printf("%c", 191); //191 is '─┐'
    for (int i = 1; i < 43; i++)
    {
        gotoxy(167, i);
        printf("%c", 179); // 179 is '|'
        gotoxy(0, i);
        printf("%c", 179);
    }
    printf("\n%c", 192);
    for (int i = 1; i < 167; i++)
    {
        printf("%c", 196);
    }
    printf("%c", 217);
    gotoxy(0, 0);
}



int main()
{

    printf("- X --- X --- X --- X --- X --- X --- X --- X --- X --- SNAKES --- X --- X --- X --- X --- X --- X --- X --- X --- X -\n");
    printf("%cUse arrow keys to move the snake\n", 179);
    printf("%cPress any key to continue", 179);

    getch();
    system("cls");
    boundary();
    getchar();


    return 0;
}
