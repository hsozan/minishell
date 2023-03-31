/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintExpander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:46 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:36:46 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_expander(void)
{
	t_lexlist	*lexer_temp;

	lexer_temp = g_core.lex_table;
	ft_printf ("~EXPANDER TABLE~\n");
	while (lexer_temp)
	{
		ft_printf("{type: %d, content: %s}\n", lexer_temp->type,
			lexer_temp->content);
		lexer_temp = lexer_temp->next;
	}
	ft_printf("\n\n");
}
