#include "../include/nemergent.h"

void init_data(t_data *data)
{
    data->nb_per_thread = 0;
	data->thread_num = 0;
    data->th = NULL;
    data->positive = NULL;
    data->negative = NULL;
    pthread_mutex_init(&data->m_positive, NULL);
    pthread_mutex_init(&data->m_negative, NULL);
}

int init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->th = malloc(sizeof(pthread_t) * data->thread_num);
	if (!data->th)
		return (perror("init_threads: "), EXIT_FAILURE);
	while (i < data->thread_num)
	{
		if (pthread_create(&data->th[i], NULL, &routine, data) != 0)
			return (perror("pthread_create: "), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int join_threads(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->thread_num)
	{
		if (pthread_join(data->th[i], NULL))
			return (perror("join_threads: "),EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	destroy_mutex(t_data *data)
{
	if (pthread_mutex_destroy(&data->m_positive) != 0)
		perror("destroy_mutex positive: ");

	if (pthread_mutex_destroy(&data->m_negative) != 0)
		perror("destroy_mutex negative: ");
}
