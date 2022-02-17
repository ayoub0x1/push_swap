/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:22:07 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:51:15 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	assign_index(t_list **a)
{
	int		va;
	t_list	*tmp;

	tmp = *a;
	va = 0;
	while (tmp)
	{
		tmp->index = va++;
		tmp = tmp->next;
	}
}

int	get_index(int nb, t_list **a)
{
	t_list	*tmp;

	assign_index(a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->content == nb)
		{
			if (tmp->index < count_elements(a) / 2)
				return (tmp->index);
			else
				return (tmp->index - count_elements(a));
		}
		tmp = tmp->next;
	}
	return (0);
}

void	move_to_top(int pos, t_list **a, t_list **b)
{
	(void)b;
	while (pos < 0)
	{
		rrx(a, "rra\n");
		pos += 1;
	}
	while (pos > 0)
	{
		rx(a, "ra\n");
		pos -= 1;
	}
}
