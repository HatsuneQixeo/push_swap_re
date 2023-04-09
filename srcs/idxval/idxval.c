/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:55 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:55 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idxval.h"

void	*idxval_new(void *content)
{
	t_idxval	*new;
	const long	value = ft_atol(content);

	if (!(INT_MIN <= value && value <= INT_MAX))
		return (NULL);
	new = malloc(sizeof(t_idxval));
	if (new == NULL)
		return (NULL);
	idxval_setvalue(new, value);
	idxval_setindex(new, 0);
	return (new);
}

void	idxval_del(void *idxval)
{
	free(idxval);
}

void	idxval_log(void *idxval)
{
	if (idxval == NULL)
		ft_dprintf(2, "OutofRange\n");
	else
		ft_dprintf(2, "[%3d]: %3d\n",
			idxval_getindex(idxval), idxval_getvalue(idxval));
}
