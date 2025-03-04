#include "push_swap.h"

static long		ft_atol_ps(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		str ++;
	}
	return (num * sign);
}
void	ft_join_node(t_stack **stacks, int n)
{
	t_stack	*node;
	t_stack	*final_node;

	if (!stacks)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->dataarg = n;
	if (!(*stacks))
	{
		*stacks = node;
		node->prev = NULL;
	}
	else
	{
		final_node = ft_lstlast_ps(*stacks);
		final_node->next = node;
		node->prev = final_node;
	}
}

void	ft_stack_in(t_stack **args, char **argv)
{
	long	nbr;
	int		j;

	j = 0;
	while (argv[j])
	{
		if (ft_syntax(argv[j]))
			ft_errors_free(args);
		nbr = ft_atol_ps(argv[j]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_errors_free(args);
		if (ft_duplicates(*args, (int)nbr))
			ft_errors_free(args);
		ft_join_node(args, (int)nbr);
		j ++;
	}
}