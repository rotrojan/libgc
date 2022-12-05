/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:23 by rotrojan          #+#    #+#             */
/*   Updated: 2022/12/05 17:03:35 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_garbage_lst
{
	void					*ptr;
	struct s_garbage_lst	*next;
}							t_garbage_lst;

void			*gc_malloc(size_t size);
void			gc_free(void **garbage_to_free);
void			gc_free_all(void);
void			gc_exit(int status, char *message);

t_garbage_lst	**_gc_get_garbage_lst(void);
void			_gc_memdel(void **ap);
void			_gc_bzero(void *s, size_t n);
void			_gc_putstr_fd(int fd, char const *str);

#endif
