#define _CRT_SECURE_NO_WARNINGS 1
#include"MineClearance.h"
void menu() {
	printf("********************************\n");
	printf("******    MineClearance   ******\n");
	printf("******    1.play          ******\n");
	printf("******    0.exit          ******\n");
	printf("********************************\n");
}
void initial(char PlayBoard[][column], int MineBoard[][column]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			MineBoard[i][j] = rand()%2;
			PlayBoard[i][j] = '#';
		}
	}
}

void display(char PlayBoard[][column]) {
	for (int i = 0; i < row; i++) {
		printf("%s\n", PlayBoard[i]);
	}
}

void reveal(int MineBoard[][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", MineBoard[i][j]);
		}
		printf("\n");
	}
}

void adjust(char PlayBoard[][column], int MineBoard[][column], int x, int y) {
	PlayBoard[x][y] = ' ';
	//uppercheck
	if (x != 0) {
		if (MineBoard[x - 1][y] == 0) {
			adjust(PlayBoard, MineBoard, x - 1, y);
		}
	}
	//lowercheck
	if (x != row - 1) {
		if (MineBoard[x + 1][y] == 0) {
			adjust(PlayBoard, MineBoard, x + 1, y);
		}
	}
	//rightcheck
	if (y != column - 1) {
		if (MineBoard[x][y + 1] == 0) {
			adjust(PlayBoard, MineBoard, x , y+1);
		}
	}
	//leftcheck
	if (y != 0) {
		if (MineBoard[x][y - 1] == 0) {
			adjust(PlayBoard, MineBoard, x, y - 1);
		}
	}
}
int judge(char PlayBoard[][column], int MineBoard[][column], int x, int y) {
	if (MineBoard[x][y] == 1) {
		printf("Game Over!You been blow off!");
		reveal(MineBoard);
		return 0;
	}
	else {
		adjust(PlayBoard, MineBoard,x, y);
		return 1;
	}
}
void game(char PlayBoard[][column], int MineBoard[][column]) {
	int x = 0, y = 0;
	while (1) {
		display(PlayBoard);
		printf("Enter Coordinate:>");
		scanf("%d %d", &x, &y);
		printf("\n");
		if (judge(PlayBoard,MineBoard,x,y) == 0) {
			break;
		}
	}
}