/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:15:27 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/25 19:53:57 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

static char *ft_next_stash(char *stash)
{
	size_t	size;
	char	*res;
	char	*stash_temp;
	int		i;

	i=0;
	stash_temp = ft_strchr(stash, '\n') + 1;
	size = ft_strlen(stash_temp);
	res = malloc(size + 1);
	if (!res)
		return(NULL);
	while (stash_temp[i])
	{
		res[i] = stash_temp[i];
		i++;
	}
	free(stash);
	return(res);
}
static char *ft_edit_stash(char *stash, char *li)
{
	char	*line;
	int		size;
	int 	i;

	i = 0;
	size = ft_strchr(stash, '\n') - stash + 1;
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	line[size] = '\0';
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	stash = ft_next_stash(stash);
	li = line;
	return(stash);
}

static char	*ft_readline(int fd, char *stash)
{
	char	*buff;
	int		bytes_read;

	buff= malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_read = 1;

	while(!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		if (!stash)
			stash=ft_strdup(buff);
		else
			stash = ft_strjoin(stash, buff);
		free(buff);
	}
	return (stash);
}
char    *get_next_line(int fd)
{
    static char *stash;
    char *line;
	
	line = NULL;
	stash = ft_readline(fd, stash);
	stash = ft_edit_stash(stash,line);
    return(line);
}