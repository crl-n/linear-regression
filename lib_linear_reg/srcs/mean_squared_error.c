/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean_squared_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:38:04 by cnysten           #+#    #+#             */
/*   Updated: 2023/03/05 00:25:19 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_regression.h"
#include "matrix.h"
#include "performance.h"
#include <math.h>
#include <stdio.h>

static float	calc_sum_squared_error(t_linear_model model, float n)
{
	int		i;
	float	sum;
	float	x;
	float	y;

	sum = 0.0;
	i = 0;
	/* printf("w %f b %f\n", model.w, model.b); */
	while (i < n)
	{
		x = matrix_get_val(model.x_vals, 0, i);
		y = matrix_get_val(model.y_vals, 0, i);
		sum += pow(y - (model.w * x + model.b), 2.0);
		/* printf("x = %f, y = %f, sum %f\n", x, y, sum); */
		i++;
	}
	return (sum);
}

float	calc_mean_squared_error(t_linear_model model)
{
	float	sum_squared_error;
	int		n;

	n = model.x_vals->n_cols;
	sum_squared_error = calc_sum_squared_error(model, n);
	/* printf("SSE: %f\n", sum_squared_error); */
	return (sum_squared_error / n);
}
