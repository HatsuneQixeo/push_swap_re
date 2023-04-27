/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxval_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:56 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:56 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "idxval.h"

void	idxval_setvalue(t_idxval *idxval, const int value)
{
	idxval->value = value;
}

void	idxval_setindex(t_idxval *idxval, const int index)
{
	idxval->index = index;
}
