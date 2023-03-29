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
	char	*tmp2;

	if (g_core.title.full_title)
		free(g_core.title.full_title);
	g_core.title.full_title = NULL;
	tmp = ft_strtonl(g_core.title.head);
	tmp2 = getcwd(cwd, 256);
	own_strjoin1(&tmp, "-\033[0;32m[\033[0m");
	if (str_compare(g_core.usrname, ft_strrchr(tmp2, '/') + 1))
		own_strjoin1(&tmp, "~");
	else
		own_strjoin1(&tmp, ft_strrchr(tmp2, '/') + 1);
	own_strjoin1(&tmp, "\033[0;32m]\n\033[0;36m└──\033[0;32m╼\033[0;36m$");
	own_strjoin(&g_core.title.full_title, tmp);
	own_strjoin(&g_core.title.full_title, "\033[0m");
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
/*void	set_title(void)
{
	g_core.title.head = NULL;
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.head, "\033[0;36m▌│█║▌║▌║\033[0;32mᗰ ");
	own_strjoin(&g_core.title.head, TITLE);
	own_strjoin(&g_core.title.head, "\033[0;32m");
	own_strjoin(&g_core.title.full_title, g_core.title.head);
}*/
void	set_title(void)
{
	g_core.title.head = NULL;
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.head, "\033[0;36m┌──\033[0;32m(\033[0;34m");
	own_strjoin(&g_core.title.head, g_core.usrname);
	own_strjoin(&g_core.title.head, "\033[0;32m@\033[0;34m" );
	own_strjoin(&g_core.title.head, "minishell\033[0;32m)\n");
	own_strjoin(&g_core.title.head, "\033[0;36m└──");
	own_strjoin(&g_core.title.head, "\033[0;32m╼\033[0;36m$");
	own_strjoin(&g_core.title.head, "\033[0m");
	own_strjoin(&g_core.title.full_title, g_core.title.head);
}
