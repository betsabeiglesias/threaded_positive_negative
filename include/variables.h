#ifndef VARIABLES_H
# define VARIABLES_H

# include <pthread.h>

typedef struct	s_list
{
	int				nb;
	struct s_list	*next;
}				t_list;

typedef struct	s_data
{
	int				nb_per_thread;
	int				thread_num;
	pthread_t		*th;
	t_list			*positive;
	t_list			*negative;
	pthread_mutex_t	m_positive;
	pthread_mutex_t	m_negative;
}				t_data;

# endif