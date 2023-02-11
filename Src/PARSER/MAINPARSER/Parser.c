#include "../../../Include/minishell.h"

void	parser(void)
{
	g_core.cmd_table = NULL;
	create_cmdtable(g_core.lex_table);
	fill_cmdtable();
	create_files(g_core.cmd_table);
}
