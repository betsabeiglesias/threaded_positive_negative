#ifndef FUNCTIONS_H
# define FUNCTIONS_H


/* check_args.c */
int check_args(int argc, char **argv, t_data *data);
int is_valid_number(char *str);
long ft_atol(char *str);

/* aux.c */
void print_error(char *str);
void print_usage(void);
void print_list(t_list *list);

/* threads.c */
void    init_data(t_data *data);
int     init_threads(t_data *data);
int     join_threads(t_data *data);
void    destroy_mutex(t_data *data);

/* routine.c */
void    *routine(void *arg);
void    add_node(t_list **list, int num, t_data *data, int class);
void    ft_lstadd_front(t_list **lst, t_list *new);

/* sort.c */
void    final_list(t_list *list, char *class);
t_list  *sort_list(t_list *list);
int     *list_to_array(t_list *list);
t_list  *array_to_list(int *arr, int size);
t_list	*ft_lstnew(int nb);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	    ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_bubble_sort(int *array, int size);
int	    ft_array_is_sorted(int *array, int size);
void	ft_swap_nbr(int *a, int *b);

# endif