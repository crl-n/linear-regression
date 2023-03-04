/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:00:43 by cnysten           #+#    #+#             */
/*   Updated: 2023/03/04 21:13:52 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "matrix.h"
#include "linear_regression.h"
#include "linear_regression.h"

int	main(void)
{
	t_linear_model	model;
	t_matrix		*x_vals;
	t_matrix		*y_vals;

	x_vals = matrix_from_int_array((int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10);
	if (!x_vals)
		return (1);
	y_vals = matrix_from_int_array((int[]){10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 10);
	if (!y_vals)
		return (1);
	model = (t_linear_model){
		.x_vals = x_vals,
		.y_vals = y_vals
	};
	fit(model);
	return (0);
}
