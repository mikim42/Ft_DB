/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 23:50:33 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:23:53 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_elem	*read_elem(char *s, t_tsv *e)
{
	t_elem	*new;
	t_field	*n_field;
	char	**split;
	int		i;
	int		len;

	i = -1;
	new = create_elem(e->elem_cnt);
	split = ft_strsplit(s, '\t');
	e->elem_cnt++ == 0 ? init_width(e, split) : 0;
	while (split[++i])
	{
		n_field = create_field(i, split[i]);
		add_field(&new->field, n_field);
		len = strlen(split[i]);
		len > e->f_width[i] ? e->f_width[i] = len : 0;
	}
	e->field_cnt = i;
	free(split);
	return (new);
}

int		open_file(t_tsv *e)
{
	char	*line;
	char	name[NAME_LEN - 12];
	t_elem	*new;

	e->elem_cnt = 0;
	print_directory(0);
	printf("\nfile name:");
	scanf(" %[^\n]%*c", name);
	strcat(e->file, name);
	if (3 > (e->fd = open(e->file, O_RDONLY)))
	{
		printf("\nFile Error, try again\n");
		return (main());
	}
	while (get_next_line(e->fd, &line) == 1)
	{
		new = read_elem(line, e);
		add_elem(&e->head, new);
		free(line);
		line = NULL;
	}
	close(e->fd);
	printf("\nread [%s] done\n", name);
	return (run_db(e));
}

int		new_file(t_tsv *e)
{
	char	name[NAME_LEN - 12];

	print_directory(1);
	printf("\nfile name:");
	scanf(" %[^\n]%*c", name);
	strcat(e->file, name);
	if (3 > (e->fd = open(e->file, O_CREAT | O_EXCL, 0644)))
	{
		printf("\nFile Error, try again\n");
		return (main());
	}
	e->head = create_elem(0);
	close(e->fd);
	printf("\ncreate [%s] done\n", name);
	return (run_db(e));
}

int		run_db(t_tsv *e)
{
	int	status;

	printf("\n[1] check data\n[2] add data\n[3] search data\n");
	printf("[4] update data\n[5] delete data\n[6] save data\n[7] exit\n");
	e->scan = scanf(" %d", &status);
	if (status == 1)
		return (check_data(e));
	else if (status == 2)
		return (add_data(e));
	else if (status == 3)
		return (search_data(e));
	else if (status == 4)
		return (update_data(e));
	else if (status == 5)
		return (delete_data(e));
	else if (status == 6)
		return (save_data(e));
	else if (status == 7)
		return (exit_free(e));
	else if (e->scan == 0)
		scanf("%c", &e->tmp);
	printf("\nError, try again\n");
	return (run_db(e));
}

int		main(void)
{
	t_tsv	e;
	int		status;

	init_tsv(&e);
	ft_printf("{SET:BO}{RED}----------------------------\n| {CYN}FT_DB");
	ft_printf("    {OFF}{SET:BO}{MGT}{SET:UL}By. mikim tzhou{OFF}");
	ft_printf("{SET:BO}{RED} |\n----------------------------{OFF}\n");
	printf("\n[1] open file\n[2] new file\n[3] exit\n");
	e.scan = scanf(" %d", &status);
	if (status == 1)
		return (open_file(&e));
	else if (status == 2)
		return (new_file(&e));
	else if (status == 3)
		return (0);
	else if (e.scan == 0)
		scanf("%c", &e.tmp);
	printf("\nError, try again\n");
	return (main());
}
