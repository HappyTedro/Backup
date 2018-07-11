/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 15:11:39 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/10 16:16:35 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"
#include "../includes/globals.h"

int		g_max = 0;
int		g_coord[2] = {1, 1};

static int	**create_matrix(void **instructions)
{
	int		**mtx;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mtx = (int**)malloc(sizeof(int*) * (INS(int, 0) + 1));
	while (i <= INS(int, 0))
		mtx[i++] = (int*)malloc(sizeof(int) * (INS(int, 4) + 1));
	i = 0;
	while (i < (INS(int, 0) + 1))
		mtx[i++][0] = 0;
	while (j < (INS(int, 4) + 1))
		mtx[0][j++] = 0;
	return (mtx);
}

static int	lst(int v_1, int v_2, int v_3)
{
	int		lst;

	lst = ((v_1 - v_2) > 0) ? v_2 : v_1;
	lst = ((lst - v_3) > 0) ? v_3 : lst;
	return (lst);
}

static int	**fill_mtx(int **mtx, char buff, void **instructions, int i[3])
{
	int		l;

	if (buff == INS(char, 1))
	{
		l = lst(CRD((i[0] - 1), i[1]), CRD(i[0], (i[1] - 1)),
				CRD((i[0] - 1), (i[1] - 1)));
		CRD(i[0], i[1]) = (l + 1);
	}
	else
		CRD(i[0], i[1]) = 0;
	if (CRD(i[0], i[1]) > g_max)
	{
		g_max = CRD(i[0], i[1]);
		g_coord[0] = i[0];
		g_coord[1] = i[1];
	}
	return (mtx);
}

static	int	**filler(int **mtx, char *buff, void **instructions, int i[3])
{
	while (buff[i[2]] != '\n')
	{
		mtx = fill_mtx(mtx, buff[i[2]++], instructions, i);
		i[0]++;
	}
	i[0] = 1;
	i[2] = 0;
	i[1]++;
	return (mtx);
}

void		find_square(char *av, void **instructions)
{
	char	buff[INS(int, 4) + 1];
	int		fd;
	int		i[3];
	int		lines;
	int		**mtx;

	i[0] = 1;
	i[1] = 1;
	i[2] = 0;
	fd = open(av, O_RDONLY);
	lines = INS(int, 0);
	mtx = create_matrix(instructions);
	while (*buff != '\n')
		read(fd, buff, 1);
	while (i[1] <= lines)
		while (read(fd, buff, (INS(int, 4) + 1)))
			mtx = filler(mtx, buff, instructions, i);
	i[0] = 0;
	while (i[0] < INS(int, 0) + 1)
		free(mtx[i[0]++]);
	free(mtx);
	close(fd);
}
