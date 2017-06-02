/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:37:04 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		update_field(t_tsv *e)
{
	t_field	*curr;
	int		status;
	char	tmp[NAME_LEN];

	if (0 > (status = print_fieldlist(e, &e->head->field)))
		return (update_data(e));
	printf("\nenter new elem[max:1KB]:");
	scanf(" %[^\n]%*c", tmp);
	curr = e->head->field;
	while (curr->fnum != status)
		curr = curr->next;
	curr->felem == NULL ? 0 : free(curr->felem);
	curr->felem = ft_strdup(tmp);
	e->f_width[status] < (int)strlen(tmp) ?
	e->f_width[status] = strlen(tmp) : 0;
	printf("\nupdate field done\n");
	return (update_data(e));
}

int		update_elem_one(t_tsv *e)
{
	t_elem	*ecur;
	t_field	*fcur;
	int		status[2];
	char	tmp[NAME_LEN];

	if (!(status[1] = print_elemlist(e)))
		return (update_data(e));
	if (0 > (status[0] = print_fieldlist(e, &e->head->field)))
		return (update_data(e));
	printf("\nenter new elem[max:1KB]:");
	scanf(" %[^\n]%*c", tmp);
	ecur = e->head;
	while (ecur->id != status[1])
		ecur = ecur->next;
	fcur = ecur->field;
	while (fcur->fnum != status[0])
		fcur = fcur->next;
	free(fcur->felem);
	fcur->felem = ft_strdup(tmp);
	e->f_width[status[0]] < (int)strlen(tmp) ?
	e->f_width[status[0]] = strlen(tmp) : 0;
	printf("\nupdate elem (one) done\n");
	return (update_data(e));
}

int		update_elem_all(t_tsv *e, int status)
{
	t_field	*lst;
	t_field	*fcur;
	t_elem	*ecur;
	char	tmp[NAME_LEN];

	if (!(status = print_elemlist(e)))
		return (update_data(e));
	ecur = e->head;
	while (ecur->id != status)
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
	return (update_data(e));
}

int		update_data(t_tsv *e)
{
	int status;

	printf("\n[1] update field\n[2] update elem (all field)");
	printf("\n[3] update elem (one field)\n[4] back to menu\n");
	e->scan = scanf(" %d", &status);
	if (status == 1)
		return (update_field(e));
	else if (status == 2)
		return (update_elem_all(e, 0));
	else if (status == 3)
		return (update_elem_one(e));
	else if (status == 4)
		return (run_db(e));
	else if (e->scan == 0)
		scanf(" %c", &e->tmp);
	printf("\nError, try again\n");
	return (update_data(e));
}
