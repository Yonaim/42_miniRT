#include "minirt.h"

void	init_ray_tracing(t_ray_tracing *rt, char *path)
{
	// init하는 함수들 호출
}

void	do_rendering(t_ray_tracing *rt)
{
	// 렌더링
	
}

void	flush_ray_tracing(t_ray_tracing *rt)
{
	// 종료 전 할당한 메모리 정리
}

int	main(int argc, char *argv)
{
	t_ray_tracing	rt;

	if (argc != 2)
		return (handle_error(ERRMSG_ARG_CNT));
	init_ray_tracing(&rt, argv[1]);
	do_rendering(&rt);
	flush_ray_tracing(&rt);
}
