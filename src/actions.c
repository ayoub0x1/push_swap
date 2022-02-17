/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:53:03 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:42:42 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	sx(t_list **a, const char *msg)
{
	int	tmp;

	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (msg)
		ft_putstr_fd((char *) msg, STDOUT_FILENO);
}

t_list	*get_last_element(t_list **a)
{
	t_list	*tmp;

	if (!a || !*a)
		return (0x0);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	count_elements(t_list **a)
{
	int		size;
	t_list	*tmp;

	if (!a || !*a)
		return (0x0);
	tmp = *a;
	size = 0;
	while (tmp)
	{
		size += 1;
		tmp = tmp->next;
	}
	return (size);
}

void	rrx(t_list **a, const char *msg)
{
	t_list	*last;
	int		size;

	size = count_elements(a) - 1;
	last = get_last_element(a);
	if (last->content != (*a)->content)
	{
		last->next = *a;
		*a = last;
		while (size--)
			last = last->next;
		last->next = 0x0;
	}
	if (msg)
		ft_putstr_fd((char *) msg, STDOUT_FILENO);
}

void	rx(t_list **a, const char *msg)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *a;
	*a = (*a)->next;
	last = get_last_element(a);
	tmp->next = 0x0;
	last->next = tmp;
	if (msg)
		ft_putstr_fd(msg, STDOUT_FILENO);
}
