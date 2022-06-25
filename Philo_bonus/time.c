/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:02:38 by atakeddi          #+#    #+#             */
/*   Updated: 2022/06/22 16:49:50 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	time_passed(long long start_time)
{
	long long		elapsed_time;
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	elapsed_time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000) - start_time;
	return (elapsed_time);
}

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(int time)
{
	long long	t;

	t = current_time();
	while (current_time() - t < time)
		usleep(100);
}
