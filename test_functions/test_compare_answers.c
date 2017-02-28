/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare_answers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:27:21 by ggane             #+#    #+#             */
/*   Updated: 2017/02/28 15:26:15 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h> //to_delete
#include <fcntl.h>

char	**split_delim(char *line, char **delim);
void	print_char_array(char **target);
void	delete_both_arrays(char ***ar1, char ***ar2);
void	display_mistake(char **to_test, char **good_answers);
size_t	get_file_line_number(char *file);
char	**copy_lines_in_file(int fd, char **array);
char	**create_array_from_file(char *file);

void	display_split_delim_error_msg(void)
{
	ft_putendl_fd("\tsplit_delim() returned NULL string's array", 2);
	ft_putendl_fd("\tunit tests won't run with a NULL string's array", 2);
	ft_putendl_fd("end of unit tests", 2);
	exit(EXIT_FAILURE);
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
	const char	*delim[] = {">>", " ", "<<", ">", "<", "||", "|", "&&", "&", NULL};

	i = 0;
	while (commands[i] && expected_results[i])
	{
		if (!(to_test = split_delim(commands[i], (char **)delim)))
			display_split_delim_error_msg();
		printf("test %d : [%s]\n", i + 1, commands[i]);
		good_answers = ft_strsplit(expected_results[i], '^');
		if (check_wrong_answers(to_test, good_answers))
			display_mistake(to_test, good_answers);
		else
			printf("ok\n");
		delete_both_arrays(&to_test, &good_answers);
		i++;
	}
}
