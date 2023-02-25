/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:27:05 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 14:39:04 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	*matrix_scalar_mult(const t_matrix *matrix, const int scalar)
{
	int			i;
	int			offset;
	t_matrix	*result;

	result = matrix_new(matrix->n_rows, matrix->n_cols, matrix->elem_size);
	if (!result)
		return (0);
	i = 0;
	while (i < matrix->n_cols * matrix->n_rows)
	{
		offset = i * matrix->elem_size;
		result->data[offset] = matrix->data[offset] * scalar;
		i++;
	}
	return (result);
}
