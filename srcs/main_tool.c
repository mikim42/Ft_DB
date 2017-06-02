/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:27:20 by mikim             #+#    #+#             */
/*   Updated: 2017/05/05 18:21:30 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	print_directory(int stat)
{
	DIR				*dir;
	struct dirent	*dp;

	if (!(dir = opendir(PATH)))
	{
		printf("\ndatabase directory doesn't exist\n");
		if (mkdir(PATH, 07777) == 0)
			printf("create directory done\n");
		else
			exit(printf("fail to create directory\ntry again\n"));
		dir = opendir(PATH);
	}
	if (stat == 1)
		return ;
	printf("\nchoose a file in the list:\n");
	while ((dp = readdir(dir)))
		if (!(strcmp(dp->d_name, ".")) || !(strcmp(dp->d_name, "..")))
			;
		else
			printf("[%s]\n", dp->d_name);
}

int		exit_free(t_tsv *e)
{
	t_elem	*curr;
	t_elem	*prev;

	printf("\nclosing program");
	free(e->f_width);
	curr = e->head;
	while (curr)
	{
		printf(".");
		prev = curr;
		delete_elem_field(curr->field);
		curr = curr->next;
		free(prev);
	}
	close(e->fd);
	printf("\nprogram closed.\n");
	return (0);
}
