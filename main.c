/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:26:24 by ydinler           #+#    #+#             */
/*   Updated: 2025/06/25 19:14:25 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int        fd;
    char    *ss;

    fd = open("yunn.txt", O_RDWR);
    if (fd != -1)
        ss = get_next_line(fd);
    printf("%s\n",ss);
    free(ss);
    //ss = get_next_line(fd);
    //printf("%s\n",ss);
    //free(ss);
    //ss = get_next_line(fd);
    //printf("%s\n",ss);
    //free(ss);
    close(fd);
    return (0);
}