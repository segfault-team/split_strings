#include "../libft/libft.h"

char		*split_command(char *line, char **delim);
static void	print_test(char **commands, int i)
{
	ft_putstr("test ");
	ft_putnbr(i);
	ft_putstr(" : ");
	ft_putstr(commands[i]);
}

static void	print_good_answer(char *expected_result, char *bad_answer)
{
	ft_putendl(" : failed");
	ft_putendl("----------------");
	ft_putendl("expected result is :");	
	ft_putendl(expected_result);
	ft_putendl("\n\t*****\n");
	ft_putendl("your result is :");
	ft_putendl(bad_answer);
	ft_putendl("----------------");
}

void		check_answers(char **commands, char **expected_results)
{
	const char	*delim[] = {">>", " ", ">", "<", "||", "|", "&&", "&", NULL};
	char		*answer;
	int	i;

	i = 0;
	while (commands[i])
	{
		print_test(commands, i);
		answer = split_command(commands[i], (char **)delim);
		if (!ft_strcmp(answer, expected_results[i]))
			ft_putendl(" : ok");
		else
			print_good_answer(expected_results[i], answer);
		ft_strdel(&answer);
		i++;
	}
}
