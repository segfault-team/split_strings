/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:20:55 by ggane             #+#    #+#             */
/*   Updated: 2017/02/24 14:05:27 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 9

char	**split_delim(char *cmd, char *redirection);

void	print_char_array(char **target)
{
	int		i;

	i = 0;
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

void	delete_both_arrays(char **ar1, char **ar2)
{
	erase_char_array(a1);
	erase_char_array(a2);
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
		if (ft_strcmp(to_test[i], good_answer[i]))
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
		printf("test %d : ", i + 1);
		to_test = split_delim(commands[i], "|<>&");
		good_answers = ft_strsplit(expected_results, '^');
		if (check_wrong_results(to_tests, expected_results[i]))
			display_mistake(to_tests, expected_results[i]);
		else
			printf("ok\n");
		erase_char_array(good_answers);
		i++;
	}
	erase_char_array(to_test);
}

char	**create_expected_results(void)
{
	char	**expected_results;
	size_t	size;

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
	size_t	size;

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
	return (commandss);
}

int		main(void)
{
	char	**commands;
	char	**expected_results;

	commands = create_commands();
	expected_results = create_expected_results();
	test_answers(commands, expected_results);
	delete_both_arrays(commands, expected_results);
	return (0);
}
