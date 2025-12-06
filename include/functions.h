#ifndef FUNCTIONS_H
# define FUNCTIONS_H


/* check_args.c */
int check_args(int argc, char **argv, t_data *data);
int is_valid_number(char *str);
long ft_atol(char *str);

/* aux.c */
void print_error(char *str);
void print_usage(void);

/* threads.c */
void init_data(t_data *data);
void destroy_mutex(t_data *data);

# endif