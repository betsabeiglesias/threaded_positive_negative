#include "../include/nemergent.h"

void final_list(t_list *list, char *class)
{
	t_list *sorted;

	if (!list)
	{
        printf("There are no %s numbers\n", class);
		return;
	}
	sorted = sort_list(list);
	if (sorted)
	{
		printf("%s\n", class);
		print_list(sorted);
		ft_lstclear(&sorted, &free);
	}
}

t_list *sort_list(t_list *list)
{
    int n_size = ft_lstsize(list);
	int *arr = list_to_array(list);
    t_list  *new = NULL;
	
	if (arr)
	{
		ft_lstclear(&list, &free);
		ft_bubble_sort(arr, n_size);
		new = array_to_list(arr, n_size);
		free(arr);
	}
    return  (new);
}

int *list_to_array(t_list *list)
{
	int size;
	int *arr;
	int	i;

	i = 0;
	size = ft_lstsize(list);
	if(!list || size == 0)
		return(NULL);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return(perror("malloc"), NULL);
	while(list)
	{
		arr[i] = list->nb;
		list = list->next;
		i++;
	}
	
	return (arr);
}

t_list *array_to_list(int *arr, int size)
{
	t_list *list;
	t_list *aux;
	int i;

	list = ft_lstnew(arr[0]);
	i = 1;
	while(i < size)
	{
		aux = ft_lstnew(arr[i]);
		if(!aux)
			return(ft_lstclear(&list, &free), NULL);
		ft_lstadd_back(&list,aux);
		i++;
	}
	return (list);
}

t_list *ft_lstnew(int nb)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->nb = nb;
	list->next = NULL;
	return (list);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(&lst->nb);
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

void ft_bubble_sort(int *array, int size)
{
	int	i;

	while (!ft_array_is_sorted(array, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
				ft_swap_nbr(&array[i], &array[i + 1]);
			i++;
		}
	}
	return ;
}

int	ft_array_is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void ft_swap_nbr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}