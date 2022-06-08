/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:08:57 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/06 17:16:45 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_2_power(int nb)
{
	int	res;

	res = 1;
	while (nb > 0)
	{
		res = res * 2;
		nb--;
	}
	return (res);
}

void	fruit_rouge_radix(t_list **a, t_list **b, t_info *data)
{
	size_t	bits;
	size_t	i;
	size_t	j;

	bits = 0;
	while (ft_2_power(bits) <= data-> value_max)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < data->size)
		{
			if ((*(int *)(*a)->content >> i) & 1)
				rotate_a(a);
			else
				push_b(a, b);
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}

t_list	*indexed_list(t_list **lst)
{
	t_list	*ind;
	t_list	*parser;
	t_list	*new_item;
	int		nb;
	t_list	*new_lst;

	ind = *lst;
	new_lst = NULL;
	while (ind)
	{
		new_item = ft_lstnew(rangeone(0));
		nb = *(int *)ind->content;
		parser = *lst;
		while (parser)
		{
			if (nb > *(int *)parser->content)
				(*(int *)(new_item->content))++;
			parser = parser->next;
		}
		ft_lstadd_back(&new_lst, new_item);
		ind = ind->next;
	}
	return (new_lst);
}
