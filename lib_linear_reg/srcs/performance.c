/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:35:57 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:30:59 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "performance.h"
#include "linear_regression.h"

t_perf_result	measure_performance(t_linear_model model)
{
	t_perf_result	result;

	result = (t_perf_result){
		.r2_score = calc_r2_score(model),
		.mean_squared_error = calc_mean_squared_error(model),
		/* .mean_squared_error = calc_mean_absolute_error(model), */
		/* .mean_error = calc_mean_error(), */
	};
	return (result);
}
