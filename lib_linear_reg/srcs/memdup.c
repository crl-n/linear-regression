/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:03 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:07:26 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memdup.h"

void	*memdup(void *src, size_t size_bytes)
{
	void	*dst;

	dst = malloc(size_bytes);
	if (!dst)
		return (0);
	memcpy(dst, src, size_bytes);
	return (dst);
}
