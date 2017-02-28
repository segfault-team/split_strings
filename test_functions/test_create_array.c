/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_create_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:21:18 by ggane             #+#    #+#             */
/*   Updated: 2017/02/28 15:19:42 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>

char	**split_delim(char *cmd, char **delim);
void	print_char_array(char **target);
void	delete_both_arrays(char ***ar1, char ***ar2);
void	display_mistake(char **to_test, char **good_answers);
int		check_wrong_answers(char **to_test, char **good_answers);
void	test_answers(char **commands, char **expected_results);

void	display_open_error_msg(void)
{
	ft_putendl_fd("\topen() failed", 2);
	ft_putendl_fd("end of unit tests", 2);
	exit(EXIT_FAILURE);
}

size_t	get_file_line_number(char *file)
{
	int		fd;
	char	*line;
	size_t	size;

	size = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		display_open_error_msg();
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		size++;
	}
	close(fd);
	return (size);
}

char	**copy_lines_in_file(int fd, char **array)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		array[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (array);
}

char	**create_array_from_file(char *file)
{
	int		fd;
	size_t	size;
	char	**array;

	size = get_file_line_number(file);
	if ((fd = open(file, O_RDONLY)) == -1)
		display_open_error_msg();
	if (!(array = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	array = copy_lines_in_file(fd, array);
	array[size] = NULL;
	close(fd);
	return (array);
}
