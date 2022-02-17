/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:32:55 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:53:17 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	sort_4(t_list **a, t_list **b)
{
	int	min;

	min = get_min(a);
	assign_index(a);
	move_to_top(get_index(min, a), a, b);
	px(a, b, "pb\n");
	sort_3(a);
	px(a, b, "pa\n");
}

void	sort_5(t_list **a, t_list **b)
{
	int	min;

	min = get_min(a);
	assign_index(a);
	move_to_top(get_index(min, a), a, b);
	px(a, b, "pb\n");
	sort_4(a, b);
	px(a, b, "pa\n");
}

void	cp(int *arr, t_list **a)
{
	t_list	*tmp;
	int		*cp;

	tmp = *a;
	cp = arr;
	while (tmp)
	{
		*arr = tmp->content;
		tmp = tmp->next;
		arr += 1;
	}
}

int	is_empty(t_list **a)
{
	if (!*a)
		return (1);
	return (0);
}

void	move_to_top_b(int pos, t_list **a)
{
	while (pos < 0)
	{
		rrx(a, "rrb\n");
		pos += 1;
	}
	while (pos > 0)
	{
		rx(a, "rb\n");
		pos -= 1;
	}
}
