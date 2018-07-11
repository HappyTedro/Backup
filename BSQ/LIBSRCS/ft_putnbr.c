/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 18:01:37 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/07 12:32:16 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_nbrln(int nb)
{
	int		ln;

	ln = 0;
	while (nb > 10)
	{
		ln++;
		nb /= 10;
	}
	return (++ln);
}

void	ft_putnbr(int nb)
{
	int		denominator;
	int		i;
	int		ln;

	i = 1;
	ln = ft_nbrln(nb);
	denominator = 1;
	while (i < ln)
	{
		denominator *= 10;
		i++;
	}
	while (ln > 0)
	{
		ft_putchar((char)(nb / denominator) + 48);
		nb %= denominator;
		denominator /= 10;
		ln--;
	}
}
