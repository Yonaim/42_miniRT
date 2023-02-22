#ifndef OBJECT_H
# define OBJECT_H

t_object	*create_sphere(t_point3 pos, double radius, t_color rgb);
t_object	*create_cylinder(t_point3 pos, t_vector3 orient, \
								double radius, double height, t_color rgb);
								// 파라미터 수 4개 이하로 줄여야 함
t_object	*create_plane(t_point3 pos, t_vector3 normal, t_color rgb);
t_object	*create_light(t_point3 pos, double ratio, t_color rgb);


#endif