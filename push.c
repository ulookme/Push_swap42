/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:35:55 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:10:26 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src == NULL)
		return (0);
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	push_a(t_list **src, t_list **dst)
{
	if (push(dst, src))
		ft_printf("pa\n");
}

void	push_b(t_list **dst, t_list **src)
{
	if (push(dst, src))
		ft_printf("pb\n");
}
