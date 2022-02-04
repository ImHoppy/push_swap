#include "push_swap.h"

int	ft_strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			i++;
		else if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

void	error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	if (stacks == NULL)
		exit(EXIT_FAILURE);
	if (stacks->a != NULL)
		ft_stackclear(&stacks->a);
	if (stacks->b != NULL)
		ft_stackclear(&stacks->b);
	if (stacks->result != NULL)
		ft_lstclear(&stacks->result, NULL);
	free(stacks);
	exit(EXIT_FAILURE);
}
