/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 16:33:59 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		delete_elem_one_y(t_tsv *e, int status[2])
{
	t_elem	*ecur;
	t_field	*fcur;

	ecur = e->head;
	while (ecur->id != status[1])
		ecur = ecur->next;
	fcur = ecur->field;
	while (fcur->fnum != status[0])
		fcur = fcur->next;
	free(fcur->felem);
	fcur->felem = ft_strdup("(null)");
	renew(e);
	printf("\ndelete elem (one) done\n");
	return (delete_data(e));
}

void	delete_field_one(t_field **head, int stat)
{
	t_field *cur;
	t_field	*prv;

	cur = *head;
	if (cur->fnum == stat)
	{
		free(cur->felem);
		*head = cur->next;
		free(cur);
		return ;
	}
	while (cur)
	{
		prv = cur;
		cur = cur->next;
		if (cur->fnum == stat)
		{
			prv->next = cur->next;
			free(cur->felem);
			free(cur);
			return ;
		}
	}
}

int		delete_field_y(t_tsv *e, int stat)
{
	t_elem	*curr;

	curr = e->head;
	while (curr)
	{
		delete_field_one(&curr->field, stat);
		curr = curr->next;
	}
	renew(e);
	printf("\ndelete field done\n");
	return (delete_data(e));
}

void	delete_elem_field(t_field *head)
{
	if (head == NULL)
		return ;
	free(head->felem);
	delete_elem_field(head->next);
	free(head);
}

int		delete_elem_all_y(t_tsv *e, int stat)
{
	t_elem	*prv;
	t_elem	*cur;

	cur = e->head;
	if (cur->id == stat)
	{
		delete_elem_field(cur->field);
		e->head = cur->next;
		free(cur);
		cur = NULL;
	}
	while (cur->id != stat)
	{
		prv = cur;
		cur = cur->next;
		if (cur->id == stat)
		{
			prv->next = cur->next;
			delete_elem_field(cur->field);
			free(cur);
		}
	}
	renew(e);
	printf("\ndelete elem (all) done\n");
	return (delete_data(e));
}
