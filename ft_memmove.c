/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:12:18 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/16 21:02:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned long i;
    int j;
    char *ptr_dst;
    char const *ptr_src;
    char *backup_dst;

    backup_dst = "eelo";
    ptr_dst = dst;
    ptr_src = src;
    i = 0;
    j = 0;
    
    while(ptr_dst[j] != '\0')
    {
        backup_dst[j] = ptr_dst[j];
        j++;
    }
    while(i < len)
    {
        ptr_dst[i] = ptr_src[i];
        i++;
    }
    return (backup_dst);
}

// int main(void)
// {
// 	char	*source;
// 	char	*destination;
// 	int		size;
// 	char	*test_output;
// 	char	*destination_2;
// 	char	*test_output_2;

//     size = 3;
//     source = (char *)malloc(sizeof(char) * 50);
// 	destination = (char *)malloc(sizeof(char) * 50);
// 	test_output = (char *)malloc(sizeof(char) * 50);
// 	destination_2 = (char *)malloc(sizeof(char) * 50);
// 	test_output_2 = (char *)malloc(sizeof(char) * 50);
//     printf("\nTEST MEMMOVE\n");
// 	printf("-------------");
// 	strlcpy(source, "Hello", sizeof("Hello"));
//     strlcpy(destination, "a", 20);
//     strlcpy(destination_2, "a", 20);
// 	printf("\n");
// 	printf("Original Before: %s\n", destination);
//     test_output = memmove(destination, source, size);
// 	printf("Original After: %s\n", destination);
// 	printf("Original The output: %s\n", test_output);
// 	printf("\n");
// 	printf("Built Before: %s\n", destination_2);
// 	test_output_2 = ft_memmove(destination_2, source, size);
// 	printf("Built After: %s\n", destination_2);
// 	printf("Built The output: %s\n", test_output_2);
// 	printf("-------------\n");
// }
