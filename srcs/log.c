/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idxval.h"

static void	logone(const t_list *stack)
{
	if (stack == NULL)
		ft_dprintf(2, "OutofRange");
	else
		ft_dprintf(2, "[%3d]: %3d",
			idxval_getindex(stack->content), idxval_getvalue(stack->content));
}

void	ps_log(const t_list *stack_a, const t_list *stack_b)
{
	while (stack_a != NULL || stack_b != NULL)
	{
		logone(stack_a);
		ft_dprintf(2, "  |  ");
		logone(stack_b);
		ft_dprintf(2, "\n");
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_dprintf(2, " (stack_a)  |  (stack_b) \n\n");
}
