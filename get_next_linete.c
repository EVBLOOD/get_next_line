/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:02:29 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/09 19:58:15 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


int ft_strlen(char *str)
{
	int i = 0;
	
	while(str[i])
		i++;
	return (i);
}
char *ft_strdup(char *str)
{
	int i = 0;
	char *ptr = malloc(sizeof(char) * ft_strlen(str)+1);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
 }

char	*get_next_line(int fd)
{
	// static char	*recept;
	char		*buff = malloc(sizeof(char) * 1024);
	int ret = 0;
	char *line = NULL;

	/*

		some insructions...

	*/
	while((ret=read(fd,buff, 1024)) > 0)
	{
		buff[ret] = '\0';
		printf("[%s]",buff);
		if(!line)
			line = ft_strdup(buff);
		else
		{
			//leak be like : HELOOOOW
			//line = ft_strjoin(line,buff);
		}
		//if(ft_strchr(line,"\n"))
	//	{
			//check leak; bufff
			//break;
	//	}
		free(buff);
		buff = malloc(sizeof(char) * 1024);
	}
	//--->  line \n --> \ndeiudheiudh
	//if(recept == NULL)
	//recept = ft_strchr(line,"\n");
	//else 
	// 
	// if(ret < 0)
	//
	// if(ret == 0)
	// free --> recept 
	// if(ret > 0)
	// 
	return (/**/);
}
