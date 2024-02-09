/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:46:19 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/09 07:52:00 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!stack || !*stack || ft_lstsize(*stack) == 1)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write(1, "sa\n", 3);
}

void	swapb(t_list **stack)
{
	int	tmp;

	if (!stack || !*stack || ft_lstsize(*stack) == 1)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_list **stack1, t_list **stack2)
{
	swap(stack1);
	swap(stack2);
}
