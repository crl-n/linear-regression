/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_descent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:33:05 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 22:39:13 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gradient_descent.h"
#include "matrix.h"

static t_gd_result	descend(t_gd_params params, t_gd_result result)
{
	(void) params;
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
