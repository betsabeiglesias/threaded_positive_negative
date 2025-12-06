#include "../include/nemergent.h"

void *routine(void *arg)
{
	t_data *data;
	int		num;
	int		i;
	unsigned int seed;

	data = (t_data *)arg;
	i = 0;
	seed = time(NULL) ^ pthread_self();
	while (i < data->nb_per_thread)
	{
		num = rand_r(&seed);
		if (rand_r(&seed) % 2)
			num = -num;
		if(num >= 0)
			add_node(&data->positive, num, data, POSITIVE);
		else
			add_node(&data->negative, num, data, NEGATIVE);
		i++;
	}
	return (NULL) ;
}

void add_node(t_list **list, int num, t_data *data, int class)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (perror("add_node: "));
	new->nb = num;
	new->next = NULL;
	if (class == POSITIVE)
		pthread_mutex_lock(&data->m_positive);
	else if (class == NEGATIVE)
		pthread_mutex_lock(&data->m_negative);
	ft_lstadd_front(list, new);
	if (class == POSITIVE)
		pthread_mutex_unlock(&data->m_positive);
	else if (class == NEGATIVE)
		pthread_mutex_unlock(&data->m_negative);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
