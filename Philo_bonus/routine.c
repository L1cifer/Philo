/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:58:24 by atakeddi          #+#    #+#             */
/*   Updated: 2022/06/25 11:45:22 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	pthread_create(&philo->thread, NULL, (void *)check_death, philo);
	while (!philo->rules->dead)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	if (philo->eated == 1)
		exit(1);
	return (NULL);
}

void	sema_init(t_rules *all)
{
	sem_unlink("fork");
	sem_unlink("print");
	all->forks = sem_open("fork", O_CREAT, 666, \
			all->num_philo);
	all->print = sem_open("print", O_CREAT, 666, 1);
}
