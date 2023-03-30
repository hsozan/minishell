/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:45:26 by stunca            #+#    #+#             */
/*   Updated: 2023/02/19 14:45:26 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tables.h"
# include "macros.h"

//MAIN
void		parser(void);

//CREATECMDTABLE
void		create_cmdtable(t_lexlist *lex_table);
void		fill_cmdtable_node(t_cmdlist *node);
void		create_cmdtable_nodes(int count);

//FILLTABLE
void		fill_cmdtable(void);
void		fill_cmdnode(t_cmdlist *node, t_lexlist **lex_list);

char		**create_path(t_lexlist *lex_list);

int			create_new_filelist(t_cmdlist *node, t_lexlist **lex_list);
t_filelist	*add_filelist(t_filelist **file_list, char *filename, char *meta);

//CREATEFILES
void		create_files(t_cmdlist *node);

void		run_heredocs(t_cmdlist *node);
int			read_heredoc(t_cmdlist *node, char *eof);
void		set_heredoc_value(t_cmdlist *node, int *fd);
void		fill_heredoc(char *eof, int *fd);
char		*get_heredoc_values(char *eof);
char		*replace_line(char *old, char *replace, int begin, int start);
char		*env_check(char *line);

void		close_heredoc_file(void);
void		open_heredoc_file(char	*create_mode);

void		create_infile(t_cmdlist *node, t_filelist *file);

void		create_outfile(t_cmdlist *node, t_filelist *file);

int			check_directory_error(char *file_name);
int			raise_file_error(t_filelist *file, int *file_output);

//FREEPARSER
void		free_parser(void);
void		free_filelist(t_filelist *files);

void		print_files(t_filelist *temp_filelist);
void		print_parser(void);

#endif
