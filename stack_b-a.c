#include "push_swap.h"

static void	ft_set_b(t_stack *a, t_stack *b)
{
	t_stack	*node_a;
	t_stack	*set_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MIN;
		node_a = a;
		while (node_a)
		{
			if(node_a->dataarg < b->dataarg && node_a->dataarg > best_index)
			{
				best_index = node_a->dataarg;
				set_node = node_a;
			}
			node_a = node_a->next;
		}
		if (node_a == LONG_MIN)
			b->node = ft_findmax(b);
		else
			b->node = set_node;
		b = b->next;
	}
}
void	ft_init_nodesb(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_set_b(a, b);
}
