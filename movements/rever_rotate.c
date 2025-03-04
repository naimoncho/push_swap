#include "push_swap.h"

static void	ft_rever_rotate(t_stack **stacks)
{
	t_stack *lstnode;

	if (!*stacks || !(*stacks)->next)
		return ;
	lstnode = ft_lstlast_ps(*stacks);
	lstnode->prev->next = NULL;
	lstnode->next = *stacks;
	lstnode->prev = NULL;
	*stacks = lstnode;
	lstnode->next->prev = lstnode;
}

void	rra(t_stack **a)
{
	ft_rever_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	ft_rever_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_rever_rotate(a);
	ft_rever_rotate(b);
	write(1, "rrr\n", 4);
}

