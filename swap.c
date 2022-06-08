/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:13:45 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/06 17:19:15 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **lst)
{
	void	*tmp;

	if (*lst == NULL)
		return (0);
	if ((*lst)->next == NULL)
		return (0);
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
	return (1);
}

void	swap_sa(t_list **lst)
{
	if (swap(lst))
		ft_printf("sa\n");
}

void	swap_sb(t_list **lst)
{
	if (swap(lst))
		ft_printf("sb\n");
}

void	swap_ss(t_list **tls, t_list **tla)
{
	if (swap(tls) + swap(tla))
		ft_printf("ss\n");
}
