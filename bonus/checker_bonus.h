/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:40 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/04 07:49:45 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
}					t_moves;

typedef struct s_array
{
	int				*a;
	int				l;
}					t_array;

typedef struct s_stacks
{
	t_array			*a;
	t_array			*b;
	t_array			*map;
}					t_stacks;

int					extract_digit(int number, int digit, int n_base);
int					contains_dgt_grp(t_array *stack, int digit_grp, int digit,
						int n_base);
int					fix_stack_shift(t_array *stack, t_array *map, char label);
int					sort_small_map(t_array *stack_a, t_array *stack_b);
int					sort_smallest_map(t_array *stack);
void				free_stacks(t_stacks *stacks);
t_stacks			*init_stacks(t_array *a_map, int size);
int					*parse_input(int *argc, char *argv[]);
int					head(t_array *stack, int d);

void				ft_arrfree(t_array *array);
void				ft_arrrev(t_array *array);
t_array				*ft_arrnew(int max_size);
void				ft_arrfree(t_array *array);
t_array				*ft_arrclone(t_array *arr);
void				free_stacks(t_stacks *stacks);
static void	ft_free_split(char **vals, int size);
static int	ft_atoi_mod(char *nptr);
void	reverse_array(int *arr, int len);

void				ft_putstr_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_arrissorted(t_array *stack);
static int			ft_atoi_mod(char *nptr);
static void			ft_free_split(char **vals, int size);
static int			*populate_input_array(char **vals, int size);
int					*parse_input(int *argc, char *argv[]);
char				*concat_argc(char **arr, int size);
char				**ft_split(char const *s, char c);

t_stacks			*init_stacks(t_array *a_map, int size);
int					ft_strcmp(const char *s1, const char *s2);
t_moves				*ft_lstnew(char *content);
int					ft_lstsize(t_moves *lst);
void				ft_lstadd_back(t_moves **lst, t_moves *new);
t_moves				*ft_lstlast(t_moves *lst);
void				ft_lstclear(t_moves **lst, void (*del)(void *));
void				ft_lstdelone(t_moves *lst, void (*del)(void *));
int					ft_strcmp(const char *s1, const char *s2);
int					rr(t_array *stack, char label);
int					r(t_array *stack, char label);
int					s(t_array *stack, char label);
int					p(t_array *dest, t_array *src, char label);
t_array				*normalize_input(int *array, int size);
int					ipow(int n, int power);
void				reverse_array(int *arr, int len);
char				*concat_argc(char **arr, int size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
int					ft_arrfinds(t_array *arr);
void				ft_arrshftr(t_array *stack);
t_array				*ft_arrsort(t_array *array);
t_array				*ft_arrisort(t_array *arr);
int					ft_arrissorted(t_array *stack);
int					ft_arriscsorted(t_array *stack);
int					ft_arrindexof(t_array *arr, int n);
int					ft_arrfindl(t_array *arr);
void				ft_arrshftl(t_array *stack);
void				ft_arrrev(t_array *array);
t_array				*ft_arrclone(t_array *arr);
void				ft_arrfree(t_array *array);
t_array				*ft_arrnew(int max_size);
char				**ft_split(char const *s, char c);

/** DEBUG */
void				printArray(char *label, int *array, int size);
#endif
