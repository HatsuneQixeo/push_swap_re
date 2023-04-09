#include "push_swap.h"

t_list	*ps_tokenize(char **argv)
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
