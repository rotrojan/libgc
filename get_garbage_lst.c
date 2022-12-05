/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_garbage_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:18:42 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/05 15:08:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

t_garbage_lst	**get_garbage_lst(void)
{
	static t_garbage_lst	*garbage_lst = NULL;

	return (&garbage_lst);
}
