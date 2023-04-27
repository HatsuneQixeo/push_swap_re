/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_lookup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "operator.h"

typedef struct operation
{
	const char	*name;
	t_operator	operator;
}			t_operation;

static int	find_operatorfunc(unsigned int i, const void *arr, const void *op)
{
	const t_operation	*operations = arr;

	return (operations[i].operator == op);
}

static int	find_operatorname(unsigned int i, const void *arr, const void *name)
{
	const t_operation	*operations = arr;

	return (!ft_strcmp(name, operations[i].name));
}

static const t_operation	*operator_find(t_ftfind ft_find, const void *ref)
{
	static const t_operation	operations[] = {
	{"sa", operator_sa},
	{"sb", operator_sb},
	{"ss", operator_ss},
	{"pa", operator_pa},
	{"pb", operator_pb},
	{"ra", operator_ra},
	{"rb", operator_rb},
	{"rr", operator_rr},
	{"rra", operator_rra},
	{"rrb", operator_rrb},
	{"rrr", operator_rrr},
	};
	size_t						length;
	size_t						find;

	length = (sizeof(operations) / sizeof(operations[0]));
	find = ft_arrfind(operations, length, ft_find, ref);
	if (find == SIZE_MAX)
		return (NULL);
	else
		return (&operations[find]);
}

t_operator	operator_getfunc(const char *name)
{
	const t_operation	*operation = operator_find(find_operatorname, name);

	if (operation == NULL)
		return (NULL);
	else
		return (operation->operator);
}

const char	*operator_getname(t_operator operator)
{
	const t_operation	*op = operator_find(find_operatorfunc, operator);

	if (op == NULL)
		return (NULL);
	else
		return (op->name);
}
