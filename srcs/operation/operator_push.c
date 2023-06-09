/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	operator_push(t_list **src, t_list **dst)
{
	ft_lstadd_front(dst, ft_lstextract_front(src));
}

void	operator_pa(t_list **stack_a, t_list **stack_b)
{
	operator_push(stack_b, stack_a);
}

void	operator_pb(t_list **stack_a, t_list **stack_b)
{
	operator_push(stack_a, stack_b);
}
