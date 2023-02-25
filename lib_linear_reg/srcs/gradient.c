/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:48:26 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/26 00:01:47 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient.h"
#include <math.h>

static float	calc_dw(t_gradient_params params, float n)
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
		sum +=  -2.0 * x * (y - (params.w * x + params.b));
		i++;
	}
	return (sum / n);
}

static float	calc_db(t_gradient_params params, float n)
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
		sum += -2.0 * (y - (params.w * x + params.b));
		i++;
	}
	return (sum / n);
}

t_gradient	calc_gradient(t_gradient_params params)
{
	float		dw;
	float		db;
	float		n;
	t_gradient	gradient;

	n = params.x_vals->n_cols;
	dw = calc_dw(params, n);
	db = calc_db(params, n);
	gradient = (t_gradient) {.dw = dw, .db = db};
	return (gradient);
}
