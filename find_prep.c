#include "push_swap.h"

t_stack	*ft_findmin(t_stack *stacks)
{
	long	min;
	t_stack	*min_node;

	min = LONG_MAX;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg < min)
		{
			min = stacks->dataarg;
			min_node = min;
		}
		stacks = stacks->next;
	}
	return (min_node);
}

t_stack	*ft_findmax(t_stack *stacks)
{
	long	max;
	t_stack	*max_node;

	max = LONG_MIN;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg < max)
		{
			max = stacks->dataarg;
			max_node = max;
		}
		stacks = stacks->next;
	}
	return (max_node);
}

t_stack	*ft_lowercost(t_stack *stacks)
{
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->lowercost)
			return (stacks);
		stacks = stacks->next;
	}
	return (NULL);
}

void	ft_preppush(t_stack **stacks, t_stack *head, char name)
{
	while (*stacks != head)
	{
		if (name == 'a')
			if (head->up_median)
				ra(stacks);
			else
				rra(stacks);
		else if (name == 'b')
		{
			if (head->up_median)
				rb(stacks);
			else
				rrb(stacks);
		}
	}
}
