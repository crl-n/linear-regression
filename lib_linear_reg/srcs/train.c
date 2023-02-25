/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:14:22 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/26 00:47:49 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient_descent.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* static void	print_array(int array[], size_t n) */
/* { */
/* 	size_t	i; */

/* 	i = 0; */
/* 	while (i < n) */
/* 	{ */
/* 		printf("%i", array[i]); */
/* 		i++; */
/* 	} */
/* 	printf("\n"); */
/* } */

t_gd_result	*train(int x_vals[], int x_len, int y_vals[], int y_len)
{
	t_gd_params	params;
	t_gd_result	result;

	/* print_array(x_vals, x_len); */
	/* print_array(y_vals, y_len); */

	params = (t_gd_params){
		.epochs = 10000,
		.learning_rate = 0.001,
		.x_vals = matrix_from_int_array(x_vals, x_len),
		.y_vals = matrix_from_int_array(y_vals, y_len)
	};
	printf("train():\n");
	/* matrix_print(params.x_vals); */
	/* matrix_print(params.y_vals); */
	result = gradient_descent(params);
	printf("result in c -> w: %f\nb: %f\n", result.w, result.b);
	return (gd_result_new(result));
}
