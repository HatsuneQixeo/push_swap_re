/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxval_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idxval.h"

int	idxval_getvalue(const t_idxval *idxval)
{
	return (idxval->value);
}

int	idxval_getindex(const t_idxval *idxval)
{
	return (idxval->index);
}
