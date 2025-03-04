#include "push_swap.h"

static void	ft_set_a(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	t_stack	*set_node;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		node_b = b;
		while (node_b)
		{
			if(node_b->dataarg < a->dataarg && node_b->dataarg > best_index)
			{
				best_index = node_b->dataarg;
				set_node = node_b;
			}
			node_b = node_b->next;
		}
		if (node_b == LONG_MIN)
			a->node = ft_findmax(b);
		else
			a->node = set_node;
		a = a->next;
	}
}

static void	ft_analyse(t_stack *a, t_stack *b)
{
	int	count1;
	int	count2;

	count1 = ft_lstlen_ps(a);
	count2 = ft_lstlen_ps(b);
	while (a)
	{
		a->cost = a->index;
		if(!(a->up_median))
			a->cost = count1 - (a->index);
		if (a->node->up_median)
			a->cost += a->node->index;
		else
			a->cost += count2 - (a->node->index);
		a = a->next;
	}
}

void	ft_index(t_stack *stacks)
{
	int	i;
	int	med;

	i = 0;
	if (!stacks)
		return (NULL);
	med = ft_lstlen_ps(stacks) / 2;
	while (stacks)
	{
		stacks->index = i;
		if (i <= med)
			stacks->up_median = true;
		else
			stacks->up_median = false;
		stacks = stacks->next;
		i ++;
	}
}

void	ft_cheapest(t_stack *stacks)
{
	t_stack	*cheapest_node;
	long	value;

	if (!stacks)
		return (NULL);
	value = LONG_MAX;
	while (stacks)
	{
		if (stacks->cost < value)
		{
			value = stacks->cost;
			cheapest_node = stacks;
		}
		stacks = stacks->next;
	}
	cheapest_node->lowercost = true;
}

void	ft_init_nodesa(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_set_a(a, b);
	ft_analyse(a, b);
	ft_cheapest(a);
}

