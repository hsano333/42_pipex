/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano <hsano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:30:58 by hsano             #+#    #+#             */
/*   Updated: 2022/09/15 09:32:24 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_split(char **split)
{
	size_t	j;

	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}