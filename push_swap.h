/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:09:09 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 18:15:05 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_intvector3 {
	int			x;
	int			y;
	int			z;
}	t_vector3;

typedef struct s_info{
	size_t		size;
	int			value_min;
	int			value_max;
}	t_info;

void	swap_sa(t_list **lst);
void	swap_sb(t_list **lst);
void	swap_ss(t_list **lst, t_list **lat);
void	rotate_a(t_list **lst);
void	rotate_b(t_list **lst);
void	rotate_r(t_list **lst, t_list **lat);
void	rr_a(t_list **lst);
void	rr_b(t_list **lst);
void	r_r_r(t_list **lst, t_list **lat);
void	push_a(t_list **dst, t_list **src);
void	push_b(t_list **dst, t_list **src);

int		ft_intoverflow(char *content);
int		ft_isnum(char *c);

int		*rangeone(int nbr);
int		parsing(int argc, char **argv, t_list **lst);
void	sorting_init(t_list **a, t_list **b);
int		ps_can_insert(t_list **lst, t_list *value, t_info data);
int		*ft_lst2range(t_list *lst);
void	ft_sort_array(int *array, size_t n);
int		verif_list_sort(t_list **lst);
t_info	ps_data_init(t_list **stack);
void	fruit_rouge_radix(t_list **a, t_list **b, t_info *data);
t_list	*indexed_list(t_list **lst);

#endif
