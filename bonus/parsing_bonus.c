/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:08:56 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/09 08:06:53 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_sign(int *i, long *sign, char *num)
{
	if (num[*i] == '+')
		(*i)++;
	if (num[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
}

int	checknum(char *num)
{
	int		i;
	long	sign;
	long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (num[i] > 9 && num[i] < 13)
		return (1);
	while (num[i] == ' ')
		i++;
	if (num[i] == '\0')
		return (1);
	ft_sign(&i, &sign, num);
	if (num[i] == '\0')
		return (1);
	while (num[i] >= '0' && num[i] <= '9')
		res = res * 10 + num[i++] - '0';
	if ((num[i] < '0' || num[i] > '9') && num[i] != '\0')
		return (1);
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		return (1);
	return (0);
}

int	checklist(int argc, char **argv, t_list **stack)
{
	char	**list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		list = ft_split(argv[i], ' ');
		if (!list[0])
			return (ft_lstclear(stack, free), free(list), 1);
		j = 0;
		while (list[j])
		{
			if (checknum(list[j]) || implement(stack, ft_atoi(list[j])))
				return (ft_lstclear(stack, free), free(list), free(list[j]), 1);
			free(list[j]);
			j++;
		}
		free(list);
		list = NULL;
	}
	return (0);
}
