#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <limits.h>

enum e_success_or_failure
{
	SUCCESS,
	FAILURE
};

// window
# define WINDOW_NAME				"meyun & yona's wonderful miniRT"
# define WINDOW_WIDTH				1920
# define WINDOW_HEIGHT				1080

// t range
# define T_MINIMUM					0.001
# define T_INFINITY 				INT_MAX

// sampling
# define SAMPLES_PER_PIXEL			100
# define PUT_IMG_TERM				5

// recursive depth
# define MAX_DEPTH					50

// camera
# define APERTURE					0
# define FOCAL_DISTANCE				10.0
# define UP_VECTOR					(t_vector3){0, 1, 0}

// object
# define POINT_LIGHT_RADIUS			5

// dynamic array
# define INITIAL_OBJECT_ARR_SIZE	10
# define INITIAL_INFO_ARR_SIZE		10

// light
# define MAX_BRIGHTNESS				20

/** dev **/

// object
# define MATERIAL_NUMBER			4
# define OBJECT_NUMBER				5

// camera
# define FIELD_OF_VIEW				30
# define LOOK_FROM					(t_point3){13, 2, 3}
# define LOOK_AT					(t_point3){0, 0, 0}

#endif
