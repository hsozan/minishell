/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:37:58 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:38:01 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	Lexer 4 asamali prjenin ilk asamasidir. Burada amac
	girilen karisik komutlari sozcuk yapilarina ayirmaktir.
	orn komut: <a.txt cat| ls| wc -l | echo "ahmet $HOME''"selam
	lexer calistiktan sonra bagil liste deki
	contentlerin ciktisi soyle olmalidir:
	<, a.txt, cat, |, ls, |, wc, -l, |, echo, "ahmet $HOME''"selam'$PATH'
*/
void	lexer(void)
{
	g_core.lex_table = NULL;
	create_lexlist(g_core.cmd, &(g_core.lex_table));
	classify(g_core.lex_table);
	syntax_check();
}
