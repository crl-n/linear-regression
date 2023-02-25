/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:14:22 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 22:56:47 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient_descent.h"
#include "matrix.h"
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
	t_gd_params	params;

	print_array(x_vals, x_len);
	print_array(y_vals, y_len);

	params = (t_gd_params){
		.epochs = 400,
		.learning_rate = 0.01,
		.x_vals = matrix_from_int_array(x_vals, x_len),
		.y_vals = matrix_from_int_array(y_vals, y_len)
	};
	printf("train():\n");
	matrix_print(params.x_vals);
	matrix_print(params.y_vals);
	gradient_descent(params);
}

int	predict(int value)
{
	(void) value;
	return (42);
}
