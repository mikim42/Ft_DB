/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 02:43:13 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:12:16 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	init_width(t_tsv *e, char **sp)
{
	int i;
	int j;

	i = 0;
	while (sp[i])
		i++;
	e->f_width = (int*)malloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		e->f_width[j] = 5;
}

void	init_tsv(t_tsv *e)
{
	e->field_cnt = 0;
	e->elem_cnt = 1;
	e->f_width = NULL;
	e->fd = -1;
	e->scan = 0;
	bzero(e->file, NAME_LEN);
	strcpy(e->file, PATH);
	e->head = NULL;
}
