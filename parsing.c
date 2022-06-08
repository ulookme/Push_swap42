/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:10:03 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:40:33 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **array)
{
	size_t	n;

	n = 0;
	while (array[n])
		free(array[n++]);
	free(array);
}

static t_list	**convert_lst(char **argv, t_list **lst)
{
	unsigned int	i;

	if (!argv)
		return (lst);
	i = 0;
	if (*lst == NULL && argv[i])
		*lst = ft_lstnew(ft_strdup(argv[i++]));
	while (argv[i])
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(argv[i++])));
	return (lst);
}

int	check_digit_dd(t_list *lst)
{
	t_list	*next;

	if (!lst || !lst->content)
		return (0);
	if (!ft_isnum(lst->content))
		return (0);
	if (ft_intoverflow(lst->content))
		return (0);
	next = lst->next;
	while (next)
	{
		if (!ft_strncmp(lst->content, next->content, 11))
			return (0);
		next = next->next;
	}
	return (1);
}

int	*rangeone(int nbr)
{
	int	*array;

	array = (int *) ft_calloc(1, sizeof(int));
	if (array)
		array[0] = nbr;
	return (array);
}

int	parsing(int argc, char **argv, t_list **lst)
{
	char	**split;
	t_list	*tmp;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		convert_lst(split, lst);
		ft_free(split);
	}
	if (!(*lst))
		return (0);
	tmp = *lst;
	while (tmp)
	{
		if (!check_digit_dd(tmp))
			return (0);
		ft_lstupdate(tmp, free, rangeone(ft_atoi(tmp->content)));
		tmp = tmp->next;
	}
	return (1);
}
