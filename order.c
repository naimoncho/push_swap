#include "push_swap.h"

int	ft_lstsize_ps(t_stack *lst)
{
	int	counter;
	t_stack *auxiliar;

	counter = 0;
	auxiliar = lst;
	if (!lst)
		return (0);
	while (auxiliar != NULL)
	{
		counter ++;
		auxiliar = auxiliar->next;
	}
	return (counter);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstlen_ps(t_stack *stacks)
{
	int i;

	i = 0;
	if (!stacks)
		return (0);
	while (stacks)
	{
		stacks = stacks->next;
		i ++;
	}
	return (i);
}

bool	ft_stackorder(t_stack *stacks)
{
	if (!stacks)
		return (1);
	while (stacks->next)
	{
		if (stacks->dataarg > stacks->next->dataarg)
			return (false);
		stacks = stacks->next;
	}
	return (true);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*node;

	node = ft_findmax(*a);
	if (node == *a)
		ra(a);
	else if(!(*a)->next == node)
		rra(a);
	if ((*a)->dataarg > (*a)->next->dataarg)
		sa(a);
}