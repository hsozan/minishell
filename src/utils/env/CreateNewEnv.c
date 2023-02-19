/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateNewEnv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:43:18 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:43:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	mainde 3.parametre olarak aldığımız env değişkenini alır
	ve bağlı liste yapısına doldurur.
*/
void	fill_envs(char **env)
{
	while (env && *env)
		add_newenv(&g_core.env_table, *(env++));
}

/*
	bağlı liste yapısında henüz bir bode yok is onu yaratır
	var is sonuna gider ve ardına yeni bir node ekler.
	Gelen parametreyi oraya ekler.
*/
t_env	*add_newenv(t_env **env_table, char *env)
{
	t_env	*last_node;
	char	*content;

	if (!*env_table)
	{
		*env_table = (t_env *)malloc(sizeof(t_env));
		last_node = *env_table;
	}
	else
	{
		last_node = *env_table;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = (t_env *)malloc(sizeof(t_env));
		last_node = last_node->next;
	}
	last_node->env_name = get_env_name(env);
	content = env + ft_strlen(last_node->env_name);
	if (*content == '=' && *(content + 1))
		last_node->content = ft_strdup(content + 1);
	else
		last_node->content = NULL;
	last_node->next = NULL;
	return (last_node);
}

char	*get_env(char *env_name)
{
	t_env	*temp_env;

	temp_env = g_core.env_table;
	while (temp_env)
	{
		if (str_compare(env_name, temp_env->env_name))
			return (temp_env->content);
		temp_env = temp_env->next;
	}
	return (NULL);
}
