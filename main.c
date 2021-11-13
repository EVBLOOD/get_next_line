/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:38:29 by sakllam           #+#    #+#             */
/*   Updated: 2021/11/13 18:58:33 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	i;
	char *c;

	i = open("txt", O_RDONLY);
	// c = get_next_line(i);
	// printf("%s", c);	
	// c = get_next_line(i);
	// printf("%s", c);
		// c = get_next_line(i);
	// printf("%s", c);

	while ((c = get_next_line(i)))
	{
		printf("%s", c);
	}
	return (0);
}