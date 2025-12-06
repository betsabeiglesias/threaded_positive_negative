#include "../include/nemergent.h"

int main(int argc, char **argv)
{

    t_data data;

    init_data(&data);

    if (check_args(argc, argv, &data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);

    printf("Checking args: SUCCESS\n");
    printf("Threads: %d\n", data.thread_num);
    printf("Numbers per thread: %d\n", data.nb_per_thread);

    destroy_mutex(&data);
    
    return (EXIT_SUCCESS);
}