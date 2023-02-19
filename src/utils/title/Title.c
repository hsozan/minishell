/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Title.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:45:35 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:45:35 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	change_title(void)
{
	char	cwd[256];
	char	*tmp;

	tmp = getcwd(cwd, 256);
	if (g_core.title.full_title)
		free(g_core.title.full_title);
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.full_title, g_core.title.head);
	own_strjoin(&g_core.title.full_title, strrchr(tmp, '/'));
	own_strjoin(&g_core.title.full_title, "$ ");
}

/*
	burada her dongunun basinda yazilacak prompt olusturulur
	env'den expand edilerek yapilir.
*/
//	expand_envs(&g_core.title.head, "LOGNAME");
//	str_addchar(&g_core.title.head, '@');
//	expand_envs(&g_core.title.head, getenv("HOME"));
//	own_strjoin(&g_core.title.full_title, g_core.title.head);
//	own_strjoin(&g_core.title.full_title, "k2m10s07:~$ ");
///	own_strjoin(&g_core.title.full_title, g_core.title.head);
//	own_strjoin(&g_core.title.full_title, (char *)getcwd(cwd, 256));
//	own_strjoin(&g_core.title.full_title, "$ ");
void	set_title(void)
{
	g_core.title.head = NULL;
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.head, \
		"\033[0;36m▌│█║▌║▌║\033[0;32mᗰ i̇𝕟i̇$є𝓁 :\033[0;36m║▌║▌║█│▌:\033[0m");
	own_strjoin(&g_core.title.full_title, g_core.title.head);
}
