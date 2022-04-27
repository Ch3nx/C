#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
	srand((unsigned)time(NULL));

	char play;
	int win = 0, lose = 0;

	for(;;)
	{
		if (play_game())
			win++;
		else
			lose++;
		printf("\nPlay again? ");
		play = getchar();
		getchar();
		printf("\n");
		if (play == 'n')
		{
			printf("Wins: %d  Losses: %d\n", win, lose);
			return 0;
		}
	}

	return 0;
}

int roll_dice(void)
{
	int num;

	num = rand() % 6 + rand() % 6 + 2;
	printf("You rolled: %d\n", num);

	return num;
}

bool play_game(void)
{
	int dice = roll_dice(), point = 0;

	switch (dice)
	{
		case 7:
		case 11:
			printf("You win!\n");
			return true;
		case 2:
		case 3:
		case 12:
			printf("You lose!\n");
			return false;
		default:
			printf("Your point is %d\n", dice);
			break;
	}
	for (;;)
	{
		point = roll_dice();
		if (dice == point)
		{
			printf("You win!\n");
			return true;
		}
		if (point == 7)
		{
			printf("You lose!\n");
			return false;
		}
	}
}