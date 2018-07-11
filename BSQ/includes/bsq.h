/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:36:42 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/10 18:12:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# define CRD(x, y) mtx[y][x]
# define INS(type, v) (*((type *)(instructions[v])))
# define INBOX_X (i[0] >= box_coord[0] && i[0] <= g_coord[0])
# define INBOX_Y (i[1] >= box_coord[1] && i[1] <= g_coord[1])
# define BUFF_SIZE 42

int			ft_atoi(char *str);
void		ft_putchar(char c);
void		ft_putnbr(long nb, int ln);
int			ft_nbrln(long nb);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_swap(int *a, int *b);
void		find_square(char *av, void **instructions);
void		display(char *av, void **instructions);
char		*store_in_file(void);

#endif
