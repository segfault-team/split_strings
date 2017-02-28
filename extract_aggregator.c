/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_aggregator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:16:26 by ggane             #+#    #+#             */
/*   Updated: 2017/02/28 20:05:22 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


size_t	since_aggr(char *line, int i)
{
	size_t	nb;

	nb = 0;	
	return (nb);
}

void	parcours_spaces(size_t *nb, int *i, char *line)
{
}

size_t	before_aggr(char *line, int i)
{
	size_t	nb;
	int		space;

	nb = 0;
	space = 0;
	if (line[i - 1] == ' ')
		parcours_spaces(&nb, line, &i);
	while (line[i - 1] == ' ')
	{
		i--;
		nb++;
	}
	while (i > 0)
	{
		if (line[i] == ' ')
			break ;
		nb++;
		i--;
	}
	return (nb);
}

size_t	get_nb_char(char *line, size_t (*count)(char *, int))
{
	size_t	nb;
	int		i;

	nb = 0;
	i = 0;
	while (line[i])
	{
		if ((line[i] == '>' && line[i + 1] == '&') || (line[i] == '&' &&
			line[i + 1] == '&'))
			return (nb = count(line, i));
		i++;
	}
	return (nb);
}

size_t	get_aggregator_size(char *line)
{
	size_t	(*count)(char *, int);
	size_t	size;

	count = &before_aggr;
	size = get_nb_char(line, count);
	count = &since_aggr;
	size = size + get_nb_char(line, count);
	return (size);
}

char	*get_aggregator(char *line)
{
	char	*aggregator;
	size_t	size;

	size = get_aggregator_size(line);
	if (!(aggregator = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	get_aggregator_char(&aggregator);
	return (aggregator);
}

int		aggregator_is_found(char *line)
{
	if (ft_strstr(line, "&>"))
		return (1);
	else if (ft_strstr(line, ">&"))
		return (1);
	return (0);
}

char	*check_aggregator(char *line)
{
	char	*aggregator;

	if (aggregator_is_found(line))
		aggregator = get_aggregator(line);
	else
		aggregator = NULL;
	return (aggregator);
}
