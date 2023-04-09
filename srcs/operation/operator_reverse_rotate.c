#include "libft.h"

static void	operator_reverse_rotate(t_list **stack)
{
	ft_lstadd_front(stack, ft_lstextract_back(stack));
}

void	operator_rra(t_list **stack_a, t_list **stack_b)
{
	operator_reverse_rotate(stack_a);
	(void)stack_b;
}

void	operator_rrb(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	operator_reverse_rotate(stack_b);
}

void	operator_rrr(t_list **stack_a, t_list **stack_b)
{
	operator_reverse_rotate(stack_a);
	operator_reverse_rotate(stack_b);
}
