#include <stdio.h>

#define NUM_STUDENTS 5
#define NUM_QUIZZES 5

int main(void)
{
	int grades[NUM_STUDENTS][NUM_QUIZZES], student, quiz, total, high, low;

	for (int student = 0; student < NUM_STUDENTS; student++)
	{
		printf("Enter grades for student %d: ", student + 1);
		for (quiz = 0; quiz < NUM_STUDENTS; quiz++)
			scanf("%d", &grades[student][quiz]);
	}

	printf("\nStudents  Totals  Average\n");
	for (student = 0; student < 5; student++)
	{
		printf("%5d       ", student + 1);
		total = 0;
		for (quiz = 0; quiz < 5; quiz++)
			total += grades[student][quiz];
		printf("%3d     %3d\n", total, total/NUM_QUIZZES);
	}

	printf("\nQuiz  Average  High  Low\n");
	for (quiz = 0; quiz < NUM_QUIZZES; quiz++)
	{
		printf("%3d     ", quiz + 1);
		total = 0;
		high = 0;
		low = 100;
		for (student = 0; student < NUM_STUDENTS; student++)
		{
			total += grades[student][quiz];
			if (grades[student][quiz] > high)
				high = grades[student][quiz];
			if (grades[student][quiz] < low)
				low = grades[student][quiz];
		}
		printf("%3d    %3d   %3d\n", total / NUM_STUDENTS, high, low);
	}

	return 0;
}
/*
* 80 12 34 23 89
* 16 27 80 78 91
* 93 82 72 92 41
* 91 83 92 71 85
* 99 98 94 96 93
*/