/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:17:52 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/05 20:41:50 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_internal.h"

t_token	*nth_token(const t_token_arr *tokens, int nth);

// - material 및 texture가 없는 경우
// 	ex) sp | (0, 0, 20) 20 | (255, 0, 0)
// - material 및 texture가 있는 경우
// 	ex) sp | (0, 0, 20) 20 | lam sol (255, 0, 0)

void	print_v3(t_vector3 v)
{
	printf("x: %lf, y: %lf, z: %lf\n", v.x, v.y, v.z);
}

void	print_n(double n)
{
	printf("%lf\n", n);
}

int	parse_line(char *line, t_info *info);

// int main()
// {
// 	t_token 			*token;
// 	char				*line;
// 	t_info_object_sphere *info;

// 	// char	*line = "A | 0.2 (255, 255,";
// 	// char	*line = "A | 0.2 (255, 255, 255)";
// 	// t_token_arr *tokens = tokenize(line);
// 	// printf("%d\n", is_ambient_line(tokens));

// 	// line = "sp | (1, 2, 3) 5 | (250, 251, 252)";
// 	line = "sp | (0, 0, 20) 20 | lam sD (250, 251, 252) ";
	
// 	// t_token_arr *tokens = tokenize(line);
// 	// printf("%d\n", is_sphere_line(tokens));
// 	// sp = (t_info_object_sphere *)get_info_sphere(tokens);
// 	// print_v3(sp->center);
// 	// print_n(sp->radius);
// 	// print_n(sp->material.type);
// 	// print_n(sp->material.texture.type);
// 	// print_v3(sp->material.texture.rgb1);
	
// 	// parse_line(line, (t_info *)info);
	
// 	// token = nth_token(tokens, 0);
// 	// int i = 0;
// 	// while (i < tokens->cnt)
// 	// {
// 	// 	printf("%s\n", token->str);
// 	// 	i++;
// 	// 	token = nth_token(tokens, i);
// 	// }
// 	// printf("%d\n", is_ambient_line(tokens));
// }