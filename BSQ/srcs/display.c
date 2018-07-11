/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:11:57 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/10 16:36:27 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include "../includes/globals.h"

static	void	out(int i[3], int box_coord[2], void **instructions, char *buff)
{
	while (buff[i[2]] != '\n')
	{
		if (INBOX_X && INBOX_Y)
			write(1, &INS(char, 3), 1);
		else
			write(1, &buff[i[2]], 1);
		i[2]++;
		i[0]++;
	}
	write(1, "\n", 1);
	i[1]++;
	i[0] = 1;
	i[2] = 0;
}

void			display(char *av, void **instructions)
{
	int		fd;
	char	buff[INS(int, 4) + 1];
	int		i[3];
	int		box_coord[2];

	i[0] = 1;
	i[1] = 1;
	i[2] = 0;
	box_coord[0] = g_coord[0] - (g_max - 1);
	box_coord[1] = g_coord[1] - (g_max - 1);
	fd = open(av, O_RDONLY);
	while (*buff != '\n')
		read(fd, buff, 1);
	while (read(fd, buff, (INS(int, 4) + 1)))
		out(i, box_coord, instructions, buff);
	close(fd);
}
