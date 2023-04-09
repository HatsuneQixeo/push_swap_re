#include "push_swap.h"

static int	ps_checker(t_list **stack_a, t_list **stack_b)
{
	char		*input;
	t_operator	operator;

	while (1)
	{
		// ps_log(*stack_a, *stack_b);
		input = ft_prompt("");
		if (input == NULL)
			return (0);
		operator = operator_getfunc(input);
		free(input);
		if (operator == NULL)
			break ;
		operator(stack_a, stack_b);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = ps_parse(argv);
	stack_b = NULL;
	if (stack_a == NULL)
		ft_putendl_fd("Error: Invalid input", 2);
	else if (ps_index_imbue(stack_a) == -1)
		ft_putendl_fd("Error: Duplicate values", 2);
	else if (ps_checker(&stack_a, &stack_b) == -1)
		ft_putendl_fd("Error: Invalid operation", 2);
	else if (!(ft_lstis_sorted(stack_a, idxval_cmp_index) && stack_b == NULL))
		ft_putendl_fd("KO", 1);
	else
	{
		ft_putendl_fd("OK", 1);
		/* Forbidden */
		system("leaks -q checker");
		return (0);
	}
	/* Forbidden */
	system("leaks -q checker");
	return (1);
}
