#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split_ps(argv[1], ' ');
	ft_stack_in(&a, argv + 1);
	if (!ft_stackorder(a))
	{
		if (ft_lstlen_ps(a) == 2)
			sa(&a);
		else if (ft_lstlen_ps(a) == 3)
			ft_sort_three(&a);
		else
			ft_sort_stacks(&a, &b);
	}
	ft_free_stacks(&a);
	return (0);
}