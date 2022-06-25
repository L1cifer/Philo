/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:23:08 by lucifer           #+#    #+#             */
/*   Updated: 2022/06/25 11:49:08 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo)
{
	int		res;

	res = 0;
	while (1)
	{
		if (current_time() - philo->last_meal >= philo->rules->time_to_die)
		{
			exit(0);
		}		
		else if (philo->eaten == philo->rules->must_eat)
		{
			philo->eated = 1;
			philo->rules->dead = 1;
			return ;
		}
	}
}

void	print_status(t_philo *philo, int n, char *str)
{
	long long	time;

	sem_wait(philo->rules->print);
	time = current_time() - philo->rules->begin_time;
	printf ("%lld %d %s", time, philo->philo_id, str);
	if (n)
		sem_post(philo->rules->print);
}

void	kill_this_mf(t_philo *philo)
{
	int		res;
	t_philo	*node;

	res = 0;
	node = philo;
	while (philo)
	{
		waitpid(-1, &res, 0);
		if (res == 0)
		{
			while (node)
			{
				kill(node->pid, SIGKILL);
				node = node->next;
			}
			print_status(philo, 0, "is dead\n");
			ft_free(philo);
			return ;
		}
		else
			philo = philo->next;
	}
}
