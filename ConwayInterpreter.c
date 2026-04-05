#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#define MAX_STEPS 1000
#define MAX_FACTORS 128

//clear && gcc ConwayInterpreter.c -lm -o m.o && ./m.o
typedef struct
{
	uint64_t num;
	uint64_t den;
}Fraction;

//Simple prime factorization
void PrintPrimeFactorization(uint64_t n) 
{
	printf("Factorization: ");
	uint64_t first = 1;
	uint64_t count = 0;while (n % 2 == 0) {count++;n /= 2;}
	if(count > 0){printf("(%d,%lu)", 2, count);first = 0;}
	for(uint64_t i = 3; i <= sqrt(n); i += 2) 
	{
		count = 0;
		while (n % i == 0){count++;n /= i;}
		if(count > 0){if (!first) printf(", ");printf("(%lu,%lu)", i, count);first = 0;}
	}

	//Remaining prime
	if(n > 2){if (!first) printf(", ");printf("(%lu,%d)", n, 1);}
	printf("\n");
}

uint64_t FractranInterpreter(uint64_t start, Fraction f[], uint64_t fractionCount, uint64_t results[], uint64_t *resultLength) 
{
	uint64_t n = start;
	results[0] = n;
	*resultLength = 1;
	for(uint64_t step = 0; step < MAX_STEPS; step++)
	{
		uint64_t applied = 0;
		for(uint64_t i = 0; i < fractionCount; i++) 
		{
			//Check if n * num / den is integer
			if((n * f[i].num) % f[i].den == 0)
			{
				n = (n * f[i].num) / f[i].den;
				results[*resultLength] = n;
				(*resultLength)++;
				printf("Step %lu: %lu\n", step, n);
				applied = 1;
				break;
			}
		}
		if(!applied) 
		{
			printf("Halting.\n");
			return n;
		}
	}
	printf("Max steps reached.\n");
	return n;
}

void AdditionProgram() 
{
	uint64_t start = 72;
	Fraction program[] = {{3, 2}};

	uint64_t fractionCount = sizeof(program) / sizeof(program[0]);

	printf("\nTesting ADD\nInitial n: %lu\n", start);
	PrintPrimeFactorization(start);

	uint64_t results[MAX_STEPS];
	uint64_t resultLength = 0;
	uint64_t final = FractranInterpreter(start, program, fractionCount, results, &resultLength);

	printf("\nAll values of n:\n");
	for (uint64_t i = 0; i < resultLength; i++) 
	{
		printf("%lu ", results[i]);
	}
	printf("\n");

	printf("\nFinal n: %lu\n", final);
	PrintPrimeFactorization(final);

}

void SubtractionProgram() 
{
	uint64_t start = 497664;
	Fraction program[] = {{7, 6},{1,7}};

	uint64_t fractionCount = sizeof(program) / sizeof(program[0]);

	printf("\nTesting SUB\nInitial n: %lu\n", start);
	PrintPrimeFactorization(start);

	uint64_t results[MAX_STEPS];
	uint64_t resultLength = 0;
	uint64_t final = FractranInterpreter(start, program, fractionCount, results, &resultLength);

	printf("\nAll values of n:\n");
	for (uint64_t i = 0; i < resultLength; i++) 
	{
		printf("%lu ", results[i]);
	}
	printf("\n");

	printf("\nFinal n: %lu\n", final);
	PrintPrimeFactorization(final);

}

void MultiplicationProgram() 
{
	uint64_t start = 36;
	Fraction program[] = {{385, 13},{13, 21},{1, 7},{3, 11},{7, 2},{1, 3}};

	uint64_t fractionCount = sizeof(program) / sizeof(program[0]);

	printf("\nTesting MUL\nInitial n: %lu\n", start);
	PrintPrimeFactorization(start);

	uint64_t results[MAX_STEPS];
	uint64_t resultLength = 0;
	uint64_t final = FractranInterpreter(start, program, fractionCount, results, &resultLength);

	printf("\nAll values of n:\n");
	for (uint64_t i = 0; i < resultLength; i++) 
	{
		printf("%lu ", results[i]);
	}
	printf("\n");

	printf("\nFinal n: %lu\n", final);
	PrintPrimeFactorization(final);
}

void DivisionProgram() 
{
	uint64_t start = 456192;
	Fraction program[] = {{91, 66},{11, 13},{1, 33},{85, 11},{57, 119},{17, 19},{11, 17},{1, 3}};

	uint64_t fractionCount = sizeof(program) / sizeof(program[0]);

	printf("\nTesting DIV\nInitial n: %lu\n", start);
	PrintPrimeFactorization(start);

	uint64_t results[MAX_STEPS];
	uint64_t resultLength = 0;
	uint64_t final = FractranInterpreter(start, program, fractionCount, results, &resultLength);

	printf("\nAll values of n:\n");
	for (uint64_t i = 0; i < resultLength; i++) 
	{
		printf("%lu ", results[i]);
	}
	printf("\n");

	printf("\nFinal n: %lu\n", final);
	PrintPrimeFactorization(final);
}

void FusedMultiplyAddProgram() 
{
	uint64_t start = 337500;
	Fraction program[] = {
	{385, 13},{13, 21},{1,7},{3, 11},{7, 2},{1, 3}};

	uint64_t fractionCount = sizeof(program) / sizeof(program[0]);

	printf("\nTesting FMA\nInitial n: %lu\n", start);
	PrintPrimeFactorization(start);

	uint64_t results[MAX_STEPS];
	uint64_t resultLength = 0;
	uint64_t final = FractranInterpreter(start, program, fractionCount, results, &resultLength);

	printf("\nAll values of n:\n");
	for (uint64_t i = 0; i < resultLength; i++) 
	{
		printf("%lu ", results[i]);
	}
	printf("\n");

	printf("\nFinal n: %lu\n", final);
	PrintPrimeFactorization(final);
}

uint64_t main()
{
	AdditionProgram();
	SubtractionProgram();
	DivisionProgram();
	MultiplicationProgram();
	FusedMultiplyAddProgram();
	return 0;
}

