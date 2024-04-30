//#include<stdio.h>
//#include<stdlib.h>
//int main() {
//	int* p = (int*)malloc(10 * sizeof(int));
//	int* d=p;
//	for (int i = 0; i < 10; i++) {
//		p[i] = i;
//	}
//	free(d);
//	d = NULL;
//}

#include<stdio.h>
#include<stdlib.h>
int main() {
	int* p = (int*)malloc(10 * sizeof(int));
	if (p == NULL) {
		perror("malloc");
		return 1;
	}
	int*ptr=(int*)realloc(p, 1000 * sizeof(int));
	return 0;
}