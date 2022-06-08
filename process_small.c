/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:04:48 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 20:04:50 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_sort_trio(t_list **stack)
{
	t_vector3	v;

	v.z = *((int *)(*stack)->content);
	v.y = *((int *)(*stack)->next->content);
	v.x = *((int *)(*stack)->next->next->content);
	if ((v.x > v.z && v.z > v.y)
		|| (v.y > v.x && v.x > v.z)
		|| (v.z > v.y && v.y > v.x))
		swap_sa(stack);
	else if (v.z > v.x && v.x > v.y)
		rotate_a(stack);
	else if (v.y > v.z && v.z > v.x)
		rr_a(stack);
	else
		return ;
	ps_sort_trio(stack);
}

int	ps_can_insert(t_list **lst, t_list *value, t_info data)
{
	t_vector3	v;

	v.x = *((int *) value->content);
	v.y = *((int *)(*lst)->content);
	v.z = *((int *) ft_lstlast(*lst)->content);
	if ((v.x <= data.value_min && v.z >= data.value_max)
		|| (v.x >= data.value_max && v.y <= data.value_min)
		|| (v.x >= v.z && v.x <= v.y))
		return (1);
	return (0);
}

void	ps_sort_small(t_list **a, t_list **b, t_info *data)
{
	size_t	i;

	i = data->size;
	while (i > 3)
	{
		push_b(a, b);
		i--;
	}
	ps_sort_trio(a);
	while (i < data->size)
	{
		while (!ps_can_insert(a, *b, ps_data_init(a)))
			rotate_a(a);
		push_a(a, b);
		i++;
	}
	while (!verif_list_sort(a))
		rotate_a(a);
}

void	sorting_init(t_list **a, t_list **b)
{
	t_info	data;
	t_list	*index;

	if (verif_list_sort(a))
		return ;
	else if (ft_lstsize(*a) == 2)
		rotate_a(a);
	else
	{
		index = indexed_list(a);
		ft_lstclear(a, free);
		data = ps_data_init(&index);
		if (data.size <= 5)
			ps_sort_small(&index, b, &data);
		else
			fruit_rouge_radix(&index, b, &data);
	}
}
