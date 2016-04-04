/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 13:28:46 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/22 14:28:10 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int     ft_get_word_length(char *str)
{
    int word_length;

    word_length = 0;
    while (str[word_length] != ' ' && str[word_length] != '\t' && str[word_length] != '\n' && str[word_length] != '\0')
        word_length++;
    return (word_length);
}

void    ft_strncpy(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while(s2[i] && i <= n)
    {
        s1[i] = s2[i];
        i++;
    }
}

char    **ft_split_whitespaces(char *str)
{
    char **array;
    int i;
    int m;
    int word_length;

    i = 0;
    m = -1;
    array = (char**)malloc(sizeof(char*));
    while (str[i])
    {
     	word_length = ft_get_word_length(&str[i]);
		if (word_length != 0)
		{
            m++;
            array = (char**)realloc(array, sizeof(char*) * m + 2);
            array[m] = (char*)malloc(sizeof(char) * word_length - 1);
            ft_strncpy(array[m], &str[i], word_length - 1);
            i += word_length + 1;
		}
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
    array[m + 1] = (char*)malloc(sizeof(char));
    array[m + 1][0] = 0;
    return (array);
}
