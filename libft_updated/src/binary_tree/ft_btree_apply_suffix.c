/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:43:50 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 12:59:14 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	if (root->left)
		ft_btree_apply_suffix(root->left, applyf);
	if (root->right)
		ft_btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
