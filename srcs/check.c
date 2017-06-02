/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 00:46:35 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		print_field(t_elem *head, t_tsv *e)
{
	t_field	*tmp;
	int		i;

	if (head->field == NULL)
		return (printf("(null)\n"));
	tmp = head->field;
	i = 0;
	while (tmp && ++i)
	{
		if (i == 1)
			head->id == 0 ? printf("\x1B[31m|\x1B[1m%5s\x1B[0m", "No.") :
			printf("\x1B[31m|\x1B[1m%5d\x1B[0m", head->id);
		if (!(strcmp(tmp->felem, "(null)")) && head->id != 0)
			printf("\x1b[31m|\x1B[0m%*s", e->f_width[tmp->fnum], " ");
		else
			head->id == 0 ?
		printf("\x1B[31m|\x1B[1m%*s\x1B[0m", e->f_width[tmp->fnum], tmp->felem)
		: printf("\x1B[31m|\x1B[0m%*s", e->f_width[tmp->fnum], tmp->felem);
		tmp = tmp->next;
	}
	return (printf("\x1B[31m|\x1B[0m\n"));
}

int		check_data(t_tsv *e)
{
	t_elem *curr;

	curr = e->head;
	printf("\n-- Start\n");
	while (curr)
	{
		print_field(curr, e);
		curr = curr->next;
	}
	printf("-- End\n\n");
	return (run_db(e));
}
