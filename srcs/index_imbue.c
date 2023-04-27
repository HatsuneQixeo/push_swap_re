/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_imbue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "idxval.h"

static int	has_duplicate(const t_list *lst, t_ftcmp cmp)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL && cmp(lst->content, lst->next->content))
		lst = lst->next;
	return (lst->next != NULL);
}

static void	apply_index(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		idxval_setindex(lst->content, i++);
		lst = lst->next;
	}
}

int	ps_index_imbue(const t_list *lst)
{
	t_list	*lst_cpy;
	int		ret;

	lst_cpy = ft_lstmap(lst, map_copy, idxval_del);
	ft_lstsort_merge(lst_cpy, NULL, idxval_cmp_value);
	if (has_duplicate(lst_cpy, idxval_cmp_value))
		ret = -1;
	else
	{
		ret = 0;
		apply_index(lst_cpy);
	}
	ft_lstclear(&lst_cpy, NULL);
	return (ret);
}
