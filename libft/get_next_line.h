/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakkus <sakkus@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:37:46 by sakkus            #+#    #+#             */
/*   Updated: 2022/09/09 21:40:05 by sakkus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

size_t	ft_strlen(char *str);
char	*ft_buff(int fd, char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, int c);
char	*ft_get_line(char *str);
char	*ft_last_str(char *str);
#endif
