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

#include "parsing.h"

static int ft_isquote(int c)
{
    if(c == '\"')
        return 1;
    return 0;
}

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
        if(ft_isquote(*line))
        {
            must_increment = 1;
            while(*line++)
            {
                if(*line == '\"')
                {
                    line++; //moche
                    break;
                }
            }
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
        if(str[0][0] == '"')
        {
            i = 1;
            while(str[0][i] != '"')
                i++;
            dup = str[0];
            str[0] = str[0] + ++i;
            return (ft_strsub(dup, 0, i));
        }
        
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
