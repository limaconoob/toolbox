/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_voidpointer_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 11:26:40 by jpepin            #+#    #+#             */
/*   Updated: 2016/08/11 06:58:48 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

#include <stdio.h>

typedef struct		s_cat
{
	char			*str;
	char			*grt;
	char			*pwd;
	struct s_list	*next;
}					t_cat;

typedef struct		s_bim
{
	char			*str;
	int				nbr;
	struct s_list	*next;
}					t_bim;

void				*voidpointer_list(void)
{
	void			*master;

	if (!((master = (void*)malloc(1))))
		return (NULL);
	((t_bim*)master)->next = NULL;
	((t_bim*)master)->str = "bonjour";
	((t_bim*)master)->nbr = 123456789;
	((t_cat*)master)->grt = "connard";
	((t_cat*)master)->pwd = "prout";
	return (master);
}

int					main(void)
{
	t_bim			*master;
	t_cat			*tree;

	master = voidpointer_list();
	tree = voidpointer_list();
	printf("Master::%s %d\n", master->str, master->nbr);

	//	Dieser Satz nicht kompiliert, weil es kein 'nbr' Element in 't_cat' gibt
	//	'-> printf("Tree::%s %d\n", tree->str, tree->nbr);
	
	//	Aber hier es kompiliert, obgleich das kündigt 't_cat' tree
	//	mit ein 't_bim'-malloc-cast war, dann die 'str' Element zeigen ist.
	printf("Tree::%s\n", tree->str);

	//	Tree ist nur ein Adresse. Jedermann kann neue Element 
//	tree->grt = "retard";
//	tree->pwd = "Baümen";
	printf("Tree::%s %s\n", tree->grt, tree->pwd);
	free(master);
	free(tree);
}
