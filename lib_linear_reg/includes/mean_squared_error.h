/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mean_squared_error.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:26:07 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 23:27:33 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEAN_SQUARED_ERROR_H
# define MEAN_SQUARED_ERROR_H

#include "matrix.h"
typedef struct s_mse_params
{
	t_matrix	*x_vals;
	t_matrix	*y_vals;
	float		w;
	float		b;
}	t_mse_params;

#endif
