// Function Name.cpp: Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
	int t, i;
	for (t = 0; t < argc;++t){
		i = 0;
		while (argv[t][i]){
			putchar(argv[t][i]);
			++i;
		}
		printf_s("\n");
	}
	return 0;
}

