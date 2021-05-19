/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 17:48:44 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	*gc_malloc(size_t size)
{
	t_gc_lst	*tmp;
	t_gc_lst	*new;
	t_gc_lst	**gc_lst;

	new = NULL;
	gc_lst = _get_gc_lst();
	tmp = *gc_lst;
	new = malloc(sizeof(t_gc_lst));
	if (new == NULL)
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	_gc_bzero(new, sizeof(t_gc_lst));
	new->ptr = malloc(size);
	if (new->ptr == NULL)
	{
		_gc_memdel((void **)&new);
		gc_exit(EXIT_FAILURE, "malloc(): failed to allocate memory.\n");
	}
	_gc_bzero(new->ptr, size);
	new->next = tmp;
	*gc_lst = new;
	return (new->ptr);
}
