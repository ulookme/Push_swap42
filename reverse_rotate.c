/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:36:59 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:12:14 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_r(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return (0);
	if ((*lst)->next == NULL)
		return (0);
	tmp = *lst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *lst;
	*lst = tmp->next;
	tmp->next = 0;
	return (1);
}

void	rr_a(t_list **lst)
{
	if (r_r(lst))
		ft_printf("rra\n");
}

void	rr_b(t_list **lst)
{
	if (r_r(lst))
		ft_printf("rrb\n");
}

void	r_r_r(t_list **lst, t_list **lat)
{
	if (r_r(lst) + r_r(lat))
		ft_printf("rrr\n");
}
