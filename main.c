/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:00:43 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 13:42:32 by cnysten          ###   ########.fr       */
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
	matrix_set_val(matrix, 2, 2, 42);
	matrix_print(matrix);
	return (0);
}
