#include "push_swap.h"

static void	ft_order_min_max(t_stack **a)
{
	while ((*a)->dataarg != ft_findmin(*a)->dataarg)
	{
		if(ft_findmin(*a)->up_median)
			ra(a);
		else
			rra(a);
	}
}

static void	ft_rboth(t_stack **a, t_stack **b, t_stack *lower)
{
	while (*b != lower->node && *a != lower)
		rr(a, b);
	ft_index(*a);
	ft_index(*b);
}

static void	ft_rrboth(t_stack **a, t_stack **b, t_stack *lower)
{
	while (*b != lower->node && *a != lower)
		rrr(a, b);
	ft_index(*a);
	ft_index(*b);
}

static void	ft_movea(t_stack **a, t_stack **b)
{
	t_stack	*lowernode;

	if (!a || !*a || !b) 
		return ;
	lowernode = ft_lowercost(*a);
	if (!lowernode || !lowernode->node)
		return ;
	if (lowernode->up_median && lowernode->node->up_median)
		ft_rboth(a, b, lowernode);
	else if (!(lowernode->up_median) && !(lowernode->node->up_median))
		ft_rrboth(a, b, lowernode);
	ft_preppush(a, lowernode, 'a');
	ft_preppush(b, lowernode->node, 'b');
	pb(b, a);
}

static void	ft_moveb(t_stack **a, t_stack **b)
{
	ft_preppush(a, (*b)->node, 'a');
	pa(a, b);
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	i;

	i = ft_lstlen_ps(*a);
	if (i-- > 3 && !ft_stackorder(*a))
		pb(b, a);
	if (i-- > 3 && !ft_stackorder(*a))
		pb(b, a);
	while (i-- > 3 && !ft_stackorder(*a))
	{
		ft_init_nodesa(*a, *b);
		ft_movea(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodesb(*a, *b);
		ft_moveb(a, b);
	}
	ft_index(*a);
	ft_order_min_max(a);
}