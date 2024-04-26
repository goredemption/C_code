#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define row 9
#define column 9
void menu();
void initial(char PlayBoard[][column], int MineBoard[][column]);
void display(char PlayBoard[][column]); 
void reveal(int MineBoard[][column]);
void adjust(char PlayBoard[][column], int MineBoard[][column], int x, int y);
int judge(char PlayBoard[][column], int MineBoard[][column], int x, int y);
void game(char PlayBoard[][column], int MineBoard[][column]);