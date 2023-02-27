/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_descent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:33:05 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:16:37 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient_descent.h"
#include "matrix.h"
#include "gradient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* static void	gradient_print(t_gradient gradient) */
/* { */
/* 	printf("dw: %f\ndb: %f\n", gradient.dw, gradient.db); */
/* } */

static t_gd_result	descend(t_gd_params params, t_gd_result result)
{
	t_gradient_params	gradient_params;
	t_gradient			gradient;

	gradient_params = (t_gradient_params){
		.w = result.w,
		.b = result.b,
		.x_vals = params.model.x_vals,
		.y_vals = params.model.y_vals
	};
	gradient = calc_gradient(gradient_params);
	/* gradient_print(gradient); */
	result.w -= params.learning_rate * gradient.dw;
	result.b -= params.learning_rate * gradient.db;
	/* printf("w: %f\nb: %f\n", result.w, result.b); */
	return (result);
}

t_gd_result	gradient_descent(t_gd_params params)
{
	int			epoch;
	t_gd_result	result;

	result = (t_gd_result){.w = 0.0, .b = 0.0};
	epoch = 0;
	while (epoch < params.epochs)
	{
		result = descend(params, result);
		epoch++;
	}
	return (result);
}
