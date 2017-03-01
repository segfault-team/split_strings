/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:09:31 by ggane             #+#    #+#             */
/*   Updated: 2017/02/28 15:17:03 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int counter_argument(char *line, char **delim)
{
    int i = 0;
    int counter = 0;
    int must_increment = 0;
    
    while(*line)
    {
        while(*line == ' ')
            line++;
        while(delim[i])
        {
            if(strncmp(line, delim[i], (int)strlen(delim[i])) == 0)
            {
                line = line + strlen(delim[i]);
                if(*line != delim[i][0])
                    counter++;
                break;
            }
            i++;
        }
        while(ft_isalnum(*line) || *line == '-' || (delim[i] && *line == delim[i][0]))
        {
            line++;
            must_increment = 1;
        }
        if(must_increment == 1)
            counter++;
        i = 0;
        must_increment = 0;
    }
    return (counter);
}

static char *cut_word_by_delim(char **str, char **delim)
{
    char *dup;
    int len;
    int i;
    
    i = 0;
    len = 0;
    while ((str[0]) && ((*str[0]) == ' '))
        str[0]++;
    while(delim[len])
    {
        if(strncmp(str[0], delim[len], (int)strlen(delim[len])) == 0)
        {
            if(((str[0][strlen(delim[len])]) != delim[len][0]))
            {
                str[0] = str[0] + strlen(delim[len]);
                return (ft_strsub(delim[len], 0, strlen(delim[len])));
            }
            break;
        }
        len++;
    }
    while (str[0][i] && ((ft_isalnum(str[0][i]) || str[0][i] == '-') ||
                         (delim[len] && (str[0][i] == delim[len][0]))))
        i++;
    dup = ft_strsub(str[0], 0, i);
    str[0] = str[0] + i;
    return (dup);
}

/*
 * Function:  split_command(char *line, char **delim)
 * --------------------
 * Split la ligne de commande et l'insere dans un tableau 2d selon une serie de delimiteurs:
 *    exemple:
 *    -entree : $> ls -a| wc -e>> file
 *    -sortie : tableau[0] = ls, tableau[1] = -a, tableau[2] = |, tableau[3] = wc, tableau[4] = -e,
 *              tableau[5] = >>, tableau[6] = file, tableau[7] = NULL
 *
 *  argument(s) : "line" pour recuperer la ligne sur stdin (ne peut etre NULL)
 *                "delim" --> tableau de deux dimensions devant se terminer par un element NULL ou
 *                      chaque case est un delimiteur!!!
 *
 *  returns: retourne un tableau 2d formatté
 */

char **split_command(char *line, char **delim)
{
    
    int len_tab;
    char **formatted_array;
    int i;
    
    len_tab = counter_argument(line, delim);
    formatted_array = (char **)malloc(sizeof(*formatted_array) * len_tab + 1);
    i = 0;
    if(formatted_array)
    {
        while(i < len_tab)
        {
            formatted_array[i] = cut_word_by_delim(&line, delim);
            i++;
        }
    }
    formatted_array[i] = NULL;
    return (formatted_array);
}

