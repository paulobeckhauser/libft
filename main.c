/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:26:57 by pabeckha          #+#    #+#             */
/*   Updated: 2023/12/01 12:14:18 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void blue(void)
{
	printf("\x1B[34m");
}

void gray(void)
{
	printf("\033[30;1m");
}

void green(void)
{
	printf("\x1B[32m");
}

void red(void)
{
	printf("\x1B[31m");
}

void yellow(void)
{
	printf("\x1B[33m");
}

int	ft_isalpha_test(void);


int	ft_isdigit_test(void);
int	ft_isalnum_test(void);
int	ft_isascii_test(void);
int	ft_isprint_test(void);


int	ft_strlen_test(void)
{
	char *string;
	int size;

	string = "Hello";
	size = ft_strlen(string);
	printf("\nTEST STRLEN\n");
	printf("-------------");
	printf("\n");
	printf("strlen original function: %lu\n", strlen(string));
	printf("strlen built function: %lu\n", ft_strlen(string));
	printf("-------------\n");
	return(0);
}




int	ft_memset_test(void);
int	ft_bzero_test(void);

int	ft_memcpy_test(void)
{
	char	*source;

	char *str_strlcat_src[20] = {"abcd", "pqr"};
	char str_strlcat_dest_1[][20] = {"pqr", "abcd" };
	char str_strlcat_dest_2[][20] = {"pqr", "abcd"};	
	size_t size0 = 1;
	size_t size1 = 5;
	size_t *n[] = {&size0, &size1};
	char *original_output;
	char *built_output;
	int		response = 1;
	printf("\n");
	printf("=======================================[ FT_MEMCPY ]=============================================\n");
	printf("\n");

	int lenght = 0;
	while (str_strlcat_src[lenght])
	{
		lenght++;
	}
	for (int i = 0; i <= lenght; i++)
	{
		printf("\n\n\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n", i);
		printf("Source: %-16s", str_strlcat_src[i]);
		printf("\n\n");
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("Destination Before: %-16s",str_strlcat_dest_1[i]);
		original_output = memcpy(str_strlcat_dest_1[i], str_strlcat_src[i], *n[i]);
		printf("Destination After: %-16s",str_strlcat_dest_1[i]);
		printf("Original Output: %-16s",original_output);
		printf("\n\n\n");
		printf("\033[4mBuilt Function: \033[0m\n\n");
		printf("Destination Before: %-16s",str_strlcat_dest_2[i]);
		built_output = ft_memcpy(str_strlcat_dest_2[i], str_strlcat_src[i], *n[i]);
		printf("Destination After: %-16s",str_strlcat_dest_2[i]);
		printf("Built Output: %-16s",built_output);
		printf("\n\n");
		if (*original_output == *built_output)
			printf("✅  ");
		else
			printf("❌  ");
	}
			printf("\n\n");
	return (response);
}

int	ft_memmove_test(void)
{
	int		response = 1;
	printf("\n");
	printf("=======================================[ FT_MEMMOVE ]=============================================\n");
	printf("\n");

	char	*memmove_src[14] = {"Quiz", NULL};
	char	*memmove_dst[6] = {"Geeks", NULL};
	char	*memmove_dst_2[6] = {"Geeks", NULL};

	size_t size0 = sizeof(*memmove_src[8]);
	size_t size1 = 2;
	// size_t size3 = 9;
	// size_t size4 = 9;
    size_t *str_strlcat_size[] = {&size0, &size1};
	
	int lenght = 0;
	while(memmove_src[lenght])
	{
		lenght++;
	}
	
	for (int i = 0; i <= lenght; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n", i);
		printf("Size: %zu\n\n", *str_strlcat_size[i]);
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("Source: %-16s", memmove_src[i]);
		printf("Dest Before: %-16s", memmove_dst[i]);
		char *original_output = memmove(memmove_dst, memmove_src, *str_strlcat_size[i]);
		printf("Output: %-16s", original_output);
		printf("Dest After: %-16s", memmove_dst[i]);
		printf("\n\n");
		printf("\033[4mBuilt Function: \033[0m\n\n");
		printf("Source: %-16s", memmove_src[i]);
		printf("Dest Before: %-16s", memmove_dst_2[i]);
		char *built_output = ft_memmove(memmove_dst_2, memmove_src, *str_strlcat_size[i]);
		printf("Output: %-16s", built_output);
		printf("Dest After: %-16s", memmove_dst_2[i]);
		printf("\n\n\n");
	
		if (*original_output == *built_output &&  memmove_dst[i] ==  memmove_dst_2[i])
			printf("✅  ");
		else
			printf("❌  ");
		printf("\n\n");
	}

	return (response);
}

int	ft_strlcpy_test(void)
{
    char *source = "lorem ipsum dolor sit amet";
	char	destination[16];
	int		size;
    int test_output;
    char	destination_2[16];
    int test_output_2;

	size = 15;
    printf("\nTEST STRLCPY\n");
	printf("-------------\n");
    printf("Original Destination Before: %s\n", destination);
    test_output = strlcpy(destination, source, size);
    printf("Original Destination After: %s\n", destination);
    printf("Original Output: %d\n", test_output);
    printf("\n");
    printf("Built Destination Before: %s\n", destination_2);
    test_output_2 = ft_strlcpy(destination_2, source, size);
    printf("Built Destination After: %s\n", destination_2);
    printf("Built Output: %d\n", test_output_2);
    printf("-------------\n");
	return (0);
}

int check_ft_strlcat(void)
{
	int response = 1;

	yellow();
	printf("\n");
	printf("=======================================[ FT_STRLCAT ]=============================================\n");
	char *str_strlcat_src[] = {"abcd",
	"abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcd",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi",
    "abcdefghi"};

	char str_strlcat_dest_1[][20] = {"pqr",
		 "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs"};

	char str_strlcat_dest_2[][20] = {"pqr",
		 "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrstuvwxyz",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs",
    "pqrs"};

	size_t size0 = 6;
	size_t size1 = 0;
	size_t size2 = 1;
	size_t size3 = 2;
	size_t size4 = 3;
	size_t size5 = 4;
	size_t size6 = 5;
	size_t size7 = 6;
	size_t size8 = 7;
	size_t size9 = 20;
	size_t size10 = 10;
	size_t size11 = 11;
	size_t size12 = 12;
	size_t size13 = 13;
	size_t size14 = 14;
	size_t size15 = 15;
	size_t size16 = 16;
	size_t size17 = 17;

    size_t *str_strlcat_size[] = {&size0, &size1,
	&size2, &size3, &size4, &size5, &size6, &size7,
	&size8, &size9, &size10, &size11, &size12, &size13, &size14, &size15,
		&size16,
	&size17};

	int length = sizeof(str_strlcat_src) / sizeof(str_strlcat_src[0]);
	for (int i = 0; i < length; i++)
	{

		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);
		printf("Source: %s\n", str_strlcat_src[i]);
		printf("Size: %zu\n\n", *str_strlcat_size[i]);
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("Dest Before: %-20s", str_strlcat_dest_1[i]);
		size_t expected = strlcat(str_strlcat_dest_1[i] , str_strlcat_src[i],
				*str_strlcat_size[i]);
		printf("| Dest After: %-20s", str_strlcat_dest_1[i]);
		printf("| Return: %zu", expected);
		printf("\n");
		printf("\n\n\033[4mBuilt Function: \033[0m\n\n");
		printf("Dest Before: %-20s", str_strlcat_dest_2[i]);
		size_t result = ft_strlcat(str_strlcat_dest_2[i] , str_strlcat_src[i],
				*str_strlcat_size[i]);
		printf("| Dest After: %-20s", str_strlcat_dest_2[i]);
		printf("| Return: %zu", result);
		printf("\n");
		printf("\n");
		if (expected == result && (strcmp(str_strlcat_dest_1[i],
					str_strlcat_dest_2[i]) == 0))
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("\n");
		printf("\n");
	}
	printf("===========================================================================================\n");
	printf("\n");
	printf("\n");

	return (response);
}


int	ft_toupper_test(void)
{
    unsigned char original;
    unsigned char original_converted;
    unsigned char built_converted;

    printf("\nTEST TOUPPER\n");
	printf("-------------\n");
    original = 'a';
    printf("Original Before: %c\n", original);
    original_converted = toupper(original);
    printf("Original After: %c\n", original_converted);

    built_converted = ft_toupper(original);
    printf("Built After: %c\n", built_converted);
    printf("-------------\n");
	return (0);
}

int	ft_tolower_test(void)
{
    unsigned char original;
    unsigned char original_converted;
    unsigned char built_converted;

    printf("\nTEST TOLOWER\n");
	printf("-------------\n");
    original = 'A';
    printf("Original Before: %c\n", original);
    original_converted = tolower(original);
    printf("Original After: %c\n", original_converted);

    built_converted = ft_tolower(original);
    printf("Built After: %c\n", built_converted);
    printf("-------------\n");
	return (0);
}

int	ft_strchr_test(void)
{
	int		response;
	char	*str_s[20] = {"teste", "teste", "teste", NULL};
	int		c_strchr[] = {'a', 'a', 'a', 'a'};
	int		length;

	response = 1;
	printf("\n");
	printf("=======================================[ FT_STRCHR ]=============================================\n");
	printf("\n");
	length = sizeof(str_s) / sizeof(str_s[0]);
	for (int i = 0; i < 4; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n", i);
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("String: %-16s", str_s[i]);
		printf("Character: %-16c", c_strchr[i]);
		// stpcpy(output[i], strchr(str_s[i], c));
		printf("Output: %-16s", strchr(str_s[i], c_strchr[i]));
		printf("\n\n\n");
		printf("\033[4mBuilt Function: \033[0m\n\n");
		printf("String: %-16s", str_s[i]);
		printf("Character: %-16c", c_strchr[i]);
		printf("Output: %-16s", ft_strchr(str_s[i], c_strchr[i]));
		printf("\n\n\n");
		if (strchr(str_s[i], c_strchr[i]) == ft_strchr(str_s[i], c_strchr[i]))
		{
			printf("✅  ");
		}
		else
		{
			printf("❌  ");
			response = 0;
		}
		printf("\n");
	}
	return (response);
}

int	ft_strrchr_test(void)
{
	int		response;
	char	*str_s[20] = {"teste", "teste", "abcdefghi", "teste"};
	int		c_strrchr[] = {'e', 'a', 'e', '\0'};
	int		length;

	response = 1;
	printf("\n");
	printf("=======================================[ FT_STRRCHR ]=============================================\n");
	printf("\n");
	length = sizeof(str_s) / sizeof(str_s[0]);
	for (int i = 0; str_s[i]; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n", i);
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("String: %-16s", str_s[i]);
		printf("Character: %-16c", c_strrchr[i]);
		printf("Output: %-16s", strrchr(str_s[i], c_strrchr[i]));
		printf("\n\n\n");
		printf("\033[4mBuilt Function: \033[0m\n\n");
		printf("String: %-16s", str_s[i]);
		printf("Character: %-16c", c_strrchr[i]);
		printf("Output: %-16s", ft_strrchr(str_s[i], c_strrchr[i]));
		printf("\n\n\n");
		if (strrchr(str_s[i], c_strrchr[i]) == ft_strrchr(str_s[i],
				c_strrchr[i]))
		{
			printf("✅  ");
		}
		else
		{
			printf("❌  ");
			response = 0;
		}
	}
	printf("\n");
	return (response);
}

int	ft_strncmp_test(void)
{
	int	response = 1;
	printf("\n");
	printf("=======================================[ FT_STRNCMP ]=============================================\n");
	printf("\n");
	
	char *string_1[20] = {"teste", "abcdef", "abcdefghi", "teste"};
    char *string_2[20] = {"aaaa", "abc\375xx", "abcdefghi", "teste"};
	
	size_t size0 = 0;
	size_t size1 = 5;
	size_t size2 = 1;
	size_t size3 = 1;
	
    size_t *str_strlcat_size[] = {&size0, &size1,
	&size2, &size3};
	
	int original_output;
	int built_output;

    int length = 0;
    while (string_1[length]) {
        length++;
    }
	for (int i = 0; i < length; i++)
	{

		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);
		printf("\033[4mOriginal Function: \033[0m\n\n");
		printf("First String: %-16s", string_1[i]);
		printf("Second String: %-16s", string_2[i]);
		original_output = strncmp(string_1[i], string_2[i], *str_strlcat_size[i]);
		printf("The output is: %-8d", original_output);
		printf("\n\n");
		printf("\033[4mBuilt Function: \033[0m\n\n");
		printf("First String: %-16s", string_1[i]);
		printf("Second String: %-16s", string_2[i]);
		built_output = ft_strncmp(string_1[i], string_2[i], *str_strlcat_size[i]);
		printf("The output is: %-8d", built_output);
		printf("\n\n");
		if (original_output == built_output)
		{
			// green();
			printf("✅  ");
		}
		else
		{
			// red();
			printf("❌  ");
			response = 0;
		}
		printf("\n");
		printf("\n");
	}
	return (response);
}


int	ft_memchr_test(void)
{
	int	response = 1;
	printf("\n");
	printf("=======================================[ FT_MEMCHR ]=============================================\n");
	printf("\n");
	char *original_output;
	char *built_output;
	char *startAddress = (char *)0x7ffeec5097a0;
	char *string[20] = {"teste", "abcdef", "abcdefghi", "teste", startAddress};
	char charac[] = {'e', 'c', 'h', 's', 'N'};
	size_t size0 = 0;
	size_t size1 = 6;
	size_t size2 = 10;
	size_t size3 = 9;
	size_t size4 = 37;
    size_t *str_strlcat_size[] = {&size0, &size1,
	&size2, &size3, &size4};
	
    int length = 0;
    while (string[length]) {
        length++;
    }
	for (int i = 0; i < length; i++)
	{
		printf("\n");
		printf("Test %-2d. \n\n\n", i);
		printf("String: %-16s", string[i]);
		printf("The character is: %-8c", charac[i]);
		printf("\n\n\n");
		printf("\033[4mOriginal: \033[0m\n\n");
		original_output = memchr(string[i], charac[i], *str_strlcat_size[i]);
		printf("%-16s", original_output);
		printf("\n\n\n");
		printf("\033[4mBuilt: \033[0m\n\n");
		built_output = ft_memchr(string[i], charac[i], *str_strlcat_size[i]);
		printf("%-16s", built_output);
		printf("\n\n\n");
		if (original_output == built_output)
		{
			green();
			printf("OK ✅  ");
		}
		else
		{
			red();
			printf("KO ❌  ");
			response = 0;
		}
		gray();
		printf("\n");
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
	}
	return (response);
	
}

int	ft_memcmp_test(void)
{
    int response = 1;
	char *string_1[20] = {"Hellb", "abcdef", "abc", "zyxbcdefgh", "atoms\0\0\0\0", ""};
    char *string_2[20] = {"Hella", "abc\375xx", "abc", "abcdefgxyz", "atoms\0abc", ""};
    int original_output;
    int built_output;
	printf("\n");
	printf("=======================================[ FT_MEMCMP ]=============================================\n");
    size_t size0 = 3;
	size_t size1 = 5;
	size_t size2 = 7;
	size_t size3 = 0;
	size_t size4 = 8;
	size_t size5 = 2;
	size_t *n[] = {&size0, &size1,  &size2, &size3, &size4, &size5};
	
	int count = 0;
	while (string_1[count])
	{
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		gray();
		printf("\n");
		printf("\033[4mTest %-2d. \033[0m\n", i);
		printf("\n");
		printf("First String: %-10s", string_1[i]);
		printf("Second String: %-10s", string_2[i]);
		printf("\n\n");
		original_output = memcmp(string_1[i], string_2[i], *n[i]);
		printf("\033[4mOriginal:\033[0m %d\n\n", original_output);
		built_output = ft_memcmp(string_1[i], string_2[i], *n[i]);
		printf("\033[4mBuilt:\033[0m %d\n\n", built_output);
		printf("\n");
		if (original_output == built_output)
		{
			green();
			printf("OK ✅  ");
		}
		else
		{
			red();
			printf("KO ❌  ");
			response = 0;
		}
		gray();
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
	}
	return (response);

}

int	ft_strnstr_test(void)
{
	int response = 1;
	printf("\n");
	printf("=======================================[ FT_STRNSTR ]=============================================\n");
	printf("\n\n");
	char *string[] = {"Hello", "Hello", "haystack", "lorem ipsum dolor sit amet","aaabcabcd", "aaaabcabcd"};
	char *needle[]= {"l", "ll", "abcd", "ipsumm","aabc", "aabc"};
	size_t len0 = 2;
	size_t len1 = 4;
	size_t len2 = 9;
	size_t len3 = 30;
	size_t len4 = -1;
	size_t len5 = 5;
	size_t *len[] = {&len0, &len1, &len2, &len3, &len4, &len5};
	char *original_output;
	char *built_output;
	int count = 0;
	count = sizeof(string)/ sizeof(string[0]);
	for (int i = 0; i < count; i++)
	{
		printf("\n\n");
		printf("\033[4mTest %-2d. \033[0m\n", i);
		printf("\n");
		original_output = strnstr(string[i], needle[i], *len[i]);
		printf("String: ");
		printf("%-30s", string[i]);
		printf("Needle: ");
		printf("%-16s", needle[i]);
		printf("Len: ");
		printf("%-16zu", *len[i]);
		printf("\n\n");
		printf("Original: ");
		printf("%-16s", original_output);
		printf("Built: ");
		built_output = ft_strnstr(string[i], needle[i], *len[i]);
		printf("%-16s", built_output);
		if (original_output == built_output)
		{
			printf("OK ✅  ");
		}
		else
		{
			printf("KO ❌  ");
			response = 0;
		}
		printf("\n\n");
		printf("--------------------------------------------------------------------------------------------------\n");
	}

	return (response);
}

int	ft_atoi_test(void)
{
	int	response;
	int	length;
	int	expected;
	int	result;

	response = 1;
	// yellow();
	printf("\n");
	printf("=======================================[ FT_ATOI ]=============================================\n");
	char *str_atoi[] = {"12123",
						"   19212 123 123",
						"42as 1asd2 a3",
						"-12389          48",
						"2147483647",
						"-2147483648",
						"2147483648",
						"21474--83648",
						"++2483648",
						"-+214836+4-8",
						"     -     213123123",
						"   12998833 ----3",
						"    ",
						"987654321",
						"  -54321",
						"   +999",
						"0",
						"  0",
						"   -0",
						"   +0",
						"   123 456",
						"   +987654",
						"   -123.45", 
							// Note: atoi won't handle floating-point numbers correctly
						"   99999abc",
							// Note: atoi stops at the first non-numeric character
						"   abc99999",
							// Note: atoi returns 0 if the string doesn't start with a valid numeric character
						"   123 456 789",
						"+++++123",
						"----123",
						"123abc456",      // Letters in the middle
						"  -12!34",       // Special character in the middle
						"   +123$456",    // Special character in the middle
						"   -789%123",    // Special character in the middle
						"   0^",          // Caret character
						"   789*123",     // Asterisk character
						"   456(789",     // Parentheses
						"   -123_456",    // Underscore character
						"   +123456#",    // Hash/pound character
						"   -789|123",    // Vertical bar
						"   0@123",       // At symbol
						"   +123456?",    // Question mark
						"   123456~789",  // Tilde character
						"   -123456[789", // Square brackets
						"   +123456789]", // Square brackets
						"   -123456{789", // Curly brackets
						"   +123456789",
						" \t\v\n\r\f123",
						"\t 10",
						"\n 11",
						"\v 12",
						"\f 13",
						"\r 14"};
	length = sizeof(str_atoi) / sizeof(str_atoi[0]);
	for (int i = 0; i < length; i++)
	{
		expected = atoi(str_atoi[i]);
		result = ft_atoi(str_atoi[i]);
		if (expected == result)
		{
			// green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		printf("Test %-2d. ", i);
		gray();
		printf(" | Input:  | %-20s", str_atoi[i]);
		printf(" | ");
		printf("expected: %-12d", expected);
		yellow();
		printf(" | ");
		gray();
		printf("received: %-12d\n", result);
	}
	printf("===========================================================================================\n");
	printf("\n");
	printf("\n");
	return (response);
}

int	ft_calloc_test(void)
{
	
	printf("\n");
	printf("=======================================[ FT_CALLOC ]=============================================\n");
	int response = 1;
	size_t count = 5;
	size_t size_of_int = sizeof(int);
	int *original_test;
	int *built_test;
	
	original_test = (int *)calloc(count, size_of_int);
	for (size_t i = 0; i < count; i++)
	{
		original_test[i] = i + 1;
	}
	int original_lenght = 0;
	while(original_test[original_lenght])
	{
		original_lenght++;
	}
	// printf("Test %-2d. \n\n", i);
	printf("\033[4mOriginal Function: \033[0m\n\n");
	printf("The array content: ");
	printf("{");
	for (size_t i = 0; i < original_lenght; i++)
	{
		printf("'%d'", original_test[i]);
		if (i < original_lenght - 1)
		printf(", ");
	}
	printf("}\n\n");
	free(original_test);
	
	built_test = (int *)ft_calloc(count, size_of_int);
	for (size_t i = 0; i < count; i++)
	{
		built_test[i] = i + 1;
	}
	int built_lenght = 0;
	while(built_test[built_lenght])
	{
		built_lenght++;
	}
	printf("\033[4mBuilt Function: \033[0m\n\n");
	printf("The array content: ");
	printf("{");
	for (size_t i = 0; i < built_lenght; i++)
	{
		printf("'%d'", built_test[i]);
		if (i < built_lenght - 1)
		printf(", ");
	}
	printf("}\n\n");
	free(built_test);
	return (response);
}

int	ft_strdup_test(void)
{
	printf("\n");
	printf("=======================================[ FT_STRDUP ]=============================================\n");
	int response = 1;
	char *string[20] = {"Hello", "Test", "ASHUJHSAJKSA", "fdfjkdf\n35346"};
	char *original_output;
	char *built_output;

	int count = 0;
	while(string[count])
	{
		count++;
	}
	for(int i = 0; i < count; i++)
	{
		printf("\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);
		printf("String: ");
		printf("%-16s", string[i]);
		original_output = strdup(string[i]);
		printf("Original output: ");
		printf("%-16s", original_output);
		printf("Built output: ");
		built_output = ft_strdup(string[i]);
		printf("%-16s", built_output);
		printf("\n\n");
		if (*original_output == *built_output)
		{
			green();
			printf("✅  ");
		}
		else
		{
			red();
			printf("❌  ");
			response = 0;
		}
		gray();
		printf("\n");
		free(original_output);
		free(built_output);
	}
	return (response);
}

int	ft_substr_test(void)
{
	printf("\n\n");
	printf("=======================================[ FT_SUBSTR ]=============================================\n");
	printf("\n\n");
	int response = 1;
	char *string[20] = {"Hello", "Test", "Test", "Test","AA", "i just want this part #############", 
					"Bonjour comment ca va?", "01234"};
	char start[] = {3, 5, 10, 
					4, 2, 0, 5, 10};
	size_t len0 = 3;
	size_t len1 = 2;
	size_t len2 = 3;
	size_t len3 = 4;
	size_t len4 = 3;
	size_t len5 = 22;
	size_t len6 = 8;
	size_t len7 = 10;
	size_t *len[] = {&len0, &len1, &len2, &len3, &len4, &len5, &len6, &len7};
	char *original_output;
	char *built_output;
	int count = 0;
	while(string[count])
	{
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);
		printf("String: ");	
		printf("%-16s\n", string[i]);
		printf("Start: ");	
		printf("%-16d\n",start[i]);
		printf("Max length: ");	
		printf("%-16zu\n", *len[i]);
		built_output = ft_substr(string[i], start[i], *len[i]);
		printf("Built Substring: ");
		printf("%-16s\n", built_output);
		printf("\n");	
		
	}
	printf("\n\n");
	return (response);
}

int	ft_strjoin_test(void)
{
	printf("\n\n");
	printf("=======================================[ FT_STRJOIN ]=============================================\n");
	printf("\n\n");
	int response = 1;
	char *string1[20] = {"Hello", "a", "a", "", "", NULL};
	char *string2[20] = {"Test", "b", "", "b", " ", "b"};
	char *output;

	int count = 0;
	while(string1[count])
	{
		count++;
	}
	for(int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);
		printf("First String: ");
		printf("%-16s\n", string1[i]);
		printf("Second String: ");
		printf("%-16s\n", string2[i]);
		printf("\n\n");
		output = ft_strjoin(string1[i], string2[i]);
		printf("Output: ");
		printf("%-16s", output);
		printf("\n\n\n");
	}
	return (response);
}

int	ft_strtrim_test(void)
{
	printf("\n\n");
	printf("=======================================[ FT_STRTIM ]=============================================\n");
	printf("\n\n");
	int response = 1;
	char *string[20] = {"ababaaaMy name is Simonbbaaabbad",
						"ababaaaMy name is Simonbbaaabba"};
	char *set[20] = {"ab", "ab"};
	char *output;
	int count = 0;
	while(string[count])
	{
		count++;
	}
	for(int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);	
		printf("String: ");
		printf("%-20s", string[i]);
		printf("Set: ");
		printf("%-20s", set[i]);
		printf("\n\n");
		output = ft_strtrim(string[i], set[i]);
		printf("Output: ");
		printf("%-16s", output);
		printf("\n\n");
	}
	return (response);
}

int	ft_split_test(void)
{
	printf("\n\n");
	printf("=======================================[ FT_SPLIT ]=============================================\n");
	printf("\n\n");
	int response = 1;
	char *string[20] = {"Testestesab",
	"The question, is, be or not, to be, HA!", ""};
	// char c[20] = {"s", ","};
	char c[] = {'s', ',', ' '};
	char **original_output;
	int count = 0;
	while(string[count])
	{
		count++;
	}
	for(int i = 0; i < count; i++)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);	
		printf("String: ");
		printf("%-16s\n", string[i]);
		printf("Set: ");
		printf("%-16c", c[i]);
		printf("\n\n");

		original_output = (char **)malloc(ft_strlen(string[i]) * sizeof(char));
		original_output = ft_split(string[i], c[i]);
		for (int j = 0; original_output[j]; j++)
		{
			printf("Split %d: ", j);
			printf("%s\n", original_output[j]);
		}
		// // printf("Output: ");
		// // printf("%-16s", original_output);
		printf("\n\n");
		free(original_output);

	}
	return (response);
}

int	ft_itoa_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_ITOA ]=============================================\n");
	printf("\n\n");
	int nb0 = -3220;
	int nb1 = 3220;
	int	nb2 = -2147483648;
	int	nb3 = 0;
	int	nb4 = 2147483647;
	int	nb5 = -2147483647;
	int	nb6 = -2147483647 -1;
	int *nb_val[] = {&nb0, &nb1, &nb2, &nb3, &nb4, &nb5, &nb6};
	char *output;

	int count = 0;
	while (nb_val[count])
	{
		count++;
	}
	for (int i = 0; i < 7; i++)
	{
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("Test %-2d. \n\n\n", i);	
		printf("Number: ");
		printf("%-16d\n\n\n", *nb_val[i]);
		output = ft_itoa(*nb_val[i]);
		printf("Output: ");
		printf("%s", output);
		printf("\n\n");
	}
	return (response);
}


char map_function_strmap(unsigned int index, char c) 
{
	return c + 1;
}
int	ft_strmap_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_STRMAPI ]=============================================\n");
	printf("\n\n");
	// Mapping function: Increment each character's ASCII value
	char input[] = "Hello";

	char *output = ft_strmapi(input, map_function_strmap);
	// Print the result
    printf("Original: %s\n", input);
    printf("Mapped  : %s\n\n", output);
	return (response);
}

void map_function_striteri(unsigned int i, char *s) 
{
	s[i] = s[i] + 1;
}
void map_function_striteri_2(unsigned int i, char *s) 
{
	*s = ft_toupper(*s);
}
int	ft_striteri_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_STRITERI ]=============================================\n");
	printf("\n\n");
	// Mapping function: Increment each character's ASCII value
	char input[] = "hello";
    printf("Original: %s\n", input);
	// ft_striteri(input, map_function_striteri);
	ft_striteri(input, map_function_striteri_2);
	// Print the result
    printf("Mapped  : %s\n\n", input);
	return (response);
}

int	ft_putchar_fd_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_PUTCHAR_FD ]=============================================\n");
	printf("\n\n");
	// Mapping function: Increment each character's ASCII value
	char *string = "Hello";
	int fd = 2;
	int i = 0;
	while (string[i])
	{
		ft_putchar_fd(string[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
	return (response);
}

int	ft_putstr_fd_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_PUTSTR_FD ]=============================================\n");
	printf("\n\n");
	// Mapping function: Increment each character's ASCII value
	char *string = "Hello\n";
	int fd = 1;
	int i = 0;
	ft_putstr_fd(string, fd);
	return (response);
}

int	ft_putendl_fd_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_PUTENDL_FD ]=============================================\n");
	printf("\n\n");
	// Mapping function: Increment each character's ASCII value
	char *string = "Hello";
	int fd = 1;
	ft_putendl_fd(string, fd);
	return (response);
}

int ft_putnbr_fd_test(void)
{
	int response = 1;
	printf("\n\n");
	printf("=======================================[ FT_PUTNBR_FD ]=============================================\n");
	printf("\n\n");
	int a;
	int fd;
	
	a = -2147483648;
	fd = 1;
	ft_putnbr_fd(a, fd);
	printf("\n\n");
	return (response);
}

int ft_lstnew_test(void)
{
	int response = 1;
	int sample_data = 42;
	// char *sample_data = "Hello";
	//  const char *sample_data = "Hello, World!";
	t_list *new_list = ft_lstnew(&sample_data);
	// t_list *new_list = ft_lstnew((void *)sample_data);
	// Call ft_lstnew with the sample data

	printf("\n\n");
	printf("=======================================[ FT_LSTNEW ]=============================================\n");
	printf("\n\n");
	printf("%d", *((int *)new_list->content));
	// printf("%s\n", (char *)new_list->content);
	// printf("%s", *((char *)new_list->content));
	printf("\n\n");
	return (response);
}

void print_list(t_list *lst)
{
	while(lst != NULL)
	{
		printf("%d ", *((int *)lst->content));
		lst = lst->next;
	}
	printf("\n");
}
int ft_lstadd_front_test(void)
{	
	int response = 1;
	// Create an empty linked list
    t_list *head = NULL;
	
	//Create nodes with integer values
	t_list *node1 = malloc(sizeof(t_list));
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	node1->content = value1;
	
	t_list *node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	node2->content = value2;

	t_list *node3 = malloc(sizeof(t_list));
	int *value3 = malloc(sizeof(int));
	*value3 = 3;
	node3->content = value3;
	printf("\n");
	printf("Addition of 1st Node: ");
	ft_lstadd_front(&head, node3);
	print_list(head);
	printf("\n");
	printf("Addition of 2nd Node: ");
	ft_lstadd_front(&head, node2);
	print_list(head);
	printf("\n");
	printf("Addition of 3rd Node: ");
	ft_lstadd_front(&head, node1);
	print_list(head);
	printf("\n");
	return (response);
}

int ft_lstsize_test(void)
{
	int response=1;
	t_list *head = NULL;
	
	//Create nodes with integer values
	t_list *node1 = malloc(sizeof(t_list));
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	node1->content = value1;
	t_list *node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	node2->content = value2;
	t_list *node3 = malloc(sizeof(t_list));
	int *value3 = malloc(sizeof(int));
	*value3 = 3;
	node3->content = value3;
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	int size;
	size = ft_lstsize(head);
	printf("\n");
	printf("The size is: %d", size);
	printf("\n\n");
	return (response);
}

int ft_lstlast_test(void)
{
	int response=1;
	t_list *head = NULL;
	
	//Create nodes with integer values
	t_list *node1 = malloc(sizeof(t_list));
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	node1->content = value1;
	t_list *node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	node2->content = value2;
	t_list *node3 = malloc(sizeof(t_list));
	int *value3 = malloc(sizeof(int));
	*value3 = 3;
	node3->content = value3;
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	// Get the last node of the linked list
    t_list *lastNode = ft_lstlast(head);
	printf("\n\n");
	if (lastNode != NULL)
	{
		printf("Last node: %d\n", *(int *)lastNode->content);
	}
	else
		printf("Empty list");
	printf("\n\n");
	return (response);
}

int ft_lstadd_back_test(void)
{
	int response=1;
	t_list *head = NULL;
	
	//Create nodes with integer values
	t_list *node1 = malloc(sizeof(t_list));
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	node1->content = value1;
	t_list *node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	node2->content = value2;
	t_list *node3 = malloc(sizeof(t_list));
	int *value3 = malloc(sizeof(int));
	*value3 = 3;
	node3->content = value3;
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	printf("\n\n");
	printf("Before: ");
	print_list(head);
	printf("\n\n");
	
	t_list *node4 = malloc(sizeof(t_list));
	int *value4 = malloc(sizeof(int));
	*value4 = 4;
	node4->content = value4;
	
	ft_lstadd_back(&head, node4);
	printf("After: ");
	print_list(head);
	printf("\n\n");
	return (response);
}

void custom_delete_function(void *content)
{
    free(content);
}
int ft_lstdelone_test(void)
{
	int response=1;
	t_list *head = malloc(sizeof(t_list));
	int *value = malloc(sizeof(int));
	*value = 42; // Example content (integer value)
	head->content = value;
    head->next = NULL;
	// Print the linked list before deletion
	printf("\n\n");
    printf("Linked List before deletion: ");
    print_list(head);
	printf("\n\n");
	
	ft_lstdelone(head, custom_delete_function);
	print_list(head);
	printf("\n\n");
	return (response);
}

int ft_lstclear_test(void)
{
	int response = 1;
    t_list *head = NULL;
	
	//Create nodes with integer values
	t_list *node1 = malloc(sizeof(t_list));
	int *value1 = malloc(sizeof(int));
	*value1 = 1;
	node1->content = value1;
	
	t_list *node2 = malloc(sizeof(t_list));
	int *value2 = malloc(sizeof(int));
	*value2 = 2;
	node2->content = value2;

	t_list *node3 = malloc(sizeof(t_list));
	int *value3 = malloc(sizeof(int));
	*value3 = 3;
	node3->content = value3;
	printf("\n");
	ft_lstadd_front(&head, node3);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node1);
	printf("Before: ");
	print_list(head);
	printf("\n");
	printf("After: ");
	ft_lstclear(&head, custom_delete_function);
	print_list(head);
	return (response);
}


// Example function to be passed to ft_lstiter
void print_content(void *content)
{
	printf("%s\n", (char*)content);
}
int ft_lstiter_test(void)
{
	int response = 1;
	// Create a linked list
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Node 1";
	node1->next = node2;

	node2->content = "Node 2";
	node2->next = node3;

	node3->content = "Node 3";
	node3->next = NULL;
	// Test ft_lstiter with print_content function
	ft_lstiter(node1, &print_content);

	
	return (response);
}

void print_int(void *content)
{
    printf("%d\n", *((int *)content));
}
void *square(void *content)
{
    int *value = (int *)content;
    int *result = malloc(sizeof(int));

    if (!result)
        return NULL;

    *result = (*value) * (*value);
    return result;
}
int ft_lstmap_test(void)
{
	t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
	if (!node1 || !node2 || !node3)
    {
        perror("Memory allocation failed");
        return 1;
    }
	int *content1 = malloc(sizeof(int));
    int *content2 = malloc(sizeof(int));
    int *content3 = malloc(sizeof(int));
	if (!content1 || !content2 || !content3)
    {
        // Handle memory allocation failure
        perror("Memory allocation failed");
        free(node1);
        free(node2);
        free(node3);
        return 1;
    }
	*content1 = 1;
    *content2 = 2;
    *content3 = 3;

	node1->content = content1;
    node1->next = node2;

    node2->content = content2;
    node2->next = node3;

    node3->content = content3;
    node3->next = NULL;
	printf("\n");
	printf("Before Function: \n");
	ft_lstiter(node1, &print_int);
	printf("\n\n");
	t_list *result_list = ft_lstmap(node1, &square, &custom_delete_function);
	printf("Using Function(with square to each data node): \n");
	ft_lstiter(result_list, &print_int);
	printf("\n");
	return (0);
}

int	main(void)
{
	// ft_isalpha_test();
	// ft_isdigit_test();
	// ft_isalnum_test(); 
	// ft_isascii_test();
	// ft_isprint_test();
	// ft_strlen_test();
	// ft_memset_test();
	// ft_bzero_test();
	// ft_memcpy_test();
	// ft_memmove_test();
	// ft_strlcpy_test();
	// ft_strlcat_test();
	// ft_toupper_test();
	// ft_tolower_test();
	// ft_strchr_test();
	// ft_strrchr_test();
	// ft_strncmp_test();
	// ft_memchr_test();
	// ft_memcmp_test();
	// ft_strnstr_test();
	// ft_atoi_test();
	// ft_calloc_test();
	// ft_strdup_test();
	// ft_substr_test();
	// ft_strjoin_test();
	ft_strtrim_test();
	// ft_split_test();
	// ft_itoa_test();
	// ft_strmap_test();
	// ft_striteri_test();
	// ft_putchar_fd_test();
	// ft_putstr_fd_test();
	// ft_putendl_fd_test();
	// ft_putnbr_fd_test();
	// ft_lstnew_test();
	// ft_lstadd_front_test();
	// ft_lstsize_test();
	// ft_lstlast_test();
	// ft_lstadd_back_test();
	// ft_lstdelone_test();
	// ft_lstclear_test();
	// ft_lstiter_test();
	// ft_lstmap_test();
}
