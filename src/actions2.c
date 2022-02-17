/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:29:52 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:33:54 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	px(t_list **a, t_list **b, const char *msg)
{
	t_list	*tmp;

	if (!strcmp("pa\n", msg))
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		(*a) = (*b);
		(*b) = tmp;
	}
	else if (!strcmp("pb\n", msg))
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		(*b) = (*a);
		(*a) = tmp;
	}
	if (msg)
		ft_putstr_fd((char *) msg, STDOUT_FILENO);
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	exit(1);
}

void	*xalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		print_error_and_exit();
	return (ptr);
}

void	check_dup(int value, t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == value)
			print_error_and_exit();
		tmp = tmp->next;
	}
}
