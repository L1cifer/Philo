/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:13:03 by marvin            #+#    #+#             */
/*   Updated: 2022/06/09 16:13:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av, t_rules *info)
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Invalid args\n", 14);
		return (0);
	}
	info->num_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat = -1;
	info->check_meals = 0;
	pthread_mutex_init(&info->mutex, NULL);
	info->dead = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (info->num_philo < 1 || info->time_to_die < 1 || info-> time_to_eat < 1
		|| info->time_to_sleep < 1 || (ac == 6 && info->must_eat < 1))
	{
		write(2, "Invalid args\n", 14);
		return (0);
	}
	return (1);
}

void	eating(t_philo	*philo)
{
	t_philo	*right_fork;

	if (philo->next != NULL)
		right_fork = philo->next;
	else if (philo->next == NULL)
		right_fork = philo->rules->head;
	pthread_mutex_lock(&philo->fork);
	print_status(philo, 1, "is has taken a fork\n");
	pthread_mutex_lock(&right_fork->fork);
	print_status(philo, 1, "is has taken a fork\n");
	philo->last_meal = current_time();
	print_status(philo, 1, "is eating\n");
	ft_sleep(philo->rules->time_to_eat);
	philo->eaten++;
	if (philo->eaten == philo->rules->must_eat)
		philo->rules->check_meals++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&right_fork->fork);
}

void	sleeping(t_philo	*philo)
{
	print_status(philo, 1, "is sleeping\n");
	ft_sleep(philo->rules->time_to_sleep);
}

void	thinking(t_philo	*philo)
{
	print_status(philo, 1, "is thinking\n");
}

void	init_philo(t_rules *info, t_philo *philo)
{
	int		i;
	t_philo	*lst;

	i = 1;
	lst = NULL;
	info->begin_time = current_time();
	info->check_meals = 0;
	while (i <= info->num_philo)
	{
		lst = ft_lstnew(i, info);
		ft_lstadd_back(&philo, lst);
		i++;
	}
	i = 0;
	info->head = philo;
	lst = philo;
	while (i < info->num_philo)
	{
		pthread_create(&lst->thread, NULL, routine, lst);
		lst = lst->next;
		i++;
	}
	lst = philo;
	check_death(philo);
}
