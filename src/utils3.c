/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:39:34 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:40:30 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int	is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_max(t_list **a)
{
	t_list	*tmp;
	int		max;

	tmp = *a;
	max = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_list **a)
{
	t_list	*tmp;
	int		min;

	tmp = *a;
	min = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
