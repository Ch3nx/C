#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define INITIAL_PARTS 10

struct part
{
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
};

struct part* inventory;
int num_parts = 0;
int max_parts = INITIAL_PARTS;


int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
	char code;

	inventory = malloc(max_parts * sizeof(struct part));
	if (inventory == NULL)
	{
		printf("Can't allocate initial inventory space.\n");
		exit(EXIT_FAILURE);
	}

	for (;;)
	{
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while ((getchar()) != '\n');
		switch (code)
		{
			case 'i':
				insert();
				break;
			case 's':
				search();
				break;
			case 'u':
				update();
				break;
			case 'p':
				print();
				break;
			case 'q':
				return 0;
			default:
				printf("Illegal code\n");
		}
		printf("\n");
	}
	return 0;
}

int find_part(int number)
{
	int i;

	for (i = 0; i < num_parts; i++)
		if (inventory[i].number == number)
			return i;

	return -1;
}

void insert(void)
{
	int part_number;
	struct part* temp;
	if (num_parts == max_parts)
	{
		max_parts *= 2;
		temp = realloc(inventory, max_parts * sizeof(struct part));
		if (temp == NULL)
		{
			printf("Insufficient memory; can't add more parts.\n");
			return;
		}
		inventory = temp;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0)
	{
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}

void search(void)
{
	int i, number;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Part name: %s\n", inventory[i].name);
		printf("Quantity on hand: %d\n", inventory[i].on_hand);
	}
	else
		printf("Part not found.\n");
}

void update(void)
{
	int i, number, change;

	printf("Enter part number: ");
	scanf("%d", &number);
	i = find_part(number);
	if (i >= 0)
	{
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		inventory[i].on_hand += change;
	}
	else
		printf("Part not found.\n");
}

void print(void)
{
	int i;

	printf("Part Number   Part Name                  Quantity on Hand\n");
	for (i = 0; i < num_parts; i++)
		printf("%7d       %-27s%9d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
}