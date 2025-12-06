#include "../include/nemergent.h"

void print_error(char *str)
{
	if (!str)
		return ;
	write(STDERR_FILENO, str, strlen(str));
}

void print_usage(void)
{
    write(STDERR_FILENO, USAGE_MSG, strlen(USAGE_MSG));
}
