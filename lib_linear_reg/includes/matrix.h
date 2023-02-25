/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:43:50 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 13:43:25 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	int				n_rows;
	int				n_cols;
	int				elem_size;
	unsigned char	data[];
}	t_matrix;

t_matrix	*matrix_new(int n_rows, int n_cols, int elem_size);
int			matrix_calc_offset(t_matrix *matrix, int row, int col);
void		matrix_set_val(t_matrix *matrix, int row, int col, int val);
int			matrix_get_val(t_matrix *matrix, int row, int col);

#endif
