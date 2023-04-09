/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Changing the base doesn't quite help,
	since there's realistically only one bucket

	It only takes more time to divide the bucket,
	and more time to push the bucket back
*/
#ifndef BUCKET_SIZE
# define BUCKET_SIZE	2
#endif

void	radix(t_list **stack_a, t_list **stack_b, const size_t digit)
{
	size_t	i;
	size_t	iteration;

	i = -1;
	while (++i < BUCKET_SIZE - 1)
	{
		iteration = ft_lstsize(*stack_a);
		while (iteration--)
		{
			if (idxval_getindex((*stack_a)->content) / digit % BUCKET_SIZE == i)
				ps_operate(operator_pb, stack_a, stack_b);
			else
				ps_operate(operator_ra, stack_a, stack_b);
		}
	}
}

void	ps_radix_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	digit;

	digit = 1;
	while (!(ft_lstis_sorted(*stack_a, idxval_cmp_index)))
	{
		radix(stack_a, stack_b, digit);
		digit *= BUCKET_SIZE;
		ps_repeat(operator_pa, stack_a, stack_b, ft_lstsize(*stack_b));
	}
}
