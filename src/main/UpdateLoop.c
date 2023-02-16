#include "../../include/minishell.h"

void	update_loop(void)
{
	g_core.old_exec_output = g_core.exec_output;
	g_core.exec_output = 0;
//	update_exec_output();
	g_core.is_read_arg = 0;
}

void	update_history(char *cmd)
{
	char	*ptr;

	if (!cmd)
		return ;
	ptr = cmd;
	trim_spaces(&ptr);
	if (!*ptr)
		return ;
	add_history(cmd);
}

void	update_exec_output(void)
{
	g_core.old_exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.old_exec_output = g_core.old_exec_output ^ g_core.exec_output;
	g_core.exec_output = 0;
}
