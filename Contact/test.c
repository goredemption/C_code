#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void test1() {
	struct contact ct;
	initial(&ct);
	insert(&ct);
	insert(&ct);
	erase(&ct);
	print(&ct);
	destroy(&ct);
}
void test2() {
	struct contact ct;
	initial(&ct);
	insert(&ct);
	insert(&ct);
	modify(&ct);
	print(&ct);
	destroy(&ct);
}
int main() {
	int run = 1;
	struct contact ct;
	initial(&ct);
	do {
		menu();
		int x = 0;
		scanf("%d", &x);
		switch (x)
		{
		case 1: {
			insert(&ct);
			break;
		}
		case 2: {
			erase(&ct);
			break;
		}
		case 3: {
			find(&ct);
			break;
		}
		case 4: {
			modify(&ct);
			break;
		}
		case 5: {
			print(&ct);
			break;
		}
		case 6: {
			destroy(&ct);
			break;
		}
		case 7: {
			sort(&ct);
			break;
		}
		case 0: {
			run = 0;
			break;
		}
		default: {
			printf("/* Invalid Input */\n");
			break;
		}
		}
	} while (run);
	return 0;
}