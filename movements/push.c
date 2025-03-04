#include "push_swap.h"

static void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack *push;

	if (!*src)
		return (NULL);
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
	if (!dest)
	{
		*dest = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->next->prev = push;
		*dest = push;
	}
}

void	pa(t_stack **a,t_stack **b)
{
	ft_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a,t_stack **b)
{
	ft_push(b, a);
	write(1, "pb\n", 3);	
}
