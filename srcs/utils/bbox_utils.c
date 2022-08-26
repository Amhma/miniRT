/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:23:53 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/26 13:52:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_utils.h"
#include "utils.h"

void	bbox_center(const t_box *box, t_pos *center)
{
	set_vector(box->max.x - box->min.x, box->max.y - box->min.y,
		box->max.z - box->min.z, center);
}

float	bbox_expend(const t_box *box)
{
	return (dist_ab(&box->min, &box->min));
}