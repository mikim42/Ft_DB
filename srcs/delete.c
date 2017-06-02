/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 00:18:29 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		delete_field(t_tsv *e)
{
	int		status;
	char	tmp[50];

	if (0 > (status = print_fieldlist(e, &e->head->field)))
		return (delete_data(e));
	printf("\nyou really want to delete? [y/n]\n");
	scanf(" %[^\n]%*c", tmp);
	ft_lowcase(tmp);
	if (!(strcmp(tmp, "no")) || !(strcmp(tmp, "n")))
		return (delete_data(e));
	else if (!(strcmp(tmp, "yes")) || !(strcmp(tmp, "y")))
	{
		e->field_cnt--;
		return (delete_field_y(e, status));
	}
	else
		printf("\nError, try again\n");
	return (delete_field(e));
}

int		delete_elem_all(t_tsv *e)
{
	int		status;
	char	tmp[50];

	if (!(status = print_elemlist(e)))
		return (delete_data(e));
	printf("\nyou really want to delete? [y/n]\n");
	scanf(" %[^\n]%*c", tmp);
	ft_lowcase(tmp);
	if (!(strcmp(tmp, "no")) || !(strcmp(tmp, "n")))
		return (delete_data(e));
	else if (!(strcmp(tmp, "yes")) || !(strcmp(tmp, "y")))
	{
		e->elem_cnt--;
		return (delete_elem_all_y(e, status));
	}
	else
		printf("\nError, try again\n");
	return (delete_elem_all(e));
}

int		delete_elem_one(t_tsv *e)
{
	int		status[2];
	char	tmp[50];

	if (!(status[1] = print_elemlist(e)))
		return (delete_data(e));
	if (0 > (status[0] = print_fieldlist(e, &e->head->field)))
		return (delete_data(e));
	printf("\nyou really want to delete? [y/n]\n");
	scanf(" %[^\n]%*c", tmp);
	ft_lowcase(tmp);
	if (!(strcmp(tmp, "no")) || !(strcmp(tmp, "n")))
		return (delete_data(e));
	else if (!(strcmp(tmp, "yes")) || !(strcmp(tmp, "y")))
		return (delete_elem_one_y(e, status));
	else
		printf("\nError, try again\n");
	return (delete_elem_one(e));
}

int		delete_data(t_tsv *e)
{
	int	status;

	printf("\n[1] delete field\n[2] delete elem (all field)");
	printf("\n[3] delete elem (one field)\n[4] back to menu\n");
	e->scan = scanf(" %d", &status);
	if (status == 1)
		return (delete_field(e));
	else if (status == 2)
		return (delete_elem_all(e));
	else if (status == 3)
		return (delete_elem_one(e));
	else if (status == 4)
		return (run_db(e));
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (delete_data(e));
}
