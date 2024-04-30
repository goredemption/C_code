#include<stdio.h>
int testify(int testimony[], char queue[]) {
	int i = 0;
	int error = 0;
	if (testimony[i] == 0) {
		i++;
		queue[2] = 'A';
	}
	else {
		i++;
		queue[1] = 'B';
	}
	if (testimony[i] == 0) {
		i++;
		queue[3] = 'E';
	}
	else {
		i++;
		queue[1] = 'B';
	}
	if (testimony[i] == 0) {
		i++;
		if (queue[1] == 0 || queue[1] == 'D') {
			queue[1] = 'D';
		}
		else {
			error++;
		}
	}
	else {
		i++;
		queue[0] = 'C';
	}
	if (testimony[i] == 0) {
		i++;
		if (queue[2] == 0 || queue[2] == 'D') {
			queue[2] = 'D';
		}
		else {
			error++;
		}
	}
	else {
		i++;
		if (queue[4] == 0 || queue[4] == 'C') {
			queue[4] = 'C';
		}
		else {
			error++;
		}
	}
	if (testimony[i] == 0) {
		i++;
		if (queue[0] == 0 || queue[0] == 'A') {
			queue[0] = 'A';
		}
		else {
			error++;
		}
	}
	else {
		i++;
		if (queue[3] == 0 || queue[3] == 'E') {
			queue[3] = 'E';
		}
		else {
			error++;
		}
	}
	if (error == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int testimony[10] = { 0 };
	char queue[10] = { 0 };
	int i = 0;
	for (int a = 0; a < 2; a++) {
		testimony[i] = a;
		i++;
		for (int b = 0; b < 2; b++) {
			testimony[i] = b;
			i++;
			for (int c = 0; c < 2; c++) {
				testimony[i] = c;
				i++;
				for (int d = 0; d < 2; d++) {
					testimony[i] = d;
					i++;
					for (int e = 0; e < 2; e++) {
						testimony[i] = e;
						i++;
						if (testify(testimony, queue) == 1) {
							goto end;
						}
					}
				}
			}
		}
	}
end:
	printf("%s", queue);
	return 0;
}