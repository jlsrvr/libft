/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrivoire <jrivoire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:27:16 by jrivoire          #+#    #+#             */
/*   Updated: 2021/02/23 17:22:21 by jrivoire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *base)
{
	int index;
	int comp;

	index = 0;
	while (base[index])
	{
		comp = 1;
		if (base[index] == '-' || base[index] == '+')
			return (0);
		while (base[index + comp])
		{
			if (base[index] == base[index + comp])
				return (0);
			++comp;
		}
		++index;
	}
	return (1);
}

static	int		len_num(int n)
{
	size_t			len;
	unsigned int	nbr;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	else
		nbr = n;
	while (nbr > 9)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len + 1);
}

static	void	store_num(unsigned int nbr, char *num,
							size_t *index, char *base)
{
	size_t basetype;

	basetype = ft_strlen(base);
	if (nbr <= basetype - 1 && nbr >= 0)
		num[(*index)++] = base[nbr];
	else
	{
		store_num((int)(nbr / basetype), num, index, base);
		store_num((int)(nbr % basetype), num, index, base);
	}
	num[*index] = 0;
	return ;
}

char			*ft_itoa_base(int n, char *base)
{
	char			*num;
	size_t			index;
	unsigned int	nbr;
	size_t			basetype;

	num = NULL;
	basetype = ft_strlen(base);
	if (basetype > 1 && check_base(base))
	{
		if (!(num = malloc(sizeof(*num) * (len_num(n) + 1))))
			return (NULL);
		index = 0;
		if (n < 0)
		{
			num[index++] = '-';
			nbr = -n;
		}
		else
			nbr = n;
		store_num(nbr, num, &index, base);
	}
	return (num);
}
