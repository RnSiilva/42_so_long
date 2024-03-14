/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:28:45 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:36:05 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: string.h
DEF: Calculates the lenght of a string
RETURN : The lenght of the string.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "42School";
// 	printf("The length of '%s' is: %zu\n", str, ft_strlen(str));
// }