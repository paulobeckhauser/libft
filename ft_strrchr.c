/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:59:51 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/17 11:12:22 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	int		len;

	len = ft_strlen(s);
	string = (char *)s;
	string = string + len - 1;
	while (*string != c)
	{
		if (len == 1 && *string != s[len - 1])
			return (NULL);
		else
		{
			string--;
			len--;
		}
	}
	return (string);
}
