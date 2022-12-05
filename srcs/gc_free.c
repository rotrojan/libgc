/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2022/12/05 17:08:11 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free(void **garbage_to_free)
{
	t_garbage_lst	**garbage_lst;
	t_garbage_lst	*current;
	t_garbage_lst	*previous;

	previous = NULL;
	if (*garbage_to_free != NULL && garbage_to_free != NULL)
	{
		garbage_lst = _gc_get_garbage_lst();
		current = *garbage_lst;
		while (current->ptr != *garbage_to_free)
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
			*garbage_lst = current->next;
		else
			previous->next = current->next;
		_gc_memdel((void **)&current->ptr);
		_gc_memdel((void **)&current);
		*garbage_to_free = NULL;
	}
}
