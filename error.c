#include "push_swap.h"

void	ft_errors_free(t_stack **a)
{
	ft_free_stacks(a);
	write(1, "Error\n", 6);
	exit(1);
}

int ft_syntax(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if (!(*s == '+' || *s == '-' || (s[1] >= '0' && s[1] <= '9')))
		return (1);
		while (*s++)
		{
			if (!(*s >= '0' && *s <= '9'))
				return (1);
		}
	return (0);
}

void	ft_free_stacks(t_stack **stacks)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stacks)
		return ;
	current = *stacks;
	while (current)
	{
		temp = current->next;
		current->dataarg = 0;
		free(current);
		current = temp;
	}
	*stacks = NULL;
}

int	ft_duplicates(t_stack *s, int nbr)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->dataarg == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}
