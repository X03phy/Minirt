/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:05:23 by ebonutto          #+#    #+#             */
/*   Updated: 2025/03/28 12:53:50 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdlib.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *));
t_btree	*ft_btree_create_node(void *item);
void	ft_btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *));
void	*ft_btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *));

#endif
