/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <aymoulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:49:46 by aymoulou          #+#    #+#             */
/*   Updated: 2022/02/17 01:50:40 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

void	sx(t_list **a, const char *msg);
t_list	*get_last_element(t_list **a);
int		count_elements(t_list **a);
void	rrx(t_list **a, const char *msg);
t_list	*get_last_element(t_list **a);
int		count_elements(t_list **a);
void	rx(t_list **a, const char *msg);
void	px(t_list **a, t_list **b, const char *msg);
int		is_sorted(t_list **a);
void	sort(t_list **a, t_list **b);
void	sort_2(t_list **a);
void	sort_3(t_list **a);
int		get_max(t_list **a);
int		get_min(t_list **a);
void	*xalloc(size_t size);
void	print_error_and_exit(void);
void	check_dup(int value, t_list **stack_a);
void	assign_index_sorted(int *arr, t_list **a, int size);
void	move_to_top(int pos, t_list **a, t_list **b);
void	assign_index(t_list **a);
int		get_index(int nb, t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	sort_all(t_list **a, t_list **b);
void	cp(int *arr, t_list **a);
void	bubble_sort(int *arr, int size);
int		is_empty(t_list **a);
void	move_to_top_b(int pos, t_list **a);
void	push_half(t_list **a, t_list **b, int *size);
int		count_elements(t_list **a);
#endif