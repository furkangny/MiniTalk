/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:04:38 by fgunay            #+#    #+#             */
/*   Updated: 2023/08/19 18:04:40 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

void bit_sum(int x)
{
	static int set;
	static int bit = 7;

	set += (x << bit);

	if (bit == 0)
	{
		ft_printf("%c",set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void signal_catch(int sig_num)
{
	if (sig_num == SIGUSR1)
		bit_sum(1);

	else
		bit_sum(0);
}
void sig_handler(int a)
{
	(void)a;
	ft_printf("sinyal engellendi..");
}

int main()
{
	int pid;
	pid = getpid();

	ft_printf("Pid: %u\n\n", pid);

	signal(SIGUSR1, signal_catch);
	signal(SIGUSR2, signal_catch);
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);

	while(1)
		pause();
}
