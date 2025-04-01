/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:20 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 12:59:11 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	if (root->left)
		ft_btree_apply_prefix(root->left, applyf);
	if (root->right)
		ft_btree_apply_prefix(root->right, applyf);
}
