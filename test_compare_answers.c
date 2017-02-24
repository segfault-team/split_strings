/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare_answers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:21 by ggane             #+#    #+#             */
/*   Updated: 2017/02/24 16:32:32 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> //to_delete
#include <fcntl.h>

void	delete_both_arrays(char ***ar1, char ***ar2);
void	display_mistake(char **to_test, char **good_answers);

int		check_wrong_answers(char **to_test, char **good_answers)
{
	int		i;

	i = 0;
	while (to_test[i] || good_answers[i])
	{
		if (ft_strcmp(to_test[i], good_answers[i]))
			return (1);
		i++;
	}
	if (to_test[i] || good_answers[i])
		return (1);
	return (0);
}

void	test_answers(char **commands, char **expected_results)
{
	int		i;
	char	**to_test;
	char	**good_answers;

	i = 0;
	while (commands[i] && expected_results[i])
	{
		printf("test %d : [%s]\n", i + 1, commands[i]);
		//to_test = split_delim(commands[i], "|<>&");
		to_test = ft_strsplit("la vie est belle", ' ');
		good_answers = ft_strsplit(expected_results[i], '^');
		if (check_wrong_answers(to_test, good_answers))
			display_mistake(to_test, good_answers);
		else
			printf("ok\n");
		delete_both_arrays(&to_test, &good_answers);
		i++;
	}
}
