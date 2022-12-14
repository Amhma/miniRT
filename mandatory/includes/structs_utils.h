/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:04:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/09/08 16:24:02 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_UTILS_H
# define STRUCTS_UTILS_H

# include "libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
}	t_pos;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;

}	t_rgb;

typedef struct s_box
{
	t_pos	min;
	t_pos	max;
	t_pos	center;
	float	expend;
}	t_box;

typedef enum e_type
{
	AMB_LIGHT,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_vol
{
	t_type	type;
	t_pos	pos;
	t_pos	vec3;
	float	d;
	float	h;
	t_rgb	col;
	t_box	rayon;
	t_box	box;
}	t_vol;

typedef struct s_plane
{
	t_pos	pos;
	t_pos	vec3;
	t_rgb	col;
}	t_plane;

typedef struct s_cam
{
	t_pos	pos;
	t_pos	vec3;
	int		h_fov;
	t_bool	is_set;
	t_pos	lookat;
	t_pos	horizontal;
	t_pos	vertical;
	t_pos	lower_left_corner;
	float	focal_length;
	float	viewport_height;
	float	viewport_width;
	t_pos	uvw[3];

}	t_cam;

typedef struct s_light
{
	t_type		type;
	t_rgb		col;
	float		r;
	t_pos		pos;
	t_bool		is_set;
}	t_light;

typedef struct s_hit
{
	float	dst_origin;
	t_pos	pos;
	t_pos	normal;
	t_rgb	col;
}	t_hit;

typedef struct s_ray
{
	t_pos	origin;
	t_pos	dir;
}	t_ray;

typedef struct s_bvh
{
	t_box			box;
	t_vol			*vol;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

typedef struct s_scene
{
	t_list	*vols;
	t_list	*lights;
	t_light	*ambient;
	t_list	*planes;
	t_cam	cam;
	int		fd;
	char	*line_gnl;
	t_bvh	*bvh;
}	t_scene;

#endif
