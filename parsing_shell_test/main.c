/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:29:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/04/28 13:45:21 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./test.h"

void	ft_prompt(void)
{
	char *str;
	char **test;

	while (1)
	{
		str = readline("Jean_MiShell>> ");
		printf("input: %s\n", str);
		if (ft_strlen(str))
			add_history(str);
		test = ft_parsing(str);
		// ft_print(test);
		free(str);
	}
}

int	main(void)
{
	ft_prompt();
	return (0);
}