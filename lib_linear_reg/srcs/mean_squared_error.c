/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean_squared_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:38:04 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 23:49:04 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "gradient_descent.h"
#include "mean_squared_error.h"
#include <math.h>

static float	calc_sum_squared_error(t_mse_params params, float n)
{
	int		i;
	float	sum;
	float	x;
	float	y;

	sum = 0.0;
	i = 0;
	while (i < (int) n)
	{
		x = matrix_get_val(params.x_vals, 0, i);
		y = matrix_get_val(params.y_vals, 0, i);
		sum += pow((double) y - (params.w * x + params.b), 2);
		i++;
	}
	return (sum);
}

float	mean_squared_error(t_mse_params params)
{
	float	sum_squared_error;
	float	n;

	n = params.x_vals->n_cols;
	sum_squared_error = calc_sum_squared_error(params, n);
	return (sum_squared_error / n);
}
