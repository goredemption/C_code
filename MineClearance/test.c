#define _CRT_SECURE_NO_WARNINGS 1
#include "MineClearance.h"
void test1() {
	char display[row][column] = { 0 };
	int mine[row][column] = { 0 };
	int hint[row][column] = { 0 };
	intial(display, mine);
	IniHint(mine, hint);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d", mine[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d", hint[i][j]);
		}
		printf("\n");
	}
}
void test2() {
	char display[row][column] = { 0 };
	int mine[row][column] = { 0 };
	int hint[row][column] = { 0 };
	intial(display, mine);
	IniHint(mine, hint);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d", hint[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	play(display, mine, hint);
	print(display);
}
void test3() {
	char display[row][column] = { 0 };
	int mine[row][column] = { 0 };
	int hint[row][column] = { 0 };
	intial(display, mine);
	IniHint(mine, hint);
	while (1) {
		if (play(display, mine, hint) == 0) {
			break;
		}
		if (judge(display) == 1) {
			break;
		}
		print(display);
	}
}
int main() {
	int x = 0;
	char display[row][column] = { 0 };
	int mine[row][column] = { 0 };
	int hint[row][column] = { 0 };
	intial(display, mine);
	IniHint(mine, hint);
	do {
		menu();
		printf("Enter Your Choice:>");
		scanf("%d", &x);
		switch (x)
		{
		case 1:{
			print(display);
			while (1) {
				if (play(display, mine, hint) == 0) {
					break;
				}
				if (judge(display) == 1) {
					break;
				}
				print(display);
			}
			}
		case 0: {
			break;
		}
		default: {
			printf("Wrong Input! Try Again\n");
			break;
		}
		}
	} while (x);
	return 0;
}