#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct s
//{
//	char a : 1;
//	char b : 1;
//	char e : 1;
//	char c;
//	char d : 3;
//}*t;
//struct p {
//	char d : 3;
//};
//struct tagPIM
//{
//	unsigned char ucPim1;
//	unsigned char ucData0 : 1;
//	unsigned char ucData1 : 2;
//	unsigned char ucData2 : 3;
//};
//int main() {
//	t = (struct s*)malloc(sizeof(struct s));
//	struct p* p1 = (struct p*)t;
//	t->a = 1;
//	t->b = 0;
//	t->e = 1;
//	t->d = 5;
//	int a = p1->d;
//	printf("%d\n", t->d);
//	printf("%d\n", p1->d);
//	printf("%d\n", a);
//	return 0;
//}

//int main() {
//	return 0;
//}

//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    struct s {
//        unsigned char a : 1;
//        unsigned char b : 1;
//        unsigned char c : 1;
//        unsigned char d : 1;
//        unsigned char e : 1;
//        unsigned char f : 1;
//    }*t;
//    t = (struct s*)malloc(sizeof(struct s));
//    t->a = 1;
//    t->b = 0;
//    t->c = 0;
//    t->d = 1;
//    t->e = 0;
//    t->f = 1;
//    char* p = (char*)t;
//    printf("%02x")
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}


//int main() {
//	printf("%5d%5d%5d\n", 101, 97, 81);
//	printf("%05d%05d%05d", 101, 97, 81);
//	return 0;
//}
//enum color {
//	red,
//	pink,
//	yellow = 255,
//	bule,
//	gray
//};
//int main() {
//	int i = bule;
//	enum color c1 = gray;
//	enum color c2 = red;
//	printf("%d %d", c1, c2);
//	return 0;
//}

//struct student {
//	int age;
//	char name[20];
//	char sex[7];
//};
//int main() {
//	struct student chess_club[3] = { {15,"jimmy","secret"},{17,"ammy","female"},{14,"tommy","male"}};
//	printf("original group:\n%d %s %s\n%d %s %s\n%d %s %s\n", chess_club[0].age, chess_club[0].name,
//		chess_club[0].sex, chess_club[1].age, chess_club[1].name, chess_club[1].sex
//		, chess_club[2].age, chess_club[2].name, chess_club[2].sex);
//	struct student mikey = { 16,"mike","male" };
//	chess_club[0] = mikey;
//	printf("new group:\n");
//	for (int i = 0; i < 3; i++) {
//		printf("%d %s %s\n", chess_club[i].age, chess_club[i].name, chess_club[i].sex);
//	}
//	return 0;
//}

struct student {
	int age;
	char name[20];
	char sex[7];
};
void initialize(struct student p) {
	p.age = 0;
	for (int i = 0; i < 20; i++) {
		p.name[i] = 0;
	}
	for (int i = 0; i < 7; i++) {
		p.sex[i] = 0;
	}
}
int main() {
	struct student lisi = {0};
	initialize(lisi);
	return 0;
}
