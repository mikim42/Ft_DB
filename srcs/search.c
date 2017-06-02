/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 04:18:16 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 17:35:02 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		search_one(t_tsv *e)
{
	t_elem	*ecur;
	t_field	*fcur;
	int		status;
	char	tmp[NAME_LEN];

	if (0 > (status = print_fieldlist(e, &e->head->field)))
		return (search_data(e));
	printf("\nenter search key:");
	scanf(" %[^\n]%*c", tmp);
	ecur = e->head;
	print_field(e->head, e);
	while (ecur)
	{
		fcur = ecur->field;
		while (fcur->fnum <= status)
		{
			if (fcur->fnum == status && strstr(fcur->felem, tmp))
				print_field(ecur, e);
			fcur = fcur->next;
		}
		ecur = ecur->next;
	}
	return (search_update(e));
}

int		search_all(t_tsv *e)
{
	t_elem	*ecur;
	t_field	*fcur;
	char	tmp[NAME_LEN];

	printf("\nenter search key:");
	scanf(" %[^\n]%*c", tmp);
	ecur = e->head;
	print_field(e->head, e);
	while (ecur)
	{
		fcur = ecur->field;
		while (fcur)
		{
			if (strstr(fcur->felem, tmp))
				print_field(ecur, e);
			fcur = fcur->next;
		}
		ecur = ecur->next;
	}
	return (search_update(e));
}

int		search_data(t_tsv *e)
{
	int status;

	printf("\n[1] search all\n[2] search by field\n[3] back to menu\n");
	e->scan = scanf(" %d", &status);
	if (status == 1)
		return (search_all(e));
	else if (status == 2)
		return (search_one(e));
	else if (status == 3)
		return (run_db(e));
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (search_data(e));
}
