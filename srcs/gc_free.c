/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 17:51:39 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free(void *garbage_to_free)
{
	t_gc_lst	**gc_lst;
	t_gc_lst	*current;
	t_gc_lst	*previous;

	gc_lst = _get_gc_lst();
	current = *gc_lst;
	previous = NULL;
	while (current->ptr != garbage_to_free)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
		*gc_lst = current->next;
	else
		previous->next = current->next;
	_gc_memdel((void **)&current->ptr);
	_gc_memdel((void **)&current);
}
