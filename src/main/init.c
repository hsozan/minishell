/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:39:12 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:39:12 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_usrname(void)
{
	t_env	*temp_env;

	temp_env = g_core.env_table;
	while (temp_env)
	{
		if (str_compare("USER", temp_env->env_name))
			g_core.usrname = temp_env->content;
		temp_env = temp_env->next;
	}
}

void	init_core(char **env)
{
	g_core.pid = -1;
	fill_envs(env);
	set_metachars();
	get_usrname();
	set_title();
	g_core.exec_output = 0;
	g_core.old_exec_output = 0;
}
