#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	int x = 0;
//	for (a = 1; a <= 5; a++) {
//		for ( b = 1; b <= 5; b++) {
//			for (c = 1; c <= 5; c++) {
//				for (d = 1; d <= 5; d++) {
//					for (e = 1; e <= 5; e++) {
//						if (((b == 2) && (a != 3)) || ((b != 2) && (a == 3))) {
//							if (((b == 2) && (e != 4)) || ((b != 2) && (e == 4))) {
//								if (((c == 1) && (d != 2)) || ((c != 1) && (d == 2))) {
//									if (((c == 5) && (d != 3)) || ((c != 5) && (d == 3))) {
//										if (((e == 4) && (a != 1)) || ((e != 4) && (a == 1))) {
//											x = a ^ b ^c^d^e^1^2^3^4^5 ;
//											if (x == 0&&b!=d&&b!=e) {
//												printf("Competition Rank:>A%d B%d C%d D%d E%d\n", a, b, c, d, e);
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main() {
//	int murder[4] = { 0 };
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			murder[j] = 0;
//		}
//		murder[i] = 1;
//		if ((murder[0] == 0) && (murder[2] == 1) && (murder[3] == 1)) {
//			for (int k = 0; k < 4; k++) {
//				if (murder[k] == 1) {
//					if (k == 0) {
//						printf("MurderIs:>A");
//					}
//					if (k == 1) {
//						printf("MurderIs:>B");
//					}
//					if (k == 2) {
//						printf("MurderIs:>C");
//					}
//					if (k == 3) {
//						printf("MurderIs:>D");
//					}
//				}
//			}
//		}
//		if ((murder[0] == 0) && (murder[2] == 1) && (murder[3] != 1)) {
//			for (int k = 0; k < 4; k++) {
//				if (murder[k] == 1) {
//					if (k == 0) {
//						printf("MurderIs:>A");
//					}
//					if (k == 1) {
//						printf("MurderIs:>B");
//					}
//					if (k == 2) {
//						printf("MurderIs:>C");
//					}
//					if (k == 3) {
//						printf("MurderIs:>D");
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

#define LINE 10
int main() {
	int triangle[LINE][LINE] = { 0 };
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < LINE; j++) {
			if (j == 0) {
				triangle[i][j] = 1;
			}
			if (i == j) {
				triangle[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < LINE; j++) {
			if (j != 0 && i != j&&i!=0&&i!=1) {
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
			}
		}
	}
	for (int i = 0; i < LINE; i++) {
		for (int k = 0; k < 2*(LINE - i); k++) {
			printf(" ");
		}
		for (int j = 0; j < LINE; j++) {
			if (triangle[i][j] != 0) {
				printf("%-3d ", triangle[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}