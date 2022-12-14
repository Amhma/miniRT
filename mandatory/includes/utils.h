/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:04:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/09/18 00:53:49 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs_utils.h"

//		utils/ft_gnl_rt.c
char	*ft_gnl_rt(int fd);

//		utils/error_msg.c
void	error_msg(char *str);

//		utils/vector_math.c
void	vector_ab(t_pos a, t_pos b, t_pos *vec);
double	dot_product(t_pos a, t_pos b);
double	vector_norm(t_pos vec);
void	vector_add(t_pos a, t_pos b, t_pos *vec);
void	set_vector(float x, float y, float z, t_pos *vec);

//		utils/vector_math2.c
double	dist_ab(const t_pos *a, const t_pos *b);
void	vector_equal(const t_pos src, t_pos *dest);
void	cross_product(t_pos a, t_pos b, t_pos *dst);
void	vector_multi(t_pos a, t_pos b, t_pos *dst);
void	vector_sub(t_pos a, t_pos b, t_pos *dst);

//		utils/vector_math3.c
void	unit_vector(t_pos *vec);
void	vector_scale(float scale, t_pos *dst);

//		utils/color_utils.c
t_rgb	gen_rgb(const int r, const int g, const int b);
void	c_mult(const t_pos *c1, const t_rgb *c2, t_rgb *dest);
void	c_add(const t_rgb *c1, const t_rgb *c2, t_rgb *dest);
void	c_scale(const float f, t_rgb *rgb);

//		utils/bbox_utils.c
void	bbox_center(const t_box *box, t_pos *center);
float	bbox_expend(const t_box *box);

//		utils/quicksort_lst_custom.c

void	sort_list_custom(t_list **lst, const t_pos *origin,
			unsigned int begin, unsigned int end);
int		cmp_nearest_vol(const t_vol *left, const t_vol *right,
			const t_pos *origin);

//		utils/debug.c
void	print_vol(void *vol);
void	print_pos(const t_pos *pos, const char *str);

//		utils/struct_utils.c
void	pos_cpy(const t_pos *src, t_pos *dest);
void	col_cpy(const t_rgb *src, t_rgb *dest);
void	box_cpy(const t_box *src, t_box *dest);
void	vol_cpy(const t_vol *src, t_vol *dest);
void	hit_cpy(const t_hit *src, t_hit *dest);

//		utils/ft_itoa_custom.c
void	ft_itoa_custom(int n, char *str, size_t size);
void	ft_ftoa_custom(float n, char *str, size_t size);

//		utils/format_vec3.c
t_bool	format_float2(char *str, int nb);

#endif
