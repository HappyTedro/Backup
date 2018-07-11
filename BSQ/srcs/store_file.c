/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:53:19 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/10 18:59:17 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

static	char	*create_file(void)
{
	int		fd;
	char	*name;

	name = "gorgeous_input";
	fd = open(name, O_EXCL | O_CREAT);
	close(fd);
	return (name);
}

char			*store_in_file(void)
{
	int		fd;
	char	buff[BUFF_SIZE];
	int		r;
	char	*name;

	name = create_file();
	fd = open(name, O_RDWR);
	while ((r = read(0, buff, BUFF_SIZE)) != 0)
		write(fd, buff, r);
	return (name);
}
