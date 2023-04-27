/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idxval.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqixeo <hqixeo@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:27:57 by hqixeo            #+#    #+#             */
/*   Updated: 2023/04/10 02:27:57 by hqixeo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef IDXVAL_H
# define IDXVAL_H

# include "libft.h"

typedef struct s_indexed_value
{
	int	value;
	int	index;
}			t_idxval;

typedef int		(*t_idxval_getter)(const t_idxval *idxval);
int		idxval_getvalue(const t_idxval *idxval);
int		idxval_getindex(const t_idxval *idxval);

typedef void	(*t_idxval_setter)(t_idxval *idxval, const int value);
void	idxval_setvalue(t_idxval *idxval, const int value);
void	idxval_setindex(t_idxval *idxval, const int index);

void	*idxval_new(void *content);
void	idxval_del(void *idxval);
void	idxval_log(void *idxval);

/* Compare */
int		idxval_cmp_value(const void *idxval_a, const void *idxval_b);
int		idxval_cmp_index(const void *idxval_a, const void *idxval_b);

#endif
