/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:23:08 by lucifer           #+#    #+#             */
/*   Updated: 2022/06/22 16:54:52 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	while (1)
	{
		if (current_time() - philo->last_meal >= philo->rules->time_to_die)
		{
			print_status(philo, 0, "is dead\n");
			break ;
		}
		else if (philo->rules->check_meals == philo->rules->num_philo)
		{
			print_status(philo, 0, "finish\n");
			break ;
		}
		else if (philo->next == NULL)
			philo = philo->rules->head;
		else
			philo = philo->next;
	}
}

void	print_status(t_philo *philo, int n, char *str)
{
	long long	time;

	pthread_mutex_lock (&philo->rules->mutex);
	time = current_time() - philo->rules->begin_time;
	printf ("%lld %d %s", time, philo->philo_id, str);
	if (n)
		pthread_mutex_unlock(&philo->rules->mutex);
}
