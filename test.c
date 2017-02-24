/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:20:55 by ggane             #+#    #+#             */
/*   Updated: 2017/02/24 13:06:30 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	**split_delim(char *cmd, char *redirection);

void	test_answers(char **commands, char **expected_results)
{
	int		i;
	char	**to_test;

	i = 0;
	while (commands[i] && expected_results[i])
	{
		to_test = split_delim(commands[i], "|<>&");
		if (check_wrong_results(to_tests, expected_results[i]))
			display_mistake(to_tests, expected_results[i]);
		else
			printf("ok\n");
		i++;
	}
}

char	**create_expected_results(void)
{
	char	**expected_results;
	size_t	size;

	size = 9;
	if (!(expected_results = (char **)malloc(sizeof(char *) * size)))
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

	size = 9;
	if (!(commands = (char **)malloc(sizeof(char *) * size)))
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
