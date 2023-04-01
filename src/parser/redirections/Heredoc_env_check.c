/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heredoc_env_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:26 by stunca            #+#    #+#             */
/*   Updated: 2023/04/01 14:59:17 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
normdan kaçmak için(void)new yazıldı.
*/
void	set_n(char *new)
{
	(void)new;
	g_core.n.i = 0;
	g_core.n.j = 0;
	g_core.n.s = 0;
}

char	*replace_line(char *old, char *replace, int begin, int start)
{
	char	*new;

	new = malloc(sizeof(char) * 100000);
	set_n(new);
	while (old[g_core.n.i])
	{
		if (g_core.n.i == begin)
		{
			while ((size_t)g_core.n.s < ft_strlen(replace))
			{
				new[g_core.n.j] = replace[g_core.n.s];
				g_core.n.j++;
				g_core.n.s++;
			}
			g_core.n.i = g_core.n.i + start - 1;
		}
		else
		{
			new[g_core.n.j] = old[g_core.n.i];
			g_core.n.j++;
		}
		g_core.n.i++;
	}
	new[g_core.n.j] = '\0';
	return (new);
}

char	*env_loop(char *name, char *line)
{
	char	*temp;

	while (line[g_core.n.i])
	{
		if (line[g_core.n.i] == '$' && line[g_core.n.i + 1] != '\0' \
		&& line[g_core.n.i + 1] != ' ')
		{
			while (g_core.n.flag == 0 && (size_t)g_core.n.s < ft_strlen(line))
			{
				temp = ft_strpcpy(NULL, &line[g_core.n.i + 1], g_core.n.s);
				if (get_env(temp) != NULL)
				{
					g_core.n.flag = 1;
					name = get_env(temp);
					g_core.n.j = g_core.n.i;
				}
				g_core.n.s++;
			}
		}
	g_core.n.i++;
	}
	return (name);
}

char	*env_check(char *line)
{
	char	*name;
	char	*newline;

	g_core.n.flag = 0;
	name = malloc(sizeof(char) * 100);
	set_n(name);
	newline = malloc(sizeof(char) * 100000);
	name = env_loop(name, line);
	if (g_core.n.flag == 1)
		newline = replace_line(line, name, g_core.n.j, g_core.n.s);
	else
		newline = line;
	return (newline);
}
