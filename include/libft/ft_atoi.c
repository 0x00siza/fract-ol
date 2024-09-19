/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:12:35 by ner-roui          #+#    #+#             */
/*   Updated: 2024/09/07 12:12:35 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error("Error");
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Error");
		else
			number = number * 10 + (str[i++] - '0');
	}
	if (number < INT_MIN || number > INT_MAX)
		ft_error("Error");
	return (number * sign);
}
