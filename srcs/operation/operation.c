/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operator.h"

void	ps_operate(t_operator operator, t_list **stack_a, t_list **stack_b)
{
	const char	*name = operator_getname(operator);

	if (name == NULL)
		ft_putendl_fd("Error: ps_operate : Unknown operation", 2);
	else
	{
		ft_putendl_fd(name, 1);
		operator(stack_a, stack_b);
	}
}

void	ps_repeat(t_operator operator, t_list **stack_a, t_list **stack_b,
			size_t repeat)
{
	while (repeat--)
		ps_operate(operator, stack_a, stack_b);
}
