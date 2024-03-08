#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info {
	char name[20];
	double score;
	int credit;
};
void input_data(struct info* st_p, int a);
void scholarship(struct info* st_p, int a);
int main(void) {
	struct info students[5];
	input_data(students, 5);
	scholarship(students, 5);
}
void input_data(struct info* st_p, int a) {
	printf("학생이름, 취득학점, 평점 평균을 입력하세요:\n");
	for (int i = 0; i < a; i++) {
		scanf("%s %lf %d", (st_p+i)->name, &((st_p+i)->score), &((st_p+i)->credit));
	}
}
void scholarship(struct info* st_p, int a) {
	for (int i = 0; i < a; i++) {
		if (((st_p + i)->score >= 4) && ((st_p + i)->credit > 20))
			printf("장학생 이름:%s\n평점 평균:%.1f\n취득 학점:%d\n", (st_p+i)->name, (st_p+i)->score, (st_p+i)->credit);
	}
	return;
}