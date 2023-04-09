/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	operator_swap(t_list **stack)
{
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	ft_memswap(&(*stack)->content, &(*stack)->next->content,
		sizeof((*stack)->content));
}

void	operator_sa(t_list **stack_a, t_list **stack_b)
{
	operator_swap(stack_a);
	(void)stack_b;
}

void	operator_sb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	operator_swap(stack_b);
}

void	operator_ss(t_list **stack_a, t_list **stack_b)
{
	operator_swap(stack_a);
	operator_swap(stack_b);
}
