/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_smal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:06:02 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 22:13:06 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lst2range(t_list *lst)
{
	int		*array;
	size_t	i;

	if (!lst)
		return (0);
	array = (int *) ft_calloc(ft_lstsize(lst), sizeof(int));
	i = 0;
	while (array && lst)
	{
		array[i++] = *((int *) lst->content);
		lst = lst->next;
	}
	return (array);
}

void	ft_sort_array(int *array, size_t n)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	verif_list_sort(t_list **lst)
{
	t_list	*current;
	int		prev;
	int		tmp;

	current = *lst;
	prev = *((int *)current->content);
	while (current)
	{
		tmp = *((int *) current->content);
		if (tmp < prev)
			return (0);
		prev = tmp;
		current = current->next;
	}
	return (1);
}

t_info	ps_data_init(t_list **stack)
{
	t_list	*current;
	t_info	data;

	data.size = 0;
	data.value_min = 0;
	data.value_max = 0;
	current = *stack;
	if (current)
	{
		data.value_min = *((int *) current->content);
		data.value_max = *((int *) current->content);
		data.size++;
		current = current->next;
	}
	while (current)
	{
		if (*((int *) current->content) < data.value_min)
			data.value_min = *((int *) current->content);
		else if (*((int *) current->content) > data.value_max)
			data.value_max = *((int *) current->content);
		data.size++;
		current = current->next;
	}
	return (data);
}
