#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define row 3
#define column 3
#define mines 1
void intial(char display[][column], int mine[][column]);
void print(char display[][column]);
void IniHint(int mine[][column], int hint[][column]);
int play(char display[][column], int mine[][column],int hint[][column]);
int judge(char display[][column]);
void menu();