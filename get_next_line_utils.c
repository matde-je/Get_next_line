/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:48:00 by matde-je          #+#    #+#             */
/*   Updated: 2022/12/14 18:15:34 by matde-je         ###   ########.fr       */
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

	j = -1;
	i = 0;
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final)
		return (0);
	while (i < ft_strlen(s1))
	{
		final[i] = s1[i];
		i++;
	}
	while (++j < ft_strlen(s2))
	{
		final[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	final[i] = '\0';
	free(s1);
	return (final);
}
