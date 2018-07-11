/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:16:48 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/05 22:02:51 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

int		ft_strcmp(char *s1, char *s2)
{
	int		ln;
	int		ln2;

	ln = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	while (*s1 == *s2 && !(*s1 == 0 || *s2 == 0))
	{
		ln2--;
		ln--;
		s1++;
		s2++;
	}
	if (ln == 0 && ln2 == 0)
		return (0);
	return (s1 - s2);
}
