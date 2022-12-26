#include "Windows.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "generator.h"
#include "single.h"
#include "save.h"
#include "open.h"
#include "bot.h"
using namespace std;

void menu1(int Item1)
{
    system("cls");
    printf("-----------Menu----------\n");
    printf("%s1 - Start\n", Item1 == 1 ? ">>" : " ");
    printf("%s2 - Exit\n", Item1 == 2 ? ">>" : " ");
}
void menu2(int Item2)
{
    system("cls");
    printf("-----------Labyrinth generation----------\n");
    printf("%s1 - Random generation maze\n", Item2 == 1 ? ">>" : " ");
    printf("%s2 - Generating from a file\n", Item2 == 2 ? ">>" : " ");
    printf("%s3 - Save in a file\n", Item2 == 3 ? ">>" : " ");
    printf("%s4 - Back\n", Item2 == 4 ? ">>" : " ");
}
void menu3(int Item3)
{
    system("cls");
    printf("-----------Labyrinth generation----------\n");
    printf("%s1 - Single mode\n", Item3 == 1 ? ">>" : " ");
    printf("%s2 - Agent\n", Item3 == 2 ? ">>" : " ");
    printf("%s4 - Back\n", Item3 == 3 ? ">>" : " ");
}
int main()
{
    system("color E0");//07
menu11:
    int Item1 = 1;
    int Last1 = 2;
    menu1(Item1);
    while (TRUE)
    {
        system("pause >> NUL");
        Sleep(300);
        if (GetAsyncKeyState(VK_UP))
        {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
            if (0 < Item1 - 1)
                Item1 = Item1 - 1;
            else
                Item1 = Last1;
            menu1(Item1);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            if (Item1 < Last1)
                Item1 = Item1 + 1;
            else
                Item1 = 1;
            menu1(Item1);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            menu1(Item1);
            switch (Item1)
            {
            case 1:
                Sleep(300);
                goto menu22;
                break;
            case 2:
                system("cls");
                exit(0);
            }
        }
    }
    return 0;
menu22:
    int Item2 = 1;
    int Last2 = 4;
    menu2(Item2);
    while (TRUE)
    {
        system("pause >> NUL");
        Sleep(300);
        if (GetAsyncKeyState(VK_UP))
        {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
            if (0 < Item2 - 1)
                Item2 = Item2 - 1;
            else
                Item2 = Last2;
            menu2(Item2);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            if (Item2 < Last2)
                Item2 = Item2 + 1;
            else
                Item2 = 1;
            menu2(Item2);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            switch (Item2)
            {
            case 1:
                generator();
                system("cls");
                Sleep(300);
                goto menu33;
            case 2:
                open();
                Sleep(300);
                goto menu33;
            case 3:
                save();
                MessageBox(0, L"Лабиринт успешно сохранён!\nФайл находится в директории программы", L"Warning!", MB_OK);
                Sleep(300);
                break;
            case 4:
                Sleep(300);
                goto menu11;
            }
        }
    }
    return 0;
menu33:
    int Item3 = 1;
    int Last3 = 3;
    menu3(Item3);
    while (TRUE)
    {
        system("pause >> NUL");
        Sleep(300);
        if (GetAsyncKeyState(VK_UP))
        {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
            if (0 < Item3 - 1)
                Item3 = Item3 - 1;
            else
                Item3 = Last3;
            menu3(Item3);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            if (Item3 < Last3)
                Item3 = Item3 + 1;
            else
                Item3 = 1;
            menu3(Item3);
        }
        if (GetAsyncKeyState(VK_RETURN))
        {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
            menu3(Item3);
            switch (Item3)
            {
            case 1:
                single();
                system("cls");
                Sleep(300);
                goto menu33;
            case 2:
                bot();
                system("cls");
                Sleep(300);
                goto menu33;
            case 3:
                Sleep(300);
                goto menu22;
            }
        }
    }
    return 0;
}
