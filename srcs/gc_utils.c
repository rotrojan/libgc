/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:35:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 19:15:57 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	_gc_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	_gc_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	_gc_putstr_fd(int fd, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
}

void	_gc_putendl_fd(int fd, char const *str)
{
	_gc_putstr_fd(fd, str);
	write(fd, "\n", 1);
}

t_gc_lst	**_get_gc_lst(void)
{
	static t_gc_lst	*gc_lst = NULL;

	return (&gc_lst);
}
