/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:39:47 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:39:47 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sig_handler(int signum)
{
	if (g_core.is_read_arg != 1)
		ft_printf("\n%s", ft_strtonl(g_core.title.head));
	(void)signum;
	if (signal_in_reading())
		return ;
	if (signal_while_cmd_works())
		return ;
	g_core.exec_output = SIGNAL_C;
	write(1, "\n", 1);
	free_for_loop();
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

int	signal_in_reading(void)
{
	if (g_core.is_read_arg && g_core.pid == 0)
	{
		free_for_loop();
		free_core();
		exit(SIGNAL_C);
	}
	else if (g_core.is_read_arg && g_core.pid != 0)
	{
		g_core.exec_output = SIGNAL_C;
		return (1);
	}
	return (0);
}

int	signal_while_cmd_works(void)
{
	t_cmdlist	*cmd_list;
	int			return_value;

	return_value = 0;
	cmd_list = g_core.cmd_table;
	while (cmd_list)
	{
		if (cmd_list->pid >= 0)
			return_value |= waitpid(cmd_list->pid, 0, 0);
		cmd_list = cmd_list->next;
	}
	if (return_value)
	{
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	exit_signal_check(void)
{
	if (!g_core.cmd)
	{
		ft_printf(g_core.title.full_title);
		print_error("^+D : Exits ./minishell\n", 0, 0);
		free_core();
		exit(EXIT_SUCCESS);
	}
}
