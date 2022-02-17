/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:20:50 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:40:09 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			j += 1;
		}
		i += 1;
	}
}

void	assign_index_sorted(int *arr, t_list **a, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *a;
	(void)size;
	while (tmp)
	{
		i = 0;
		while (tmp->content != arr[i])
			i += 1;
		tmp->index_sorted = i;
		i = 0;
		tmp = tmp->next;
	}
}

void	push_half(t_list **a, t_list **b, int *size)
{
	int		tmp_size;
	t_list	*tmp;

	tmp_size = count_elements(a) / 2;
	while (tmp_size--)
	{
		tmp = *a;
		assign_index(a);
		while (tmp)
		{
			if (tmp->content < *size)
				break ;
			tmp = tmp->next;
		}
		if (tmp)
		{
			move_to_top(get_index(tmp->content, a), a, b);
			px(a, b, "pb\n");
		}
	}
}
