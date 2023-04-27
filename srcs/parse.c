/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stris_within_integer(const char *str)
{
	const long	value = ft_atol(str);

	return (INT_MIN <= value && value <= INT_MAX);
}

static t_list	*ps_tokenize(char **argv)
{
	t_list	*lst_arg;
	char	**split;

	lst_arg = NULL;
	while (*++argv != NULL)
	{
		split = ft_split(*argv, ' ');
		ft_lstadd_back(&lst_arg, ft_aatolst_clear((void **)split));
	}
	return (lst_arg);
}

t_list	*ps_parse(char **argv)
{
	t_list	*stack_a;
	t_list	*lst_token;

	lst_token = ps_tokenize(argv);
	if (ft_lstallof(lst_token, stris_numeric)
		&& ft_lstallof(lst_token, stris_within_integer))
		stack_a = ft_lstmap(lst_token, idxval_new, idxval_del);
	else
		stack_a = NULL;
	ft_lstclear(&lst_token, free);
	return (stack_a);
}
