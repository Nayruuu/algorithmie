/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-toda <sde-toda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 21:38:57 by sde-toda          #+#    #+#             */
/*   Updated: 2015/03/05 18:11:21 by sde-toda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define OPTS env->opts
# define MIN_S env->min
# define MAX_S env->max
# define SIZE env->size
# define COUNT env->count
# define ACTIONS env->actions

# define SA swap_a(a)
# define SB swap_b(b)
# define PA push_a(b, a)
# define PB push_b(a, b)
# define RA rotate_stacks(a, NULL)
# define RB rotate_stacks(NULL, b)
# define RRA rev_rotate_stacks(a, NULL)
# define RRB rev_rotate_stacks(NULL, b)

# define MSG "Nothing to be sorted\nusage: ./push_swap [INT_MIN : INT_MAX]"

# define MIN(x, y) x < y ? x : y
# define MAX(x, y) x > y ? x : y
# define SET_TAB(x) {x, x, x, x, x, x, x, x}

/*
**	Stack/
**			Stack Functions
*/

typedef struct		s_stack
{
	int				data;
	struct s_stack	*prev;
}					t_stack;

int					check_stack(t_stack *stack, int nbr);
void				print_stack(t_stack *stack);
void				stack_push(t_stack **stack, int data);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				push_a(t_stack **b, t_stack **a);
void				rotate_stacks(t_stack **a, t_stack **b);
void				rev_rotate_stacks(t_stack **a, t_stack **b);

/*
**	Env/
**			Env Functions
*/

typedef struct		s_env
{
	int				min;
	int				max;
	int				size;
	int				count;
	int				opts;
	int				actions[8];
}					t_env;

void				print_all(t_stack **a, t_stack **b);
void				print_actions(int action, int count, int opt);
void				choose_action(t_stack **a, t_stack **b, t_env *env,
		int act);

/*
**	Checking/
**			Checking Functions
*/

int					check_param(char *param);

/*
**	Algorithm/
**			Algorithm Functions
*/

void				check_end(t_stack **a, t_env *env);
int					check_a(t_stack *a);
int					check_first(t_stack **a, t_env *env);
int					check_last(t_stack *a);
int					check_rev_a(t_stack *a, int size);
int					get_min(t_stack *a);
int					check_position(t_stack *a, int min);
void				algorithm(t_stack *a, t_env *env);

#endif
