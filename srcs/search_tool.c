/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 04:18:16 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 17:35:17 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		search_update_one(t_tsv *e, int stat)
{
	t_elem	*ecur;
	t_field	*fcur;
	int		stat2;
	char	tmp[NAME_LEN];

	if (!(stat2 = print_fieldlist(e, &e->head->field)))
		return (search_data(e));
	printf("\nenter new elem[max:1KB]:");
	scanf(" %[^\n]%*c", tmp);
	ecur = e->head;
	while (ecur->id != stat)
		ecur = ecur->next;
	fcur = ecur->field;
	while (fcur->fnum != stat2)
		fcur = fcur->next;
	free(fcur->felem);
	fcur->felem = ft_strdup(tmp);
	e->f_width[stat2] < (int)strlen(tmp) ? e->f_width[stat2] = strlen(tmp) : 0;
	printf("\nupdate field done\n");
	return (search_data(e));
}

int		search_update_all(t_tsv *e, int stat)
{
	t_field	*lst;
	t_field	*fcur;
	t_elem	*ecur;
	char	tmp[NAME_LEN];

	ecur = e->head;
	while (ecur->id != stat)
		ecur = ecur->next;
	fcur = ecur->field;
	lst = e->head->field;
	while (lst)
	{
		printf("field:%s\n(null)->blank\nenter new elem[max:1KB]:", lst->felem);
		scanf(" %[^\n]%*c", tmp);
		free(fcur->felem);
		fcur->felem = ft_strdup(tmp);
		e->f_width[fcur->fnum] < (int)strlen(tmp) ?
		e->f_width[fcur->fnum] = strlen(tmp) : 0;
		lst = lst->next;
		fcur = fcur->next;
	}
	printf("\nupdate elem (all) done\n");
	return (search_data(e));
}

int		search_update(t_tsv *e)
{
	int status[2];

	printf("\n[1] update elem (all field)\n[2] update elem (one field)");
	printf("\n[3] back to search\n[4] back to menu\n");
	e->scan = scanf(" %d", &status[0]);
	if (status[0] == 1 || status[0] == 2)
	{
		printf("\nchoose elem_id from the list:");
		if (!(e->scan = scanf(" %d", &status[1])))
			;
		else if (status[0] == 1)
			return (search_update_all(e, status[1]));
		else
			return (search_update_one(e, status[1]));
	}
	else if (status[0] == 3)
		return (search_data(e));
	else if (status[0] == 4)
		return (run_db(e));
	if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (search_update(e));
}
