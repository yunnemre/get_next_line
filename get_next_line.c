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

static char *return_temp()
char    *get_next_line(int fd)
{
    static char *stash;
    char *line;
    char *buffer;
    //size_t bytes_read;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    return (NULL);
    line = (char *)calloc(sizeof(char),BUFFER_SIZE + 1);
    if (!line)
        return (0);
    if (stash)
    {
        if (ft_strchr(stash,'\n'))
        {
            ft_strlcpy(line, stash, ft_strchr(stash, '\n') - stash + 1);

            stash = ft_strchr(stash,'\n') + 1;
            return (line);
        }
        ft_strlcpy(line, stash, ft_strchr(stash, '\n') - stash + 1);
    }
    while(read(fd,buffer,BUFFER_SIZE))
    {
        if (ft_strchr(buffer,'\n'))
        {
            stash = ft_strdup(ft_strchr(buffer, '\n') + 1);
            buffer[ft_strchr(buffer, '\n') - buffer + 1] = '\0';
            line = ft_strjoin(line,buffer);
			free(buffer);
            return (line);
        }
		line = ft_strjoin(line,buffer);
    }
    return(0);
}