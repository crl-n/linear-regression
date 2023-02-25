/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:43:50 by cnysten           #+#    #+#             */
/*   Updated: 2023/02/25 22:54:47 by cnysten          ###   ########.fr       */
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
int			matrix_calc_offset(const t_matrix *matrix, int row, int col);
void		matrix_set_val(t_matrix *matrix, int row, int col, int val);
int			matrix_get_val(const t_matrix *matrix, int row, int col);
void		matrix_fill(t_matrix *matrix, int val);
t_matrix	*matrix_scalar_mult(const t_matrix *matrix, const int scalar);
t_matrix	*matrix_dot_product(const t_matrix *lhs, const t_matrix *rhs);
t_matrix	*matrix_from_int_array(int vals[], int len);
void		matrix_print(t_matrix *matrix);

#endif
