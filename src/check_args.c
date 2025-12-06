#include "../include/nemergent.h"

int check_args(int argc, char **argv, t_data *data)
{
	long num_threads = 0;
	long num_per_threads = 0;

	if (argc != 3)
	{
		print_error(ERR_MSG_NB_ARGS);
		print_usage();
		return (EXIT_FAILURE);
	}
	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		print_error(ERR_INVALID_NUM);
		print_usage();
		return (EXIT_FAILURE);
	}

	num_threads = ft_atol(argv[1]);
	num_per_threads = ft_atol(argv[2]);

	if (num_threads <= 0 || num_per_threads <= 0 || 
		num_threads > INT_MAX || num_per_threads > INT_MAX)
	{
		print_error(ERR_INVALID_NUM);
		print_usage();
		return (EXIT_FAILURE);
	}
	data->thread_num = num_threads;
	data->nb_per_thread = num_per_threads;
	return (EXIT_SUCCESS);
}

int is_valid_number(char *str)
{
	int i = 0;

	if (!str || !str[0])
		return (0);

	if (str[i] == '+')
		i++;
	
	if (!str[i])
		return(0);
	
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long ft_atol(char *str)
{
    long result = 0;
    int  i = 0;

    if (str[i] == '+')
        i++;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (result > (LONG_MAX - (str[i] - '0')) / 10)
            return (LONG_MAX);
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}
