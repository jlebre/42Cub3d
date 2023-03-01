/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:33:21 by jlebre            #+#    #+#             */
/*   Updated: 2023/03/01 14:24:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <dirent.h>

//LIBFT

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int		ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);

//GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_line(char *line, char *buf);
int		check_gnl(char *buf);

//FT_PRINTF

int		ft_printf(const char *c, ...);
int		ft_strlen_pf(const char *str);
int		ft_strchr_pf(const char *s, int c);
int		ft_putchar_fd_pf(char c, int fd);
int		ft_putstr_fd_pf(char *s, int fd);
int		ft_putnbr_fd_pf(int n, int k, int fd);
int		ft_putnbr_base_fd(unsigned int n, char *base, int k, int fd);
int		ft_putnbr_p_fd(unsigned long n, char *base, int k, int fd);
int		ft_putpointer_fd(unsigned long ptr, int fd);
int		ft_unsigned(unsigned int nb, int fd);

//
char	*ft_strjoin_without_newline(char *s1, char *s2);
char	*ft_strdup_without_newline(const char *str);
void	ft_remove_newline(char *str);

//
int		ft_strlen2(char *str, char c);
int		ft_isdigit(char c);
int		ft_isspace(char c);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif
