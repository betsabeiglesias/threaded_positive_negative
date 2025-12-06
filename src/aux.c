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

void print_list(t_list *list)
{
	int	i;

	i = 1;	
	if(!list)
		return ;
	while(list)
	{
		printf("Position %d:\t", i);
		printf("%d\n", list->nb);
		list = list->next;
		i++;
	}
	printf("\n");
}
