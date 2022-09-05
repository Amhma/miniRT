/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:45:43 by fmauguin          #+#    #+#             */
/*   Updated: 2022/09/05 18:19:13 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu.h"
#include "structs_utils.h"
#include "utils.h"
#include "mlx_data.h"
#include "minirt.h"

void	rect_display(t_data *data, t_rect rect, int color)
{
	int	x;

	while (--rect.maxY >= rect.minY)
	{
		x = rect.minX;
		while (x++ < rect.maxX)
		{
			img_pix_put(&data->img, x, rect.maxY, color);
		}
	}
}

t_rect	gen_rect(int minX, int maxX, int minY, int maxY)
{
	t_rect	ret;

	ret.maxX = maxX;
	ret.maxY = maxY;
	ret.minX = minX;
	ret.minY = minY;
	return (ret);
}

void	str_vol(t_scene *scene, t_menu *menu)
{
	if (menu->item == m_cam)
	{
		menu->bprint[0] = '0';
		menu->bprint[1] = '0';
		menu->bprint[2] = '1';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '0';
		menu->bprint[6] = '1';
		menu->bprint[7] = '1';
		menu->bprint[8] = '1';
		menu->bprint[9] = '1';
		menu->bprint[10] = 0;
	}
	else if (menu->item == m_ambient)
	{
		menu->bprint[0] = '0';
		menu->bprint[1] = '1';
		menu->bprint[2] = '0';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '1';
		menu->bprint[6] = 0;
	}
	else if (menu->item == m_light)
	{
		menu->bprint[0] = '1';
		menu->bprint[1] = '0';
		menu->bprint[2] = '1';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '1';
		menu->bprint[6] = '0';
		menu->bprint[7] = '1';
		menu->bprint[8] = '1';
		menu->bprint[9] = '1';
		menu->bprint[11] = 0;
	}
	else if (menu->item == m_plane)
	{
		menu->bprint[0] = '1';
		menu->bprint[1] = '0';
		menu->bprint[2] = '1';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '0';
		menu->bprint[6] = '1';
		menu->bprint[7] = '1';
		menu->bprint[8] = '1';
		menu->bprint[9] = '0';
		menu->bprint[10] = '1';
		menu->bprint[11] = '1';
		menu->bprint[12] = '1';
		menu->bprint[13] = 0;
	}
	else if (menu->item == m_vol &&((t_vol *)ft_lst_at(scene->vols,
		menu->index)->content)->type == SPHERE)
	{
		menu->bprint[0] = '1';
		menu->bprint[1] = '0';
		menu->bprint[2] = '1';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '1';
		menu->bprint[6] = '0';
		menu->bprint[7] = '1';
		menu->bprint[8] = '1';
		menu->bprint[9] = '1';
		menu->bprint[10] = 0;
	}
	else if (menu->item == m_vol)
	{
		menu->bprint[0] = '1';
		menu->bprint[1] = '0';
		menu->bprint[2] = '1';
		menu->bprint[3] = '1';
		menu->bprint[4] = '1';
		menu->bprint[5] = '0';
		menu->bprint[6] = '1';
		menu->bprint[7] = '1';
		menu->bprint[8] = '1';
		menu->bprint[9] = '1';
		menu->bprint[10] = '1';
		menu->bprint[11] = '0';
		menu->bprint[12] = '1';
		menu->bprint[13] = '1';
		menu->bprint[14] = '1';
		menu->bprint[15] = 0;
	}
}

void	display_field(t_data *data, t_menu *menu, size_t size)
{
	size_t	i;
	int		y_start;
	int		x_start;

	i = 0;
	while (i < size)
	{
		if (menu->bprint[i] == '1')
		{
			x_start = RECT_START_X + FOFFSET_X;
			y_start = RECT_START_Y + FOFFSET_Y;
			if (i != 0)
			{
				y_start += STEP_FIELD * i;
				x_start += FOFFSET_X * 3;
			}
			rect_display(data,
				gen_rect(x_start, RECT_END_X - FOFFSET_X,
					y_start, y_start + STEP_FIELD - FOFFSET_Y),
				BGFIELD_PIXEL);
		}
		i++;
	}
}

void	select_field(t_data *data, t_menu *menu, size_t size)
{
	size_t	i;
	int		y_start;
	int		x_start;
	int		f_index;

	i = -1;
	f_index = menu->field_index + 1;
	while (++i < size && f_index)
		if (menu->bprint[i] == '1' && --f_index == 0)
			break ;
	if (i != size)
	{
		x_start = FOFFSET_1_X;
		y_start = RECT_START_Y + FOFFSET_Y;
		if (i != 0)
		{
			y_start += STEP_FIELD * i;
			x_start = FOFFSET_TITLE_X;
		}
		rect_display(data,
			gen_rect(x_start, RECT_END_X - FOFFSET_X,
				y_start, y_start + STEP_FIELD - FOFFSET_Y),
				SELFIELD_PIXEL);
	}
}

void fill_field(t_data *data, int y, void *item, int type)
{
	char str[50];

	if (type == m_int)
	{
		ft_itoa_custom(*((int *)item), &str[0], 50);
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_MID_X, y, WHITE_PIXEL, &str[0]);
	}
	else if (type == m_t_rgb)
	{
		fill_field(data, y, &((t_rgb *)item)->r, m_int);
		fill_field(data, y + STEP_FIELD, &((t_rgb *)item)->g, m_int);
		fill_field(data, y + STEP_FIELD * 2, &((t_rgb *)item)->b, m_int);
	}
}

int	fill_template(t_data *data, int y_start, char *name,  const int type)
{
	if (type == 0)
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_TITLE_X, y_start, WHITE_PIXEL, name);
	else if (type == 1)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_TITLE_X, y_start, WHITE_PIXEL, name);
		y_start += STEP_FIELD;
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_1_X, y_start, WHITE_PIXEL, "x");
		y_start += STEP_FIELD;
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_1_X, y_start, WHITE_PIXEL, "y");
		y_start += STEP_FIELD;
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_1_X, y_start, WHITE_PIXEL, "z");
	}
	else
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr,
			FOFFSET_1_X - (FOFFSET_X / 2), y_start, WHITE_PIXEL, name);
	}
	return (y_start + STEP_FIELD);
}

void	fill_menu(t_menu *menu, t_data *data, t_scene *scene)
{
	int		y_start;

	(void)scene;
	if (menu->item == m_cam)
	{
		y_start = RECT_START_Y + STEP_FIELD - FOFFSET_Y;
		y_start = fill_template(data, y_start, "CAMERA", 0);
		y_start = fill_template(data, y_start, "position", 1);
		y_start = fill_template(data, y_start, "direction", 1);
		y_start = fill_template(data, y_start, "fov", 2);
	}
}


int	display_menu(t_data *data, t_menu *menu, t_scene *scene)
{
	size_t	size;

	menu->is_visible = true;
	str_vol(scene, menu);
	size = ft_strlen(&menu->bprint[0]);
	rect_display(data, gen_rect(RECT_START_X, RECT_END_X, RECT_START_Y,
		RECT_START_Y + FOFFSET_Y + (STEP_FIELD * size + 1)), BG_PIXEL);
	display_field(data, menu, size);
	select_field(data, menu, size);
	return (0);
}