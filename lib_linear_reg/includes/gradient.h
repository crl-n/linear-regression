/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:49:40 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 23:58:06 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_H
# define GRADIENT_H

#include "matrix.h"

typedef struct s_gradient_params
{
	t_matrix	*x_vals;
	t_matrix	*y_vals;
	float		w;
	float		b;
}	t_gradient_params;

typedef struct s_gradient
{
	float		dw;
	float		db;
}	t_gradient;

t_gradient	calc_gradient(t_gradient_params params);

#endif
