/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:18:41 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/15 14:52:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;
	char			*string;

	i = 1;
	string = (char *)s;
	while (*string != c && i < n)
	{
		string++;
		i++;
	}
	if (*string == c)
		return (string);
	else
		return (NULL);
}
