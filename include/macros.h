#ifndef MACROS_H
# define MACROS_H

#define POSITIVE        0
#define NEGATIVE		1

# define ERR_MSG_NB_ARGS	"Error: Incorrect number of arguments\n"
# define ERR_INVALID_NUM    "Error: Arguments must be positive integers\n"
# define ERR_MSG_INT_MAX	"Error: Values exceed INT_MAX\n"


# define USAGE_MSG 		"Usage: ./nemergent <num_threads> <numbers_per_thread>\n" \
                        "  num_threads: Number of threads to create (> 0)\n" \
                        "  numbers_per_thread: Numbers each thread will generate (> 0)\n"

#endif