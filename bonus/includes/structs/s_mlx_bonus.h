/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/14 10:38:04 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MLX_BONUS_H
# define S_MLX_BONUS_H

# include "color_bonus.h"
# include "typedef_bonus.h"

struct s_image
{
	void		*obj;
	char		*data;
	t_color3	*tmp_data;
	int			data_size;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			bytes_per_line;
	int			endian;
};

struct s_mlx
{
	void	*conn;
	void	*win;
	t_image	img;
};

#endif