/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintParser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:41:02 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:41:02 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_files(t_filelist *temp_filelist)
{
	while (temp_filelist)
	{
		ft_printf("{fd: %d, ridrect : %s, filename : %s} ", temp_filelist->fd,
			temp_filelist->metachar, temp_filelist->filename);
		temp_filelist = temp_filelist->next;
	}
	ft_printf("\n\n");
}

void	print_parser(void)
{
	int			node_count;
	int			index;
	t_cmdlist	*temp_cmdlist;

	node_count = 1;
	temp_cmdlist = g_core.cmd_table;
	while (temp_cmdlist)
	{
		index = 0;
		ft_printf("------------NODE %d------------\n", node_count++);
		ft_printf("PATH: ");
		while (temp_cmdlist->path && temp_cmdlist->path[index])
			printf("%s; ", (temp_cmdlist->path[index++]));
		ft_printf("\nCMD: %s\n", temp_cmdlist->cmd);
		ft_printf("infile: %d\n", temp_cmdlist->infile);
		ft_printf("outfile: %d\n", temp_cmdlist->outfile);
		if (temp_cmdlist->heredoc_values)
			ft_printf("heredoc values: %s\n", temp_cmdlist->heredoc_values);
		ft_printf("pid: %d\n", temp_cmdlist->pid);
		ft_printf("~files~\n");
		print_files(temp_cmdlist->files);
		temp_cmdlist = temp_cmdlist->next;
	}
}
