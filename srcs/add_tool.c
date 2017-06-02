/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/04 02:43:19 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_elem	*create_elem(int id)
{
	t_elem *new;

	new = (t_elem*)malloc(sizeof(t_elem));
	new->id = id;
	new->field = NULL;
	new->next = NULL;
	return (new);
}

void	add_elem(t_elem **head, t_elem *new)
{
	t_elem	*curr;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

t_field	*create_field(int n, char *s)
{
	t_field	*new;

	new = (t_field*)malloc(sizeof(t_field));
	new->fnum = n;
	new->felem = s;
	new->next = NULL;
	return (new);
}

void	add_field(t_field **head, t_field *new)
{
	t_field	*curr;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
