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

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_rules	info;
	int		i;

	philo = NULL;
	i = 1;
	while (av[i])
	{
		if (!ft_atoi(av[i]))
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	if (!check_args (ac, av, &info))
		return (1);
	init_philo (&info, philo);
}
