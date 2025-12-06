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

void destroy_mutex(t_data *data)
{
    pthread_mutex_destroy(&data->m_positive);
    pthread_mutex_destroy(&data->m_negative);
}