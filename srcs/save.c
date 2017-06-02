/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:16:01 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	write_elem(t_elem *head, t_tsv *e)
{
	t_field	*curr;

	curr = head->field;
	while (curr)
	{
		dprintf(e->fd, "%s\t", curr->felem);
		curr = curr->next;
	}
	dprintf(e->fd, "\n");
}

int		save(t_tsv *e)
{
	t_elem	*curr;

	if (3 > (e->fd = open(e->file, O_WRONLY | O_CREAT | O_TRUNC, 0644)))
	{
		printf("\nFile Error, try again\n\nfile name:");
		scanf(" %[^\n]%*c", e->file);
		return (save(e));
	}
	printf("\nsaving file...\n");
	curr = e->head;
	while (curr)
	{
		write_elem(curr, e);
		curr = curr->next;
	}
	printf("\nsave file done\n");
	return (save_data(e));
}

int		save_data(t_tsv *e)
{
	int		status;
	char	name[NAME_LEN - 12];

	printf("\n[1] save\n[2] save as...\n[3] back to menu\n");
	e->scan = scanf(" %d", &status);
	if (status == 1)
		return (save(e));
	else if (status == 2)
	{
		printf("\nfile name:");
		scanf(" %[^\n]%*c", name);
		bzero(e->file, NAME_LEN);
		strcpy(e->file, PATH);
		strcat(e->file, name);
		return (save(e));
	}
	else if (status == 3)
		return (run_db(e));
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (save_data(e));
}
