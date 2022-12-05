/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <rotrojan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2022/12/05 16:48:03 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_exit(int status, char *message)
{
	if (message != NULL)
	{
		if (status == EXIT_FAILURE)
			_gc_putstr_fd(STDERR_FILENO, "Error: ");
		_gc_putstr_fd(STDERR_FILENO, message);
		_gc_putstr_fd(STDERR_FILENO, "\n");
	}
	exit(status);
}
