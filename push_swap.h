/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlongin <hlongin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:55:24 by hlongin           #+#    #+#             */
/*   Updated: 2025/08/11 17:50:07 by hlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* Instructions */
void				sa(t_stack **stacka);
void				sb(t_stack **stackb);
void				ss(t_stack **stacka, t_stack **stackb);
void				pa(t_stack **stacka, t_stack **stackb);
void				pb(t_stack **stacka, t_stack **stackb);
void				ra(t_stack **stacka);
void				rb(t_stack **stackb);
void				rr(t_stack **stacka, t_stack **stackb);
void				rra(t_stack **stacka);
void				rrb(t_stack **stackb);
void				rrr(t_stack **stacka, t_stack **stackb);
void				silent_rra(t_stack **stacka);
void				silent_rrb(t_stack **stackb);
void				silent_sa(t_stack **stacka);
void				silent_sb(t_stack **stackb);
void				silent_ra(t_stack **stacka);
void				silent_rb(t_stack **stacka);

/* Tri général */
void				dispatch_sort(t_stack **stacka, t_stack **stackb);
void				sort_two(t_stack **stacka);
void				sort_three(t_stack **stacka);
void				sort_four(t_stack **stacka, t_stack **stackb);
void				sort_five(t_stack **stacka, t_stack **stackb);
void				radix(t_stack **stacka, t_stack **stackb, int size);

/* Tri par chunk */
int					find_median_chunk(t_stack *stacka, int size);
int					fill_chunk_array(t_stack *stacka, int chunk_max,
						int *array);
void				bubble_sort(int *array, int size);
int					find_max_index(t_stack *stack);
int					get_position(t_stack *stack, int index);
int					has_chunk_element(t_stack *stacka, int chunk_max);

/* Stack utils */
void				ft_stack_add_back(t_stack **lst, t_stack *new);
t_stack				*ft_stack_last(t_stack *lst);
t_stack				*ft_new_stack(int content);
void				free_stack(t_stack *stack);
int					ft_stack_size(t_stack *lst);
int					find_pos(t_stack *tmp, int target);
void				assign_index(t_stack *stacka);
void				print_stack(t_stack *stack, const char *name);

/* Parsing */
t_stack				*ft_parsing(int argc, char **argv);
int					ft_aatoi(const char *str, long *out);
void				error(t_stack *stacka);
int					ft_isspace(char ch);
char				**ft_splitr(const char *s);
void				free_split(char **split);

#endif