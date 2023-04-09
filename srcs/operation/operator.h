/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:57 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:57 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

# include "libft.h"

typedef void	(*t_operator)(t_list **stack_a, t_list **stack_b);

void		operator_sa(t_list **stack_a, t_list **stack_b);
void		operator_sb(t_list **stack_a, t_list **stack_b);
void		operator_ss(t_list **stack_a, t_list **stack_b);

void		operator_pa(t_list **stack_a, t_list **stack_b);
void		operator_pb(t_list **stack_a, t_list **stack_b);

void		operator_ra(t_list **stack_a, t_list **stack_b);
void		operator_rb(t_list **stack_a, t_list **stack_b);
void		operator_rr(t_list **stack_a, t_list **stack_b);

void		operator_rra(t_list **stack_a, t_list **stack_b);
void		operator_rrb(t_list **stack_a, t_list **stack_b);
void		operator_rrr(t_list **stack_a, t_list **stack_b);

void		ps_operate(t_operator operator, t_list **stack_a, t_list **stack_b);
void		ps_repeat(t_operator operator, t_list **stack_a, t_list **stack_b,
				size_t repeat);

t_operator	operator_getfunc(const char *name);
const char	*operator_getname(t_operator operator);

#endif
