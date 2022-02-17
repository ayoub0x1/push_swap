/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:29 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:32:21 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

char	*join_arguments(char **av, int ac)
{
	char		*str;
	char		*tmp;
	char		*tmp2;
	int			i;

	i = 1;
	str = 0x0;
	tmp = 0x0;
	tmp2 = 0x0;
	while (i < ac)
	{	
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		tmp2 = ft_strjoin(str, " ");
		free(str);
		str = tmp2;
		i += 1;
	}
	return (str);
}

char	**get_data(char **av, int ac)
{
	char		*str;
	char		**data;

	str = join_arguments(av, ac);
	data = ft_split(str, ' ');
	free(str);
	return (data);
}

int	check_for_errors(char **data, int *i, int *j, long *res)
{
	int	mul;

	mul = 1;
	while (data[*i][*j])
	{
		if (data[*i][*j] == '-' && *j == 0)
		{
			mul = -1;
			*j += 1;
		}
		if (!isdigit(data[*i][*j]))
			print_error_and_exit();
		else if (isdigit(data[*i][*j]))
			*res = *res * 10 + data[*i][*j] - 48;
		*j += 1;
		if (*j > 11)
			print_error_and_exit();
	}
	return (mul);
}

t_list	**parse(char **data, t_list **stack_a)
{
	int		i;
	int		j;
	int		mul;
	long	res;

	i = 0;
	while (data[i])
	{
		j = 0;
		res = 0;
		mul = 1;
		mul = check_for_errors(data, &i, &j, &res);
		if ((res > INT_MAX && mul == 1) || (res > INT_MIN && mul == -1))
			print_error_and_exit();
		else
		{
			if (mul == -1)
				res = -res;
			check_dup((int) res, stack_a);
			ft_lstadd_back(stack_a, ft_lstnew(res));
		}
		i += 1;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	char	**data;
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		exit(0);
	stack_a = xalloc(sizeof(t_list *));
	stack_b = xalloc(sizeof(t_list *));
	*stack_a = 0x0;
	*stack_b = 0x0;
	data = get_data(av, ac);
	stack_a = parse(data, stack_a);
	sort(stack_a, stack_b);
}
