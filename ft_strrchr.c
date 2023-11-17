/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:59:51 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/17 19:53:28 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*string;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	string = (char *)s + len;
	while (string >= s)
	{
		if (*string == c)
			return (string);
		string--;
	}
	return (NULL);
}
