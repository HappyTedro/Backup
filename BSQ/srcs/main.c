/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otahirov <otahirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:36:48 by otahirov          #+#    #+#             */
/*   Updated: 2018/07/10 19:19:56 by otahirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int		main(int ac, char **av)
{
	int		fd;
	void	**instructions;
	char	*name;

	if (ac >= 1)
	{
		if (ac != 1)
		{
			while (**av)
			{
				find_square(*av, instructions);
				display(*av, instructions);
				av++;
			}
		}
		else
		{
			name = store_in_file();
			find_square(name, instructions);
			display(name, instructions);
			exit(0);
		}
	}
	return (0);
}

/*
*	//?	IF TRUE.
*	//TODO: Check.
*	//?		IF TRUE.
*	//*			FIND THE X AND Y.					-> DONE.
*	//*			DISPLAY.							-> DONE.
*	//?		ELSE.
*	//*			WRITE AN ERROR AND MOVE TO THE NEXT MAP.
*/

/*
*	//? ELSE.
*	//TODO: Check.
*	//!		Store the files in a new file			-> DONE.
*	//?		IF TRUE.
*	//*			FIND THE X AND Y IN THE NEW FILE.	-> DONE.
*	//?		ELSE.
*	//*			WRITE AN ERROR IN STDERR AND EXIT
*/