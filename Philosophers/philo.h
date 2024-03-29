/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atakeddi <atakeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:31:19 by atakeddi          #+#    #+#             */
/*   Updated: 2022/06/22 16:46:09 by atakeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_rules
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	int					finished_philo;
	int					dead;
	struct s_philo		*head;
	long long			begin_time;
	pthread_mutex_t		mutex;
	int					check_meals;

}	t_rules;
typedef struct s_philo
{
	int					philo_id;
	long long			last_meal;
	pthread_mutex_t		fork;
	struct s_rules		*rules;
	pthread_t			thread;
	struct s_philo		*next;
	int					eaten;
}	t_philo;

int			ft_atoi(const char *str);
int			check_args(int ac, char **av, t_rules *info);
int			init_info(t_rules *info);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_lstnew(int i, t_rules *info);
void		init_philo(t_rules *info, t_philo *philo);
int			checkargs(int ac, char **av, t_rules *info);
void		eating(t_philo	*philo);
void		sleeping(t_philo	*philo);
void		thinking(t_philo	*philo);
void		*routine(void	*philos);
long long	time_passed(long long start_time);
long long	current_time(void);
void		ft_sleep(int time);
void		check_death(t_philo *philo);
void		print_status(t_philo *philo, int n, char *str);

#endif