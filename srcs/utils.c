#include "idxval.h"

int	ft_lstis_sorted(const t_list *lst, t_ftcmp cmp)
{
	if (lst == NULL)
		return (1);
	while (lst->next != NULL && cmp(lst->content, lst->next->content) <= 0)
		lst = lst->next;
	return (lst->next == NULL);
}

int	ft_lststr_allof(const t_list *lst, t_ftstris ft_stris)
{
	while (lst != NULL && ft_stris(lst->content))
		lst = lst->next;
	return (lst == NULL);
}
