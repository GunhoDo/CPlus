#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p, const void *q);
typedef struct name_grade {
	char name[10];
	int grade;
} name_grade;
int main(void)
{
	name_grade student[2] = { {"hello", 1}, {"apple", 2} };
	qsort(student, 2, sizeof(student[0]), compare);
	printf("%s %s", student[0].name, student[1].name);
	return 0;
}
int compare(const void *p, const void *q)
{
	return strcmp(((name_grade*)p)->name, ((name_grade*)q)->name);
}