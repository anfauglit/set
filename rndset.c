#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define RANGE 100

typedef struct
{
	size_t size;
	int* set;
} set;

int main (void)
{
	set* gen_set (size_t, int);
	void print_set (set*);
	void destr_set (set*);

	srand(time(NULL));
	
	set* setA = gen_set(SIZE, RANGE);
	set** setF;

	setF = malloc (sizeof (set*) * SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		setF[i] = gen_set(SIZE + i, RANGE);
	}

	for (int i  = 0; i < SIZE; ++i)
	{
		print_set(setF[i]);
		puts("");
	}
	
	destr_set(setA);

	return 0;
}

set* gen_set (size_t size, int range)
{
	set* _set = malloc(sizeof (set));
	int* setA = malloc(sizeof (int) * size);

	for (int i = 0; i < size; ++i)
		setA[i] = rand() % range;

	*_set = (set) {size, setA};

	return _set;
}

void destr_set (set* setA)
{
	free(setA->set);
	free(setA);
}

void print_set (set* set)
{
	for (int i = 0; i < set->size; ++i)
		printf("%3i", set->set[i]);
}
