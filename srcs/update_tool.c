/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 04:49:38 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	update_fwidth(t_tsv *e, char *s)
{
	int	*width;
	int i;

	width = (int*)malloc(sizeof(int) * (e->field_cnt));
	i = -1;
	while (++i < e->field_cnt - 1)
		width[i] = e->f_width[i];
	width[i] = strlen(s);
	free(e->f_width);
	e->f_width = width;
}

int		print_elemlist(t_tsv *e)
{
	int		status;
	t_elem	*curr;

	printf("\nchoose elem_id in the list:\n[\x1B[1m0\x1B[0m]exit\n");
	curr = e->head;
	while (curr)
	{
		print_field(curr, e);
		curr = curr->next;
	}
	e->scan = scanf(" %d", &status);
	if (status > 0 && status <= e->elem_cnt)
		return (status);
	else if (status == 0)
		return (0);
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (print_elemlist(e));
}

int		print_fieldlist(t_tsv *e, t_field **head)
{
	t_field	*tmp;
	int		status;

	tmp = *head;
	printf("\nchoose a field in the list:\n[\x1B[1m0\x1B[0m]exit\n");
	while (tmp)
	{
		printf("[\x1B[1m%d\x1B[0m]%s\n", tmp->fnum + 1, tmp->felem);
		tmp = tmp->next;
	}
	e->scan = scanf(" %d", &status);
	if (status > 0 && status <= e->field_cnt)
		return (status - 1);
	else if (status == 0)
		return (-1);
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (print_fieldlist(e, &e->head->field));
}
