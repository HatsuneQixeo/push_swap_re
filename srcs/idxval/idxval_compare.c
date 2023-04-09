/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxval_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "idxval.h"

static int	idxval_cmp(const void *idxval_a, const void *idxval_b,
			t_idxval_getter getter)
{
	return (getter(idxval_a) - getter(idxval_b));
}

int	idxval_cmp_value(const void *idxval_a, const void *idxval_b)
{
	return (idxval_cmp(idxval_a, idxval_b, idxval_getvalue));
}

int	idxval_cmp_index(const void *idxval_a, const void *idxval_b)
{
	return (idxval_cmp(idxval_a, idxval_b, idxval_getindex));
}
