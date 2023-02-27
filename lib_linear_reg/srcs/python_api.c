/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   python_api.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:43:16 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:13:44 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_regression.h"
#include "memdup.h"

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

t_linear_model	*py_fit(int x_vals[], int x_len, int y_vals[], int y_len)
{
	t_linear_model	model;

	model = (t_linear_model){
		.x_vals = matrix_from_int_array(x_vals, x_len),
		.y_vals = matrix_from_int_array(y_vals, y_len),
		.b = 0.0,
		.w = 0.0
	};
	model = fit(model);
	return (memdup((void *) &model, sizeof (t_linear_model)));
}