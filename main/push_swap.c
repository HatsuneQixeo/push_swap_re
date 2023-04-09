#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = ps_parse(argv);
	stack_b = NULL;
	// ps_log(stack_a, stack_b);
	if (stack_a == NULL)
		ft_putendl_fd("Error: Invalid input", 2);
	else if (ps_index_imbue(stack_a) == -1)
		ft_putendl_fd("Error: Duplicate values", 2);
	else if (ft_lstis_sorted(stack_a, idxval_cmp_index))
		return (0);
	ps_radix_sort(&stack_a, &stack_b);
	system("leaks -q push_swap 1>&2");
	return (0);
}
