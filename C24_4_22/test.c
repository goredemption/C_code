#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int check(char** grid, int gridRowLen, int* gridColLen, int i, int j) {
//    grid[i][j] = '0';
//    int r = 0;
//    //upper check
//    if (i != 0) {
//        if (grid[i - 1][j] == '1') {
//            check(grid, gridRowLen, gridColLen, i - 1, j);
//            r++;
//        }
//    }
//    //lower check
//    if (i != gridRowLen - 1) {
//        if (grid[i + 1][j] == '1') {
//            check(grid, gridRowLen, gridColLen, i + 1, j);
//            r++;
//        }
//    }
//    //right check
//    if (j != (*gridColLen) - 1) {
//        if (grid[i][j + 1] == '1') {
//            check(grid, gridRowLen, gridColLen, i, j + 1);
//            r++;
//        }
//    }
//    //left check
//    if (j != 0) {
//        if (grid[i][j - 1] == '1') {
//            check(grid, gridRowLen, gridColLen, i, j - 1);
//            r++;
//        }
//    }
//    if (r > 0) {
//        return 1;
//    }
//    return 0;
//}
//int main() {
//    char grid[5][6] = { 0 };
//    int gridRowLen = 5;
//    int c = 5;
//    int* gridColLen = &c;
//    for (int i = 0; i < 5; i++) {
//        scanf("%s", grid[i]);
//    }
//    int cnt = 0;
//    for (int i = 0; i < gridRowLen; i++) {
//        for (int j = 0; j < *gridColLen; j++) {
//            if (grid[i][j] == '1') {
//                if(check(grid, gridRowLen, gridColLen, i, j)) {
//                    cnt++;
//                }
//            }
//        }
//    }
//    printf("%d", cnt);
//    return 0;
//}
#include<string.h>
int main() {
	char str[10] = { 0 };
	int n = 0;
	scanf("%d", &n);
	scanf("%s", str);
	n = n % strlen(str);
	for (int i = n; i < strlen(str); i++) {
		printf("%c", str[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%c", str[i]);
	}
	return 0;
}