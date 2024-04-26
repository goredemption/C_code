#define _CRT_SECURE_NO_WARNINGS 1
#include"MineClearance.h"
int main() {
	char PlayBoard[9][9] = { 0 };
	int MineBoard[9][9] = { 0 };
	do {
		int t = -1;
		menu();
		scanf("%d", &t);
		if (t == 0) {
			break;
		}
		if (t == 1) {
			initial(PlayBoard,MineBoard);
			game();
		}
		else {
			printf("Wrong Input!");
		}
	} while (1);
	return 0;
}