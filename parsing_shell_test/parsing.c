/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:36:11 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/28 17:46:05 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./test.h"

int	ft_quotes(char *str, int q)
{
	if (q == 0)
	{
		if (str[0] == '\'')
			q = 1;
		else if (str[0] == '\"')
			q = 2;
	}
	else if (q == 1)
	{
		if (str[0] == '\'' && (!str[1] || str[1] == ' '))
			q = 0;
	}
	else if (q == 2)
	{
		if (str[0] == '\"' && (!str[1] || str[1] == ' '))
			q = 0;
	}
	return (q);
}

int	ft_nargs(char *str)
{
	int	i;
	int	q;
	int	ct;

	i = 0;
	q = 0;
	ct = 1;
	while (str[i])
	{
		q = ft_quotes(&str[i], q);
		if (q == 0 && str[i] == ' ')
			ct++;
		i++;
	}
	return (ct);
}

int	ft_sublen(char *str, int q)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && ft_quotes(&str[i + 1], q) != q)
			break ;
		i++;
	}
	return (i);
}

char	*ft_subcpy(char *str, int q)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * (ft_sublen(str, q) + 1));
	while (str[i])
	{
		dst[i] = str[i];
		if (str[i + 1] && ft_quotes(&str[i + 1], q) != q)
			break ;
		i++;
	}
	str[i] = '\0';
	return (dst);
}

char	**ft_parsing(char *str)
{
	int	q;
	int	i;
	int	j;
	char	**args;

	q = 0;
	i = 0;
	j = 0;
	args = malloc(sizeof(char *) * (ft_nargs(str) + 1));
	while (j <= ft_nargs(str))
	{
		args[j] = ft_subcpy(&str[i], q);
		i = ft_sublen(&str[i], q) + i + 1;
		printf("i: %d\n", i);
		j++;
	}
	args[j] = 0;
	j = 0;
	while (args[j])
	{
		printf("%s\n", args[j]);
		j++;
	}
	return (NULL);
}