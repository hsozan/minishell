#include "../../include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	set_title();
	g_core.exec_output = 0;
	g_core.old_exec_output = 0;
}
