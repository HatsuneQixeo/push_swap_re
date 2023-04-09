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

int	ft_lststr_allof(const t_list *lst, t_ftstris ft_stris)
{
	while (lst != NULL && ft_stris(lst->content))
		lst = lst->next;
	return (lst == NULL);
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

	stack_a = NULL;
	lst_token = ps_tokenize(argv);
	if (ft_lststr_allof(lst_token, stris_numeric))
		stack_a = ft_lstmap(lst_token, idxval_new, idxval_del);
	else
		stack_a = NULL;
	ft_lstclear(&lst_token, free);
	return (stack_a);
}
