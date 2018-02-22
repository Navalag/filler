/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:33:12 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 15:56:39 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string pointed to
** by str to int representation.
*/

int	ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	res;
	int						sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 9223372036854775807 && sign == -1)
		return (0);
	else if (res > 9223372036854775807)
		return (-1);
	return (sign * res);
}
