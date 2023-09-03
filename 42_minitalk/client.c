/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:03:28 by fgunay            #+#    #+#             */
/*   Updated: 2023/08/19 18:04:15 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while(str[i])
	{
		result = str[i] - '0' + (result *10);
		i++;
	}
	return result;
}

void bit_send(int pid, char *str)
{
	int i;
	unsigned char c;

	while(*str)
	{
		c = *str;
		i = 8;

		while(i--)
		{
			if((c >> i) & 1)
				kill(pid,SIGUSR1);

			else
				kill(pid,SIGUSR2);

			usleep(1000);
		}
		str++;
	}
}

int main(int ac, char **av)
{
	if(ac != 3)
	{
		ft_printf("enter 3 arguments\n");
		return 1;
	}
	bit_send(ft_atoi(av[1]), av[2]);
}
