/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:20:33 by ggane             #+#    #+#             */
/*   Updated: 2017/02/28 15:19:21 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h> //to_delete
#include <fcntl.h>

char	*split_delim(char *cmd, char **delim);
void	print_char_array(char **target);
void	delete_both_arrays(char ***ar1, char ***ar2);
void	display_mistake(char **to_test, char **good_answers);
int		check_wrong_answers(char **to_test, char **good_answers);
void	test_answers(char **commands, char **expected_results);
size_t	get_file_line_number(char *file);
char	**copy_lines_in_file(int fd, char **array);
char	**create_array_from_file(char *file);
void	check_answers(char **commands, char **expected_results);

int		main(void)
{
	char	**commands;
	char	**expected_results;

	ft_putendl("start unit tests\n");
	commands = create_array_from_file("test_functions/test_texts/commands.txt");
	expected_results = create_array_from_file("test_functions/test_texts/expected_results.txt");
	/* test_answers(commands, expected_results); */
	check_answers(commands, expected_results);
	delete_both_arrays(&commands, &expected_results);
	ft_putendl("\nend unit tests");
	return (0);
}
