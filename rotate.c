/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:16:28 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/06 18:36:23 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return (0);
	if ((*lst)->next == NULL)
		return (0);
	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstlast(*lst)->next = tmp;
	tmp->next = NULL;
	return (1);
}

void	rotate_a(t_list **lst)
{
	if (rotate(lst))
		ft_printf("ra\n");
}

void	rotate_b(t_list **lst)
{
	if (rotate(lst))
		ft_printf("rb\n");
}

void	rotate_r(t_list **lst, t_list **lat)
{
	if (rotate(lst) + rotate(lat))
		ft_printf("rr\n");
}
