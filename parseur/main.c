#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define MAX_ARG 10
#define SIZE 256

const char *delim[] = {">>", " ", "<<", ">", "<", "||", "|", "&&", NULL};
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

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
                counter++;
                break;
            }
            i++;
        }
        while(ft_isalnum(*line) || *line == '-')
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

#define BUFF_DUP 4096

char *cut_word_by_delim(char **str, char **delim)
{
    char dup[BUFF_DUP];
    int len = 0;
    
    memset(dup, 0, BUFF_DUP);
    while (1)
    {
        while ((str[0]) && ((*str[0]) == ' '))
            str[0]++;
        while (str[0][len] && (ft_isalnum(str[0][len]) || str[0][len] == '-'))
            len++;
        if(len > 0)
        {
            strncpy(dup, str[0], len);
            str[0] = str[0] + len;
            return (strdup(dup));
        }
        len = 0;
        while(delim[len])
        {
            if(strncmp(str[0], delim[len], (int)strlen(delim[len])) == 0)
            {
                strncpy(dup, delim[len], strlen(delim[len]));
                str[0] = str[0] + strlen(delim[len]);
                return (strdup(dup));
            }
            len++;
        }
        len = 0;
    }
    return (NULL);
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

//pas le bon resultat pr : "ls -eeeee|wc>>>>>"

int main(int ac, char **av)
{
    char *line = "ls -eeeee|wc>>|e >";
    char **spliter = split_command(line, (char **)delim);
    int i = 0;
    while (spliter[i])
    {
        printf("element : %d vaut %s\n",i,spliter[i]);
        i++;
    }
    return(0);
}
