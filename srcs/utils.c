/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idxval.h"

int	ft_lstis_sorted(const t_list *lst, t_ftcmp cmp)
{
	if (lst == NULL)
		return (1);
	while (lst->next != NULL && cmp(lst->content, lst->next->content) <= 0)
		lst = lst->next;
	return (lst->next == NULL);
}

int	ft_lstallof(const t_list *lst, int (*ft_is)())
{
	while (lst != NULL && ft_is(lst->content))
		lst = lst->next;
	return (lst == NULL);
}
