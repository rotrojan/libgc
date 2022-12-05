/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2022/12/05 17:07:56 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	*gc_malloc(size_t size)
{
	t_garbage_lst	*tmp;
	t_garbage_lst	*new;
	t_garbage_lst	**garbage_lst;

	new = NULL;
	garbage_lst = _gc_get_garbage_lst();
	tmp = *garbage_lst;
	new = malloc(sizeof(t_garbage_lst) * 1);
	if (new == NULL)
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	_gc_bzero(new, sizeof(t_garbage_lst) * 1);
	new->ptr = malloc(size);
	if (new->ptr == NULL)
	{
		_gc_memdel((void **)&new);
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	}
	_gc_bzero(new->ptr, size);
	new->next = tmp;
	*garbage_lst = new;
	return (new->ptr);
}
