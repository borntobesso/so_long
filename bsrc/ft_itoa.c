/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:47 by sojung            #+#    #+#             */
/*   Updated: 2022/02/02 15:08:49 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_count(int n)
{
	int				count;
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = n * -1;
		count = 2;
	}
	else
	{
		nbr = n;
		count = 1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_set(char *s, unsigned int n, int size)
{
	while (0 < size)
	{
		s[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int				size;
	char			*res;
	unsigned int	nbr;

	size = ft_count(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr = n * -1;
		res[0] = '-';
		ft_set(res + 1, nbr, size - 1);
	}
	else
		ft_set(res, n, size);
	res[size] = '\0';
	return (res);
}
