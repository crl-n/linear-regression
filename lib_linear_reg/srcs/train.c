/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:14:22 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/21 23:08:45 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <Python.h> */
#include <stdio.h>

static void	print_array(int array[], size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%i", array[i]);
		i++;
	}
	printf("\n");
}

void	train(int x_vals[], int x_len, int y_vals[], int y_len)
{
	print_array(x_vals, x_len);
	print_array(y_vals, y_len);
}

int	predict(int value)
{
	(void) value;
	return (42);
}
