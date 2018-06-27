/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:17:10 by otahirov          #+#    #+#             */
/*   Updated: 2018/06/24 17:23:25 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_putchar(char c);
int		g_cngspace = 2;
int		g_cngstars = 4;
int		g_door_size[2] = {1, 1};

void	drawchunk(int i, int *spaces, int *stars)
{
	int		a;
	int		lines;

	lines = 3 + i;
	a = 0;
	while (lines > 0)
	{
		while (*spaces > a++)
			ft_putchar(' ');
		a = 0;
		ft_putchar('/');
		while (*stars > a++)
			ft_putchar('*');
		ft_putchar('\\');
		ft_putchar('\n');
		*spaces -= 1;
		*stars += 2;
		lines--;
		a = 0;
	}
}

void	draw_door(int *stars, int i)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (((*stars - g_door_size[0]) / 2) > a++)
		ft_putchar('*');
	while (g_door_size[0] > b++)
	{
		if (g_door_size[0] > 3 && i - 1 == g_door_size[1] / 2)
		{
			if (b == g_door_size[0] - 1)
			{
				ft_putchar('$');
				ft_putchar('|');
			}
			else if (b != g_door_size[0])
				ft_putchar('|');
		}
		else
			ft_putchar('|');
	}
	while ((*stars - (g_door_size[0] - 1)) > a++)
		ft_putchar('*');
}

void	draw_doorchunk(int i, int *spaces, int *stars)
{
	int		a;
	int		lines;

	lines = 3 + i;
	a = 0;
	while (lines > 0)
	{
		while (*spaces > a++)
			ft_putchar(' ');
		a = 0;
		ft_putchar('/');
		if (lines > g_door_size[1])
		{
			while (*stars > a++)
				ft_putchar('*');
		}
		else
			draw_door(stars, lines);
		*spaces -= 1;
		*stars += 2;
		ft_putchar('\\');
		ft_putchar('\n');
		lines--;
		a = 0;
	}
}

void	logic(int *spaces, int *stars, int size, int i)
{
	i = 0;
	g_door_size[1] += 2 * ((size - 1) / 2);
	g_door_size[0] += 2 * ((size - 1) / 2);
	while (i < size)
	{
		if ((i - 1) % 2 == 0 && i != 1)
		{
			g_cngspace += 1;
			g_cngstars += 2;
		}
		if (i != 0)
		{
			*spaces -= (g_cngspace);
			*stars += (g_cngstars);
		}
		if ((i + 1) != size && size != 1)
			drawchunk(i, spaces, stars);
		else
			draw_doorchunk(i, spaces, stars);
		i++;
	}
}

void	sastantua(int size)
{
	int		stars;
	int		spaces;
	int		cng;
	int		i;
	int		lines;

	i = 0;
	cng = 2;
	lines = 2;
	spaces = 0;
	stars = 1;
	while (i < size)
	{
		if ((i - 1) % 2 == 0 && i > 1)
			cng++;
		spaces += lines++;
		if (i == 0)
			lines++;
		if (i > 0 && size > 1)
			spaces += cng;
		i++;
	}
	if (size > 0)
		logic(&spaces, &stars, size, i);
}
