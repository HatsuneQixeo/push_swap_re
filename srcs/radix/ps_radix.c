#include "push_swap.h"

# define BUCKET_BASE	2

void	radix(t_list **stack_a, t_list **stack_b, const size_t digit)
{
	size_t	i;
	size_t	iteration;

	i = -1;
	while (++i < BUCKET_BASE - 1)
	{
		iteration = ft_lstsize(*stack_a);
		while (iteration--)
		{
			if ((idxval_getindex((*stack_a)->content) / digit) % BUCKET_BASE == i)
				ps_operate(operator_pb, stack_a, stack_b);
			else
				ps_operate(operator_ra, stack_a, stack_b);
		}
	}
}

void	ps_radix_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	digit;

	digit = 1;
	// radix(stack_a, stack_b, digit);
	while (!(ft_lstis_sorted(*stack_a, idxval_cmp_index)))
	{
		radix(stack_a, stack_b, digit);
		digit *= BUCKET_BASE;
		ps_repeat(operator_pa, stack_a, stack_b, ft_lstsize(*stack_b));
	}
}
