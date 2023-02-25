/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:00:43 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 14:43:47 by cnysten          ###   ########.fr       */
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

	matrix = matrix_new(4, 4, 16);
	if (!matrix)
		return (1);
	matrix_fill(matrix, 6);
	matrix_set_val(matrix, 2, 2, 42);
	matrix_print(matrix);
	matrix_fill(matrix, 1);
	t_matrix *result = matrix_scalar_mult(matrix, 42);
	puts("\n");
	matrix_print(result);
	return (0);
}
