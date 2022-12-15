/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:48:00 by matde-je          #+#    #+#             */
/*   Updated: 2022/12/15 22:44:58 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (0);
	while (s1 != NULL && s1[i] != '\0')
	{
		final[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		final[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
		j++;
	}
	final[i] = '\0';
	free(s1);
	return (final);
}
