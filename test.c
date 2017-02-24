/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:20:55 by ggane             #+#    #+#             */
/*   Updated: 2017/02/23 14:20:50 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	**split_delim(char *cmd, char *redirection);

void	check_answers(char **tested_strings, char **expected_results)
{

}

char	**create_expected_results(void)
{
	char	**expected_results;
	size_t	size;

	size = 9;
	if (!(expected_resultss = (char **)malloc(sizeof(char *) * size)))
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

char	**create_tested_strings(void)
{
	char	**tested_strings;
	size_t	size;

	size = 9;
	if (!(tested_strings = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	tested_string[0] = strdup("ls");
	tested_string[1] = strdup("ls -a");
	tested_string[2] = strdup("ls -l | wc -c");
	tested_string[3] = strdup("ls -l| wc -c");
	tested_string[4] = strdup("ls -l|wc -c");
	tested_string[5] = strdup("ls -l | wc -c -l | cat -e > file");
	tested_string[6] = strdup("ls -l|wc -c -l|cat -e>file>>file2");
	tested_string[7] = strdup("ls -l&&wc -c|| cat2>&1file");
	tested_string[8] = NULL;
	return (tested_strings);
}

int		main(void)
{
	char	**tested_strings;
	char	**expected_results;

	tested_strings = create_tested_strings();
	expected_results = create_expected_results();
	check_answers(tested_strings, expected_results);
	return (0);
}
