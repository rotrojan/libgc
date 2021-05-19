/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:04:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 17:49:54 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free_all(void)
{
	t_gc_lst	**garbage;
	t_gc_lst	*current;
	t_gc_lst	*next;

	garbage = _get_gc_lst();
	current = *garbage;
	while (current)
	{
		next = current->next;
		_gc_memdel((void **)&current->ptr);
		_gc_memdel((void **)&current);
		current = next;
	}
}
