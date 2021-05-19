/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/19 19:13:32 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_exit(int status, char *message)
{
	gc_free_all();
	if (status == EXIT_SUCCESS && message != NULL)
		_gc_putendl_fd(STDOUT_FILENO, message);
	else
	{
		_gc_putstr_fd(STDERR_FILENO, "Error: ");
		_gc_putendl_fd(STDERR_FILENO, message);
	}
	exit(status);
}
