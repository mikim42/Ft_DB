/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:35:01 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		add_data_field(t_tsv *e)
{
	char	field[NAME_LEN];
	t_field	*new;

	if (e->field_cnt > 1000000)
	{
		printf("\ntoo many field. delete field or update\n");
		return (run_db(e));
	}
	printf("\ncurrent field lst:\n");
	print_field(e->head, e);
	printf("\nenter new field[max:1KB]:");
	scanf(" %[^\n]%*c", field);
	new = create_field(e->field_cnt++, ft_strdup(field));
	add_field(&e->head->field, new);
	update_fwidth(e, field);
	renew(e);
	printf("\nadd field done\n");
	return (add_data(e));
}

int		add_data_elem(t_tsv *e)
{
	t_elem	*new;
	t_field	*lst;
	t_field	*n_field;
	char	n_elem[NAME_LEN];

	if (e->elem_cnt > 1000000)
	{
		printf("\ntoo many elem. delete elem or update\n");
		return (run_db(e));
	}
	new = create_elem(e->elem_cnt++);
	lst = e->head->field;
	while (lst)
	{
		printf("field:%s\n(null)->blank\nenter new elem[max:1KB]:", lst->felem);
		scanf(" %[^\n]%*c", n_elem);
		n_field = create_field(lst->fnum, ft_strdup(n_elem));
		add_field(&new->field, n_field);
		e->f_width[lst->fnum] < (int)strlen(n_elem) ?
		e->f_width[lst->fnum] = strlen(n_elem) : 0;
		lst = lst->next;
	}
	add_elem(&e->head, new);
	printf("\nadd elem done\n");
	return (add_data(e));
}

int		add_data(t_tsv *e)
{
	int	status;

	printf("\n[1] add field\n[2] add elem\n[3] back to menu\n");
	e->scan = scanf(" %d", &status);
	if (status == 2 && e->head->field == NULL)
	{
		printf("\nadd field first\n");
		return (add_data(e));
	}
	else if (status == 1)
		return (add_data_field(e));
	else if (status == 2)
		return (add_data_elem(e));
	else if (status == 3)
		return (run_db(e));
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (add_data(e));
}
