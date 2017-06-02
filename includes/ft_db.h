/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 19:14:20 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:21:47 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"

# define NAME_LEN 1024
# define PATH "./.database/"

typedef struct		s_field
{
	int				fnum;
	char			*felem;
	struct s_field	*next;
}					t_field;

typedef	struct		s_elem
{
	int				id;
	t_field			*field;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_tsv
{
	int				field_cnt;
	int				elem_cnt;
	int				*f_width;
	int				fd;
	int				scan;
	char			tmp;
	char			file[NAME_LEN];
	t_elem			*head;
}					t_tsv;

/*
**					main // yes. we need proto type of MAIN.
*/

int					main(void);
int					new_file(t_tsv *e);
int					open_file(t_tsv *e);
t_elem				*read_elem(char *s, t_tsv *e);
int					run_db(t_tsv *e);

/*
**					tool
*/

int					exit_free(t_tsv *e);
void				print_directory(int stat);

/*
**					init
*/

void				init_tsv(t_tsv *e);
void				init_width(t_tsv *e, char **sp);

/*
**					tool
*/

t_elem				*create_elem(int id);
void				add_elem(t_elem **head, t_elem *new);
t_field				*create_field(int n, char *s);
void				add_field(t_field **head, t_field *new);

/*
**					check
*/

int					check_data(t_tsv *e);
int					print_field(t_elem *curr, t_tsv *e);

/*
**					add
*/

int					add_data(t_tsv *e);
int					add_data_field(t_tsv *e);
int					add_data_elem(t_tsv *e);

/*
**					search
*/

int					search_data(t_tsv *e);
int					search_all(t_tsv *e);
int					search_one(t_tsv *e);
int					search_update(t_tsv *e);
int					search_update_all(t_tsv *e, int stat);
int					search_update_one(t_tsv *e, int stat);

/*
**					update
*/

int					update_data(t_tsv *e);
int					update_field(t_tsv *e);
int					update_elem(t_tsv *e);
void				update_fwidth(t_tsv *e, char *s);
int					print_fieldlist(t_tsv *e, t_field **head);
int					print_elemlist(t_tsv *e);

/*
**					delete
*/

int					delete_data(t_tsv *e);
int					delete_field(t_tsv *e);
int					delete_field_y(t_tsv *e, int stat);
int					delete_elem_all(t_tsv *e);
int					delete_elem_all_y(t_tsv *e, int stat);
void				delete_elem_field(t_field *head);
int					delete_elem_one(t_tsv *e);
int					delete_elem_one_y(t_tsv *e, int status[2]);

/*
**					save
*/

int					save_data(t_tsv *e);
int					save(t_tsv *e);
void				write_elem(t_elem *head, t_tsv *e);

/*
**					renew
*/

void				renew(t_tsv *e);
void				renew_empty(t_field *cur, int cnt);
void				zero_width(t_tsv *e);
void				renew_width(t_tsv *e, t_field *cur);

#endif
