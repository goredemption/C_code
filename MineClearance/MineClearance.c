#define _CRT_SECURE_NO_WARNINGS 1
#include "MineClearance.h"

int judge(char display[][column]) {
	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (display[i][j] == '*') {
				cnt++;
			}
		}
	}
	if (cnt == mines) {
		printf("You Win!\n");
		return 1;
	}
	else {
		return 0;
	}
}

void menu() {
	printf("**************************\n");
	printf("1.play 0.exit\n");
	printf("**************************\n");
}
void intial(char display[][column], int mine[][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			display[i][j] = '*';
		}
	}
	srand(time(NULL));
	for (int i = 0; i < mines; i++) {
		int x = rand() % column;
		int y = rand() % row;
		mine[y][x] = 1;
	}
}

void print(char display[][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%c", display[i][j]);
		}
		printf("\n");
	}
}

void reveal(char display[][column],int mine[][column], int hint[][column], int x, int y) {
	display[x][y] = hint[x][y] + 48;
	//uppercheck
	if (x != 0&&mine[x-1][y]!=1) {
		display[x - 1][y] = hint[x - 1][y] + 48;
	}
	//lowercheck
	if (x != row - 1&& mine[x + 1][y]!=1) {
		display[x + 1][y] = hint[x + 1][y] + 48;
	}
	//leftcheck
	if (y != 0&& mine[x][y - 1]!=1) {
		display[x][y - 1] = hint[x][y - 1] + 48;
	}
	//rightcheck
	if (y != column - 1&& mine[x][y + 1]!=1) {
		display[x][y + 1] = hint[x][y + 1] + 48;
	}
	//upperleft
	if (x != 0 && y != 0&& mine[x - 1][y - 1]!=1) {
		display[x - 1][y - 1] = hint[x - 1][y - 1] + 48;
	}
	//upperright
	if (x != 0 && y != column - 1&& mine[x - 1][y + 1]!=1) {
		display[x - 1][y + 1] = hint[x - 1][y + 1] + 48;
	}
	//lowerleft
	if (x != row - 1 && y != 0&& mine[x + 1][y - 1]!=1) {
		display[x + 1][y - 1] = hint[x + 1][y - 1] + 48;
	}
	//lowerright
	if (x != row - 1 && y != column - 1&& mine[x + 1][y + 1]!=1) {
		display[x + 1][y + 1] = hint[x + 1][y + 1] + 48;
	}
}

int play(char display[][column], int mine[][column],int hint[][column]) {
	printf("Enter Coordinate You Choose(Row then Column):>");
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	if (mine[x][y] == 1) {
		printf("You were blow off!\n");
		return 0;
	}
	else {
		reveal(display, mine,hint, x, y);
		return 1;
	}
}

void IniHint(int mine[][column],int hint[][column]) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			int cnt = 0;
			//uppercheck
			if (i != 0) {
				if (mine[i - 1][j] == 1) {
					cnt++;
				}
			}
			//lowercheck
			if (i != row - 1) {
				if (mine[i + 1][j] == 1) {
					cnt++;
				}
			}
			//leftcheck
			if (j != 0) {
				if (mine[i][j - 1] == 1) {
					cnt++;
				}
			}
			//rightcheck
			if (j != column - 1) {
				if (mine[i][j + 1] == 1) {
					cnt++;
				}
			}
			//upperleft
			if (i != 0 && j != 0) {
				if (mine[i - 1][j - 1] == 1) {
					cnt++;
				}
			}
			//upperright
			if (i != 0 && j != column - 1) {
				if (mine[i - 1][j + 1] == 1) {
					cnt++;
				}
			}
			//lowerleft
			if (i != row - 1 && j != 0) {
				if (mine[i + 1][j - 1] == 1) {
					cnt++;
				}
			}
			//lowerright
			if (i != row - 1 && j != column - 1) {
				if (mine[i + 1][j + 1] == 1) {
					cnt++;
				}
			}
			hint[i][j] = cnt;
		}
	}
}