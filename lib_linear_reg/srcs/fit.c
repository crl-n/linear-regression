/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   train.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:14:22 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:14:31 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient_descent.h"
#include "linear_regression.h"
#include <stdio.h>

t_linear_model	fit(t_linear_model model)
{
	t_gd_params		params;
	t_gd_result		gd_result;

	params = (t_gd_params){
		.epochs = 10000,
		.learning_rate = 0.001,
		.model = model
	};
	gd_result = gradient_descent(params);
	printf("result in c -> w: %f\nb: %f\n", gd_result.w, gd_result.b);
	model.w = gd_result.w;
	model.b = gd_result.b;
	return (model);
}
