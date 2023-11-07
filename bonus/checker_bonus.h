/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:40 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:47:39 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <unistd.h>

# define BUFFER_SIZE 2000

typedef struct s_file_info
{
	int		fd;
	char	*content;
	int		eof;
}			t_file_info;

typedef struct s_array
{
	int		*a;
	int		l;
}			t_array;

typedef struct s_stacks
{
	t_array	*a;
	t_array	*b;
	t_array	*map;
}			t_stacks;

// gnl
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);

// checker_utils_bonus.c
int			init_stacks(t_stacks *stacks, t_array a_map, int size);
void		free_stacks(t_stacks stacks);
int			*populate_input_array(char **vals, int size);
int			apply_operation(t_stacks stack, char *operation);
int			*parse_input(int *argc, char *argv[]);

// libft_bonus.c
t_array		*ft_arrnew(int max_size);
void		ft_arrfree(t_array *array);
t_array		*ft_arrclone(t_array *arr);
void		ft_arrrev(t_array *array);
void		reverse_array(int *arr, int len);

// libft_bonus2.c
void		ft_putstr_fd(const char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_arrindexof(t_array *arr, int n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_arrissorted(t_array *stack);

// libft_bonus3.c
t_array		*ft_iarrsort(t_array *array, int desc);
t_array		*ft_arrsort(t_array *arr);
t_array		*ft_arrisort(t_array *arr);
int			ft_iarrissorted(t_array *stack, int desc);
int			ft_atoi_mod(char *nptr);

// push_swap_utils.c
int			p(t_array *dest, t_array *src);
int			rrr(t_array *stack_a, t_array *stack_b);
void		ft_free_split(char **vals, int size);
void		ft_arrshftr(t_array *stack);
void		ft_arrshftl(t_array *stack);

// push_swap_utils2.c
char		**ft_split(char const *s, char c);

// push_swap_utils3.c
char		*concat_argc(char **arr, int size);

// push_swap_utils4.c
int			rr(t_array *stack);
int			r(t_array *stack);
int			s(t_array *stack);
int			r_all(t_array *stack_a, t_array *stack_b);
int			ss(t_array *stack_a, t_array *stack_b);

#endif
