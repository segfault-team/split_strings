# split_command
>###### Defini dans header<jensaisrien.h>

------
#### char    **split_command(char       *line, char     **delim)
------
Split la ligne de commande et l'insere dans un tableau 2d selon une serie de delimiteurs:

## Parametres
**line**  - pour recuperer la ligne sur stdin (ne peut etre NULL)

**delim** - tableau de deux dimensions devant se terminer par un element NULL ou 
            chaque case est un delimiteur!!!

## Valeur retournée
Retourne un tableau 2d formatté

## Exemple
```c
#include <stdio.h>

const char *delim[] = {">>", " ", "<<", ">", "<", "||", "|", "&&", NULL};

int main(int ac, char **av)
{
    char *line = "ls -a| wc -e>> file";
    char **spliter = split_command(line, (char **)delim);
    int i = 0;
    while (spliter[i])
    {
        printf("%d.%s\t",i,spliter[i]);
        i++;
    }
    return(0);
}
```
Output:
```
1.ls    2.-a    3.|     4.wc    5.-e    6.>>    7.file
```
