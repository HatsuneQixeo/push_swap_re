#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operator.h"
# include "idxval.h"

t_list	*ps_parse(char **argv);

int		ft_lstis_sorted(const t_list *lst, t_ftcmp cmp);
int		ft_lststr_allof(const t_list *lst, t_ftstris ft_stris);

int		ps_index_imbue(const t_list *lst);
void	ps_log(const t_list *stack_a, const t_list *stack_b);

void	ps_radix_sort(t_list **stack_a, t_list **stack_b);

#endif
