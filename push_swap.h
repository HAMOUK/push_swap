/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:24 by hlongin           #+#    #+#             */
/*   Updated: 2025/05/26 16:05:52 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int		content;
	struct s_stack *next;
}	t_stack;

void    sb(t_stack *stackb);
void    sa(t_stack *stacka);
void	ss(t_stack **stacka, t_stack **stackb);
void	pa(t_stack **stacka, t_stack **stackb);
void	pb(t_stack **stacka, t_stack **stackb);
void	rra(t_stack **stacka);
void	rrb(t_stack **stackb);
void	rrr(t_stack **stacka, t_stack **stackb);
void	ra(t_stack **stacka);
void	rb(t_stack **stackb);
void	rr(t_stack **stacka, t_stack **stackb);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
int 	ft_parsing(int argc, char **argv);
int	ft_stack_size(t_stack *lst);
t_stack	*ft_new_stack(int content);
t_stack	*ft_stack_last(t_stack *lst);
t_stack		*fill_stack(int argc, char **argv);
long	ft_aatoi(const char *str);

#endif