/**
 * @file program.c
 * @author Kyle Spicer
 * @brief Sample program to use with check unit testing class. 
 * @version 0.1
 * @date 2023-06-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "program_funcs.h"

int main(void)
{

	int a = 500;

	int result = add_500(a);

	printf("Result: %d\n", result);

	return 0;
}
