#include "../../../include/minishell.h"

void	change_title(void)
{
	char	cwd[256];

	if (g_core.title.full_title)
		free(g_core.title.full_title);
	g_core.title.full_title = NULL;
	own_strjoin(&g_core.title.full_title, g_core.title.head);
	own_strjoin(&g_core.title.full_title, (char *)getcwd(cwd, 256));
	own_strjoin(&g_core.title.full_title, "$ ");
}

/*
	burada her dongunun basinda yazilacak prompt olusturulur
	env'den expand edilerek yapilir.
*/
void	set_title(void)
{
	g_core.title.head = NULL;
	g_core.title.full_title = NULL;
//	expand_envs(&g_core.title.head, "LOGNAME");
//	str_addchar(&g_core.title.head, '@');
//	expand_envs(&g_core.title.head, getenv("HOME"));
//	own_strjoin(&g_core.title.full_title, g_core.title.head);
//	own_strjoin(&g_core.title.full_title, "k2m10s07:~$ ");
	own_strjoin(&g_core.title.head, "🚨ⓜ ⓘ ⓝ ⓘ ⓢ ⓗ ⓔ ⓛ ⓛ 🚨:");
	own_strjoin(&g_core.title.full_title, g_core.title.head);
///	own_strjoin(&g_core.title.full_title, g_core.title.head);
//	own_strjoin(&g_core.title.full_title, (char *)getcwd(cwd, 256));
//	own_strjoin(&g_core.title.full_title, "$ ");
}
