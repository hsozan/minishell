#include "../../../include/minishell.h"

/*
	Count degiskenine komutun ne kadar genislikte olmasi gerektigi get_cmdlen 
	fonksiyonu ile atanir.
	count buyuklugu kadar bellekte alan acilir ve bu alana count
	degiskeninde ki miktar kadar atanir.
	komutun adresi cmd_line degiskeninde tutuldugundan dolayi adres 
	uzerinden arttirilma islemleri yapilir.
	Boylece fonksiyonun cagirildigi yerde de adres arttirilmis olur.
*/
void	parse_cmd(char **cmd_line, t_lexlist *last_node)
{
	size_t	count;
	char	*holder_content;

	count = get_cmdlen(*cmd_line);
	holder_content = (char *)malloc(sizeof(char) * (count) + 1);
	last_node->content = holder_content;
	holder_content[count] = 0;
	while (count--)
		*(holder_content++) = *((*cmd_line)++);
}

/*
	Gelen komutta oncelikle bosluklar gecilir ardindan komutta sona gelinip
 	gelinmedigi kontrol edilir, gelde ise fonksiyon sonlandirilir.
	Eger sona gelinmedi ise yeni lexer listesinde yeni bir node olusturulur
	 ve olusturulan yeni node komut ayiriciya gonderilir.
	Ardindan recurisive ile komut sona gelene kadar fonksiyon tekrardan cagirilir.
*/
void	create_lexlist(char *cmdline, t_lexlist **lex_table)
{
	t_lexlist	*last_node;

	trim_spaces(&cmdline);
	if (!cmdline || !*cmdline)
		return ;
	last_node = add_new_lex_node(lex_table);
	parse_cmd(&cmdline, last_node);
	create_lexlist(cmdline, lex_table);
}
