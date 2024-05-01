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
int main() {
	test1();
	return 0;
}