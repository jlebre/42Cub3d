/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:21:08 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/30 17:32:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include <str.h>
# include <allocs.h>

int		ft_strlen(char *str, char c);
char	*ft_strrchr(char *str, char c);
char	*ft_strchr(char *str, char c);
int		isdig(char c);
int		ft_isspace(char c);
char	*strtrim(char *s1, char *set);
long	_atoi(char *s);
char	*itoa(char *str, int *maxdig, int counter, int n);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strnstr(char *big, char *little, size_t len);
int		ft_isalnum(char c);
char	*ft_strdup(char *s);
char	*strjoin(char *s1, char *s2);
int		ft_ischar(char c);

#endif
