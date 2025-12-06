#include "../include/nemergent.h"

int main(int argc, char **argv)
{

    t_data data;

    init_data(&data);

    if (check_args(argc, argv, &data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);

    if (init_threads(&data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    
    if (join_threads(&data) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
   
    final_list(data.positive, "POSITIVE");
    final_list(data.negative, "NEGATIVE");

    free(data.th);
    destroy_mutex(&data);

    return (EXIT_SUCCESS);
}