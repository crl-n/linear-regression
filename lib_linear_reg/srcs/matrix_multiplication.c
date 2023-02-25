/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:27:05 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 15:15:48 by cnysten          ###   ########.fr       */
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

static int	dot_product_step(const t_matrix *lhs, const t_matrix *rhs, int lhs_row, int rhs_col)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (i < lhs->n_cols)
	{
		sum += matrix_get_val(lhs, lhs_row, i) * matrix_get_val(rhs, i, rhs_col);
		i++;
	}
	return (sum);
}

t_matrix	*matrix_dot_product(const t_matrix *lhs, const t_matrix *rhs)
{
	int			i;
	int			j;
	t_matrix	*result;

	if (lhs->n_cols != rhs->n_rows || lhs->elem_size != rhs->elem_size)
		return (0);
	result = matrix_new(lhs->n_rows, rhs->n_cols, lhs->elem_size);
	if (!result)
		return (0);
	i = 0;
	while (i < lhs->n_rows)
	{
		j = 0;
		while (j < rhs->n_cols)
		{
			result->data[matrix_calc_offset(result, i, j)] = dot_product_step(lhs, rhs, i, j);
			j++;
		}
		i++;
	}
	return (result);
}
