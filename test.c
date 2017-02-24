/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:20:55 by ggane             #+#    #+#             */
/*   Updated: 2017/02/24 15:13:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h> //to_delete
#define SIZE 9

char	**split_delim(char *cmd, char *redirection);

void	print_char_array(char **target)
{
	int		i;

	i = 0;
	if (!target)
		return ;
	ft_putendl("*******");
	while (target[i])
	{
		ft_putchar('[');
		ft_putstr(target[i]);
		ft_putendl("]");
		i++;
	}
	ft_putendl("*******");
}

void	delete_both_arrays(char ***ar1, char ***ar2)
{
	erase_char_array(*ar1);
	erase_char_array(*ar2);
}

void	display_mistake(char **to_test, char **good_answers)
{
	printf("failed\nYour answer :\n");
	print_char_array(to_test);
	printf("Expected answer :\n");
	print_char_array(good_answers);
}

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
		to_test = split_delim(commands[i], "|<>&");
		good_answers = ft_strsplit(expected_results[i], '^');
		if (check_wrong_answers(to_test, good_answers))
			display_mistake(to_test, good_answers);
		else
			printf("ok\n");
		delete_both_arrays(&to_test, &good_answers);
		i++;
	}
}

char	**create_expected_results(void)
{
	char	**expected_results;

	if (!(expected_results = (char **)malloc(sizeof(char *) * SIZE)))
		return (NULL);
	expected_results[0] = strdup("ls");
	expected_results[1] = strdup("ls^-a");
	expected_results[2] = strdup("ls^-l^|^wc^-c");
	expected_results[3] = strdup("ls^-l^|^wc^-c");
	expected_results[4] = strdup("ls^-l^|^wc^-c");
	expected_results[5] = strdup("ls^-l^|^wc^-c^-l^|^cat^-e^>^file");
	expected_results[6] = strdup("ls^-l^|^wc^-c^-l^|^cat^-e^>^file^>>^file2");
	expected_results[7] = strdup("ls^-l^&&^wc^-c^||^cat^2^>&^1^file");
	expected_results[8] = NULL;
	return (expected_results);
}

char	**create_commands(void)
{
	char	**commands;

	if (!(commands = (char **)malloc(sizeof(char *) * SIZE)))
		return (NULL);
	commands[0] = strdup("ls");
	commands[1] = strdup("ls -a");
	commands[2] = strdup("ls -l | wc -c");
	commands[3] = strdup("ls -l| wc -c");
	commands[4] = strdup("ls -l|wc -c");
	commands[5] = strdup("ls -l | wc -c -l | cat -e > file");
	commands[6] = strdup("ls -l|wc -c -l|cat -e>file>>file2");
	commands[7] = strdup("ls -l&&wc -c|| cat2>&1file");
	commands[8] = NULL;
	return (commands);
}

int		main(void)
{
	char	**commands;
	char	**expected_results;

	ft_putendl("start unit tests");
	commands = create_commands();
	expected_results = create_expected_results();
	test_answers(commands, expected_results);
	delete_both_arrays(&commands, &expected_results);
	ft_putendl("end unit tests");
	return (0);
}
