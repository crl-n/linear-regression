/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:42:41 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 23:03:56 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

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

int		matrix_calc_offset(const t_matrix *matrix, int row, int col)
{
	return ((row * matrix->n_cols * matrix->elem_size) + (col * matrix->elem_size));
}

void	matrix_set_val(t_matrix *matrix, int row, int col, int val)
{
	int	offset;

	offset = matrix_calc_offset(matrix, row, col);
	*(matrix->data + offset) = val;
}

int		matrix_get_val(const t_matrix *matrix, int row, int col)
{
	int	offset;

	offset = matrix_calc_offset(matrix, row, col);
	return (*(matrix->data + offset));
}

void	matrix_fill(t_matrix *matrix, int val)
{
	int	i;
	
	i = 0;
	while (i < matrix->n_rows * matrix->n_cols)
	{
		*(matrix->data + (i * matrix->elem_size)) = val;
		i++;
	}
}

t_matrix	*matrix_from_int_array(int vals[], int len)
{
	t_matrix	*matrix;
	int			i;

	matrix = matrix_new(1, len, sizeof (float));
	if (!matrix)
		return (0);
	i = 0;	
	while (i < len)
	{
		matrix_set_val(matrix, 0, i, (float) vals[i]);
		i++;
	}
	return (matrix);
}

void	matrix_print(t_matrix *matrix)
{
	for (int i = 0; i < matrix->n_rows; i++)
	{
		for (int j = 0; j < matrix->n_cols; j++)
			printf("%i ", matrix_get_val(matrix, i, j));
		printf("\n");
	}
}
