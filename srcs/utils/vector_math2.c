/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:17:16 by fmauguin          #+#    #+#             */
/*   Updated: 2022/08/25 19:52:05 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_utils.h"
#include <math.h>

double	dist_ab(const t_pos *a, const t_pos *b)
{
	return (fabs((b->x - a->x) + (b->y - a->y) + (b->z - a->z)));
}