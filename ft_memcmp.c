/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:34:26 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/15 14:59:01 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	char			*string1;
	char			*string2;

	i = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	while ((string1[i] == string2[i]) && (string1[i] || string2[i]) && (i < n
			- 1))
	{
		i++;
	}
	if (string1[i] != string2[i])
		return (string1[i] - string2[i]);
	else
		return (0);
}
