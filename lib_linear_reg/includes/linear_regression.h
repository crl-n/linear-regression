/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_regression.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:59:16 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:12:46 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LINEAR_REGRESSION_H
# define LINEAR_REGRESSION_H

#include "matrix.h"

typedef struct s_linear_model
{
	t_matrix	*x_vals;
	t_matrix	*y_vals;
	float		w;
	float		b;
}	t_linear_model;

t_linear_model	fit(t_linear_model model);

#endif
