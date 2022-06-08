/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:16:08 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:28:26 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (c < 2)
		return (0);
	if (!parsing(c, argv, &a))
	{
		ft_lstclear(&a, free);
		return (ft_printf("Error\n"));
	}
	b = 0;
	sorting_init(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
}
