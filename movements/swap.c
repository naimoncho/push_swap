#include "push_swap.h"

static void	ft_swap(t_stack **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->prev->prev;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

void	sa(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
