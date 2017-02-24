/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_display_delete_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:24:27 by ggane             #+#    #+#             */
/*   Updated: 2017/02/24 17:09:25 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h> //to_delete

char	**split_delim(char *cmd, char *redirection);
int		check_wrong_answers(char **to_test, char **good_answers);
void	test_answers(char **commands, char **expected_results);
size_t	get_file_line_number(char *file);
char	**copy_lines_in_file(int fd, char **array);
char	**create_array_from_file(char *file);

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
