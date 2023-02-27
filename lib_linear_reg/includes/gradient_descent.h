/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient_descent.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:27:55 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/27 21:17:17 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_DESCENT_H
# define GRADIENT_DESCENT_H

#include "linear_regression.h"
#include "matrix.h"

typedef struct s_gd_params
{
	float			learning_rate;
	int				epochs;
	t_linear_model	model;
}	t_gd_params;

typedef struct s_gd_result
{
	float	w;
	float	b;
}	t_gd_result;

t_gd_result	gradient_descent(t_gd_params params);

#endif
