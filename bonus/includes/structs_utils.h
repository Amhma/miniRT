/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:04:08 by fmauguin          #+#    #+#             */
/*   Updated: 2022/09/16 18:13:01 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_UTILS_H
# define STRUCTS_UTILS_H

# include "libft.h"
# include "mlx.h"

typedef struct s_data	t_data;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_couple
{
	int	x;
	int	y;
}	t_couple;

typedef struct s_couplef
{
	float	x;
	float	y;
}	t_couplef;

typedef struct s_resolut
{
	int		win_width;
	int		win_height;
	float	aspect_ratio;
	float	subdivide;
	int		aliasing;
	t_bool	is_set;
}	t_resolut;

typedef struct s_menu
{
	t_bool	is_visible;
	t_bool	has_changed;
	int		item;
	int		index;
	int		field_index;
	int		max_f_index;
	char	bprint[18];
}			t_menu;

typedef struct s_img_c
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img_c;

typedef enum e_disruption
{
	NONE,
	CHECKERBOARD,
	OTHER,
}	t_disruption;

typedef struct s_xpm
{
	char	*file;
	int		h;
	int		w;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	float	coeff;
}	t_xpm;

typedef struct s_spec
{
	int		size;
	float	intensity;
}	t_spec;

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
	CYLINDER,
	TRIANGLE,
	HYPERBOLOID,
	CONE
}	t_type;

typedef struct s_vol
{
	t_type			type;
	t_pos			pos;
	t_pos			tr[3];
	t_pos			vec3;
	float			d;
	float			h;
	t_rgb			col;
	t_box			rayon;
	t_box			box;
	t_disruption	disruption;
	t_xpm			*tex;
	t_xpm			*bump;
	t_spec			spec;
	t_data			*data;
}	t_vol;

typedef struct s_plane
{
	t_pos			pos;
	t_pos			vec3;
	t_rgb			col;
	t_disruption	disruption;
	t_xpm			*tex;
	t_xpm			*bump;
	t_spec			spec;
	t_data			*data;
}	t_plane;

typedef struct s_cam
{
	t_pos	pos;
	t_pos	vec3;
	int		h_fov;
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
	float		r_o;
	t_pos		pos;
	t_bool		is_set;
}	t_light;

typedef struct s_hit
{
	float	dst_origin;
	t_pos	pos;
	t_pos	normal;
	t_rgb	col;
	t_spec	spec;
	t_type	vol_type;
	void	*vol;
}	t_hit;

typedef struct s_ray
{
	t_pos	origin;
	t_pos	dir;
}	t_ray;

typedef struct s_help_conehit
{
	t_pos	h;
	t_pos	w;
	t_pos	h_norm;
	float	m;
	t_pos	co_top;
	float	abc[3];
	float	t;
	float	d;
}	t_h_conehit;

typedef struct s_help_light
{
	t_rgb	light_specular[2];
	t_light	*lights;
	t_pos	dir_light;
	t_hit	hit_from_camera;
	t_pos	diffuse[2];
}	t_help_light;

typedef struct s_bvh
{
	t_box			box;
	t_vol			*vol;
	struct s_bvh	*left;
	struct s_bvh	*right;
}	t_bvh;

typedef struct s_scene
{
	t_resolut	resolut;
	t_list		*vols;
	t_list		*lights;
	t_light		*ambient;
	t_list		*planes;
	t_list		*cameras;
	t_cam		*cam;
	int			fd;
	char		*line_gnl;
	t_bvh		*bvh;
}	t_scene;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img_c	img;
	t_scene	*scene;
	t_menu	menu;
}			t_data;

#endif
