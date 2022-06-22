/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:32:31 by marvin            #+#    #+#             */
/*   Updated: 2022/06/06 15:32:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac,char **av)
{
	t_philo	*philo;
	t_rules	info;

	philo = NULL;
	//info = malloc(sizeof(t_rules));
	if(!check_args(ac,av,&info))
		return(1);
	init_philo(&info, philo);
	//philo->thread = malloc(sizeof(pthread_t *) * info->num_philo);
	//info->fork = malloc(sizeof(pthread_mutex_t *) *info->num_philo);
}