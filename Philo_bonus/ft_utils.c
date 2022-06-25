/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:46:49 by marvin            #+#    #+#             */
/*   Updated: 2022/06/09 15:46:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i++] - 48;
	if (str[i] != '\0')
		return (0);
	return (sign * n);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_philo	*ft_lstnew(int i, t_rules *info)
{
	t_philo	*ptr;

	ptr = (t_philo *)malloc(sizeof(t_philo));
	if (!ptr)
		return (NULL);
	ptr->philo_id = i;
	ptr->eaten = 0;
	ptr->eated = 0;
	ptr->rules = info;
	ptr->next = NULL;
	return (ptr);
}

void	init_philo2(t_philo *lst, t_rules *info)
{
	int	i;

	i = 0;
	while (i < info->num_philo)
	{
		lst->pid = fork();
		if (lst->pid < 0)
			return ;
		if (lst->pid == 0)
		{
			lst->last_meal = current_time();
			routine(lst);
		}
		else
		{
			lst = lst->next;
			i++;
		}
	}
}
