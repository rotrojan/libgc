/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:04:42 by lucocozz          #+#    #+#             */
/*   Updated: 2022/12/05 17:08:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free_all(void)
{
	t_garbage_lst	**garbage;
	t_garbage_lst	*current;
	t_garbage_lst	*next;

	garbage = _gc_get_garbage_lst();
	current = *garbage;
	while (current)
	{
		next = current->next;
		_gc_memdel((void **)&current->ptr);
		_gc_memdel((void **)&current);
		current = next;
	}
}
