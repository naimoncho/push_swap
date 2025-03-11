#include "./push_swap.h"

static void	ft_swap(t_stack **top)
{
	t_stack *first;
	t_stack *second;

	if (!*top || !(*top)->next)
		return ;
	first = *top;
	second = (*top)->next;
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*top = second;
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
