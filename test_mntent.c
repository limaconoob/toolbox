/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mntent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 02:55:32 by jpepin            #+#    #+#             */
/*   Updated: 2016/04/18 03:12:06 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mntent.h>

int				main(void) {
	struct mntent *me;
	mntfp = setmntent( "/etc/mtab", "r" );
	while((me = getmntent(mntfp)) != NULL)
	{
		printf("mnt_fsname: %s,mnt_dir: %s, mnt_type:%s\n",
				me->mnt_fsname,
				me->mnt_dir,
				me->mnt_type);
	}
}
