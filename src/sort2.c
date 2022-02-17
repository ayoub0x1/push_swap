/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 01:36:20 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:37:21 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	sort(t_list **a, t_list **b)
{
	int	len;

	len = count_elements(a);
	if (is_sorted(a))
		exit(0);
	if (len == 2)
		sort_2(a);
	else if (len == 3)
		sort_3(a);
	else if (len == 4)
		sort_4(a, b);
	else if (len == 5)
		sort_5(a, b);
	else
		sort_all(a, b);
}

void	sort_2(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		sx(a, "sa\n");
}

void	sort_3(t_list **a)
{
	int	max;

	if (is_sorted(a))
		return ;
	max = get_max(a);
	if (max == (*a)->content)
		rx(a, "ra\n");
	else if (max == (*a)->next->content)
		rrx(a, "rra\n");
	if ((*a)->content > (*a)->next->content)
		sx(a, "sa\n");
}

void	sort_all(t_list **a, t_list **b)
{
	int	*arr;
	int	*tmp;
	int	size;

	size = count_elements(a);
	arr = xalloc(sizeof(int) * size);
	tmp = arr;
	cp(arr, a);
	bubble_sort(arr, size);
	assign_index_sorted(arr, a, size);
	while (count_elements(a) > 5 && !is_sorted(a) && size > 1)
	{
		push_half(a, b, arr + (count_elements(a) / 4));
		arr = arr + (count_elements(a) / 4);
	}
	sort_5(a, b);
	while (!is_empty(b))
	{
		move_to_top_b(get_index(get_max(b), b), b);
		px(a, b, "pa\n");
	}
	free(tmp);
}
