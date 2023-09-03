/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:05:01 by fgunay            #+#    #+#             */
/*   Updated: 2023/08/19 18:05:02 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	bit_sum(int x);
void	signal_catch(int x);
void	bit_send(int pid, char *str);

#endif
