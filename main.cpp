// main.cpp
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "add.h"
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	FILE* num1;
	FILE* num2;

	uint32_t* a = (uint32_t*)malloc(sizeof(uint32_t));
	uint32_t* b = (uint32_t*)malloc(sizeof(uint32_t));

	uint32_t a1, b1, c1;

	if ((num1 = fopen(argv[1], "rb")) == NULL)
	{
		printf("fail\n");
		return 0;	
	}

	if ((num2 = fopen(argv[2], "rb")) == NULL)
	{
		printf("fail\n");
		return 0;
	}

	fread(a, sizeof(uint32_t), 1, num1);
	fread(b, sizeof(uint32_t), 1, num2);

	a1 = ntohl(*a);
	b1 = ntohl(*b);

	free(a);
	free(b);

	c1 = add(a1, b1);

	fclose(num1);
	fclose(num2);

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", a1, a1, b1, b1, c1, c1);
}
