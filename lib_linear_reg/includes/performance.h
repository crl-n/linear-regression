/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   performance.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:27:07 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:28:42 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERFORMANCE_H
# define PERFORMANCE_H

#include "linear_regression.h"

typedef struct s_perf_result
{
	float	r2_score;
	float	mean_squared_error;
	float	mean_absolute_error;
	float	mean_error;
}	t_perf_result;

t_perf_result	*measure_performace(int x_vals[], int x_len, int y_vals[], int y_len);
float			calc_r2_score(t_linear_model model);
float			calc_mean_squared_error(t_linear_model model);

#endif
