/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_construction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:01:38 by amahla            #+#    #+#             */
/*   Updated: 2022/09/13 15:50:34 by amahla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs_utils.h"
#include "utils.h"
#include "minirt.h"
#include "bvh.h"

static void	make_leaf(t_list *vols, t_bvh **root,
				unsigned int begin, unsigned int end)
{
	t_vol	*vol;

	vols = ft_lst_at(vols, begin);
	vol = (t_vol *)(vols->content);
	(*root)->left = btree_create_node(vol->box, vol);
	if (vols->next && end != begin)
	{
		ft_printf("Done %d\n", i++);
		vol = (t_vol *)(vols->next->content);
		(*root)->right = btree_create_node(vol->box, vol);
	}
}

t_bvh	*build_node(t_list **vols, t_bvh **root,
			unsigned int begin, unsigned int end)
{
	t_box			box;
	unsigned int	m;
	t_vol			*vol;

	if (end == begin)
	{
		vol = (t_vol *)(ft_lst_at(*vols, begin)->content);
		*root = btree_create_node(vol->box, vol);
		return (*root);
	}
	ft_printf("Done 1\n");
	bounds_total(*vols, &box, begin, end);
	ft_printf("Done 2\n");
	*root = btree_create_node(box, NULL);
	ft_printf("Done 3\n");
	if (end - begin <= 1)
	{
		make_leaf(*vols, root, begin, end);
		return (*root);
	}
	m = sort_vols(vols, &box, begin, end);
	ft_printf("Done 4\n");
	(*root)->left = build_node(vols, &(*root)->left, begin, m - 1);
	(*root)->right = build_node(vols, &(*root)->right, m, end);
	return (*root);
}
