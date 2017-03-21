/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggane <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 08:33:10 by ggane             #+#    #+#             */
/*   Updated: 2017/03/21 08:33:11 by ggane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef parsing_h
#define parsing_h

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char **split_command(char *line, char **delim);

#endif /* parsing_h */
