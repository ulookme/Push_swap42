/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:08:42 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:20:37 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_overflow(char *content, char *cmp, int sign)
{
	int	i;

	if (!content || !cmp)
		return (0);
	if (ft_strlen(content) < ft_strlen(cmp))
		return (0);
	else if (ft_strlen(content) > ft_strlen(cmp))
		return (1);
	else
	{
		i = 0;
		while (content[i] && cmp[i] && content[i] == cmp[i])
			i++;
		if ((sign >= 0 && content[i] <= cmp[i])
			|| (sign < 0 && content[i] >= cmp[i]))
			return (0);
		else
			return (1);
	}
}

int	ft_intoverflow(char *content)
{
	char	*cmp;
	int		sign;
	int		t;

	if (!content)
		return (0);
	sign = 1;
	if (content[0] == '-')
		sign = -1;
	if (content[0] == '+' || content[0] == '-')
		content++;
	if (sign < 0)
		cmp = ft_itoa(-__INT_MAX__ - 1);
	else
		cmp = ft_itoa(__INT_MAX__);
	t = ft_overflow(content, cmp, sign);
	free(cmp);
	return (t);
}

int	ft_isnum(char *c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	if (c[0] == '+' || c[0] == '-')
		if (!ft_isdigit(c[++i]))
			return (0);
	while (c[i])
	{
		if (!ft_isdigit(c[i++]))
			return (0);
	}
	return (1);
}
