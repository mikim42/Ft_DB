/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renew.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 00:16:10 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 00:46:00 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	zero_width(t_tsv *e)
{
	int i;

	i = 0;
	e->f_width[0] = 3;
	while (++i < e->field_cnt)
		e->f_width[i] = 5;
}

void	renew_width(t_tsv *e, t_field *cur)
{
	int	len;

	len = strlen(cur->felem);
	e->f_width[cur->fnum] < len ? e->f_width[cur->fnum] = len : 0;
}

void	renew_empty(t_field *cur, int cnt)
{
	if (cur->next)
		return ;
	else if (cnt > cur->fnum)
		cur->next = create_field(cur->fnum + 1, ft_strdup("(null)"));
}

void	renew(t_tsv *e)
{
	t_elem	*ecur;
	t_field	*fcur;
	int		cnt[2];

	cnt[0] = 0;
	ecur = e->head;
	zero_width(e);
	while (ecur)
	{
		ecur->id = cnt[0]++;
		fcur = ecur->field;
		cnt[1] = 0;
		while (fcur)
		{
			fcur->fnum = cnt[1]++;
			renew_width(e, fcur);
			cnt[1] < e->field_cnt ? renew_empty(fcur, cnt[1]) : 0;
			fcur = fcur->next;
		}
		ecur = ecur->next;
	}
}
