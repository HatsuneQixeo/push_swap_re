#include "libft.h"

static void	operator_rotate(t_list **stack)
{
	ft_lstadd_back(stack, ft_lstextract_front(stack));
}

void	operator_ra(t_list **stack_a, t_list **stack_b)
{
	operator_rotate(stack_a);
	(void)stack_b;
}

void	operator_rb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	operator_rotate(stack_b);
}

void	operator_rr(t_list **stack_a, t_list **stack_b)
{
	operator_rotate(stack_a);
	operator_rotate(stack_b);
}
