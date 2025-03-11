#include "./push_swap.h"

static void	ft_rotate(t_stack **stacks)
{
	t_stack *lstnode;

	if (!*stacks || !(*stacks)->next)
		return ;
	lstnode = ft_lstlast_ps(*stacks);
	lstnode->next = *stacks;
	*stacks = (*stacks)->next;
	(*stacks)->prev = NULL;
	lstnode->next->prev = lstnode;
	lstnode->next->next = NULL;
}
void	ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
