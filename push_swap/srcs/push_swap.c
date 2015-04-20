/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:41:43 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/19 17:43:53 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_opts(int argc, char **argv, int *opts)
{
	int				i;

	i = 1;
	while (i < argc && (ft_strequ(argv[i], "-c") || ft_strequ(argv[i], "-v") ||
			ft_strequ(argv[i], "-vc") || ft_strequ(argv[i], "-cv") ||
			ft_strequ(argv[i], "--print")))
	{
		if (ft_strequ(argv[i], "-c"))
			*opts |= 0x01;
		else if (ft_strequ(argv[i], "-v"))
			*opts |= 0x02;
		else if (ft_strequ(argv[i], "-vc") || ft_strequ(argv[i], "-cv"))
			*opts |= 0x03;
		else if (ft_strequ(argv[i], "--print"))
			*opts |= 0x04;
		i++;
	}
	return (i - 1);
}

int					main(int argc, char **argv)
{
	int				i;
	int				nbr;
	t_env			*env;
	t_stack			*a;

	i = 0;
	a = NULL;
	env = (t_env*)ft_xmalloc(sizeof(t_env));
	i = get_opts(argc, argv, &OPTS);
	*env = (t_env){2147483647, -2147483648, argc - i - 1, 0, OPTS, SET_TAB(0)};
	while (++i < argc)
	{
		if (!check_param(argv[i]))
			exit(!ft_putendl_fd("Error", 2));
		nbr = ft_atoi(argv[i]);
		if (a && !check_stack(a, nbr))
			exit(!ft_putendl_fd("Error", 2));
		stack_push(&a, nbr);
		MIN_S = MIN(nbr, MIN_S);
		MAX_S = MAX(nbr, MAX_S);
	}
	a ? algorithm(a, env) : ft_putendl(MSG);
	return (0);
}
