/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:42:41 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 13:46:31 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>
#include <strings.h>

t_matrix	*matrix_new(int n_rows, int n_cols, int elem_size)
{
	t_matrix	*matrix;
	int			size_data;

	size_data = n_rows * n_cols * elem_size;
	if (size_data <= 0)
		return (0);
	matrix = malloc(sizeof (t_matrix) + size_data);
	if (!matrix)
		return (0);
	*matrix = (t_matrix){n_rows, n_cols, elem_size};
	bzero(matrix->data, size_data);
	return (matrix);	
}

int		matrix_calc_offset(t_matrix *matrix, int row, int col)
{
	return ((row * matrix->n_cols * matrix->elem_size) + (col * matrix->elem_size));
}

void	matrix_set_val(t_matrix *matrix, int row, int col, int val)
{
	int	offset;

	offset = matrix_calc_offset(matrix, row, col);
	*(matrix->data + offset) = val;
}

int		matrix_get_val(t_matrix *matrix, int row, int col)
{
	int	offset;

	offset = matrix_calc_offset(matrix, row, col);
	return (*(matrix->data + offset));
}
