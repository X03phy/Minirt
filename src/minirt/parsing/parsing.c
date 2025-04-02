/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maecarva <maecarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:49:51 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/02 14:14:36 by maecarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minirt.h"


bool	parse_line(t_config *c, char *line)
{
	char	*trimmed;
	char	**splited;
	int		i;
	int		start;

	if (!c || !line)
		return (false);
	trimmed = ft_strtrim(line, WHITESPACES);
	if (!trimmed || ft_strlen(trimmed) == 0)
		return (free(trimmed), false);
	splited = ft_split_charset(trimmed, WHITESPACES",");
	if (!splited || splited[0] == NULL)
		return (ft_dfree(&splited), free(trimmed), false);
	i = 0;
	start = 0;
	while (SCENE_TYPE[start])
	{
		if (ft_strcmp(splited[0], &SCENE_TYPE[start]) == 0)
		{
			(c->funcs[i])(c, splited);
			break ;
		}
		i++;
		start += ft_strlen(&SCENE_TYPE[start]) + 1;
	}
	ft_sfree((void **)&trimmed);
	ft_dfree(&splited);
	return (true);
}

bool	parse_scene(t_config *c, char *filepath)
{
	int		scenefd;
	char	*tmp;

	tmp = NULL;
	scenefd = 0;
	if (!c || !filepath)
		return (false);
	scenefd = open(filepath, O_RDONLY);
	if (scenefd == -1)
		return (false);
	if (get_next_line(scenefd, &tmp) != 0)
		return (close(scenefd), false);
	while (tmp != NULL)
	{
		if (!parse_line(c, tmp))
			return (free(tmp), false);
		ft_sfree((void **)&tmp);
		if (get_next_line(scenefd, &tmp) != 0)
			return (close(scenefd), false);
	}
	return (close(scenefd), false);
}

