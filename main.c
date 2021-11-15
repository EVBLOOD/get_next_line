/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:38:29 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/15 21:43:22 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_putstr(char *str)
{
	int i;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	write(1,"\n",1);
}

int	main(void)
{
	int	i;
	char *c;

	i = open("gnlTester/files/multiple_nlx5", O_RDWR);
	// c = get_next_line(i);
	// printf("%s", c);	
	// c = get_next_line(i);
	// printf("%s", c);
		// c = get_next_line(i);
	while ((c = get_next_line(i)))
	{
		printf("%s", c);
		free(c);
		// break;
	}
		// puts(c);
	// c = get_next_line(i);
	// free(c);
	// c = get_next_line(i);
	// free(c);
	// c = get_next_line(i);
	// free(c);
	// c = get_next_line(i);
	// free(c);
	close(i);
	return (0);
}