/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:00:43 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 15:23:21 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "matrix.h"

void	matrix_print(t_matrix *matrix)
{
	for (int i = 0; i < matrix->n_rows; i++)
	{
		for (int j = 0; j < matrix->n_cols; j++)
			printf("%i ", matrix_get_val(matrix, i, j));
		printf("\n");
	}
}

int	main(void)
{
	t_matrix	*matrix;

	matrix = matrix_new(4, 4, 4);
	if (!matrix)
		return (1);
	matrix_fill(matrix, 6);
	matrix_set_val(matrix, 2, 2, 42);
	matrix_print(matrix);
	matrix_fill(matrix, 1);
	t_matrix *result = matrix_scalar_mult(matrix, 42);
	puts("\n");
	matrix_print(result);
	puts("\n");

	t_matrix *lhs = matrix_new(2, 3, 4);
	matrix_set_val(lhs, 0, 0, 1);
	matrix_set_val(lhs, 0, 1, 2);
	matrix_set_val(lhs, 0, 2, 3);
	matrix_set_val(lhs, 1, 0, 4);
	matrix_set_val(lhs, 1, 1, 5);
	matrix_set_val(lhs, 1, 2, 6);
	t_matrix *rhs = matrix_new(3, 2, 4);
	matrix_set_val(rhs, 0, 0, 7);
	matrix_set_val(rhs, 0, 1, 8);
	matrix_set_val(rhs, 1, 0, 9);
	matrix_set_val(rhs, 1, 1, 10);
	matrix_set_val(rhs, 2, 0, 11);
	matrix_set_val(rhs, 2, 1, 12);
	matrix_print(lhs);
	puts("\n");
	matrix_print(rhs);
	puts("\n");

	t_matrix *product = matrix_dot_product(lhs, rhs);
	matrix_print(product);

	return (0);
}
