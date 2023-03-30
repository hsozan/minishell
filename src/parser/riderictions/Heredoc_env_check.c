/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heredoc_env_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:26 by stunca            #+#    #+#             */
/*   Updated: 2023/03/30 17:38:10 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*replace_line(char *old, char *replace, int begin, int start)
{
	char	*new;
	int		i;
	int		j;
	int		s;

	new = malloc(sizeof(char) * 100000);
	i = 0;
	j = 0;
	s = 0;
	while (old[i])
	{
		if (i == begin)
		{
			while (s < ft_strlen(replace))
			{
				new[j] = replace[s];
				j++;
				s++;
			}
			i = i + start - 1;
		}
		else
		{
			new[j] = old[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

char	*env_check(char *line)
{
	char	*name;
	char	*newline;
	int		i;
	int		s;
	int		flag;
	int		j;

	i = 0;
	s = 0;
	flag = 0;
	name = malloc(sizeof(char) * 100);
	newline = malloc(sizeof(char) * 100000);
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != '\0' && line[i + 1] != ' ')
		{
			while (flag == 0 && (size_t)s < ft_strlen(line))
			{
				if (get_env(ft_strpcpy(NULL, &line[i + 1], s)) != NULL)
				{
					flag = 1;
					name = get_env(ft_strpcpy(NULL, &line[i + 1], s));
					j = i;
				}
				s++;
			}
		}
	i++;
	}
	if (flag == 1)
		newline = replace_line(line, name, j,s);
	else
		newline = line;
	return (newline);
}
