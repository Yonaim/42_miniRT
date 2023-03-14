/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:19:21 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/09 10:14:28 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_BONUS_H
# define CONSTANTS_BONUS_H

# include <limits.h>

enum e_success_or_failure
{
	SUCCESS,
	FAILURE
};

// window
# define WINDOW_NAME				"Go photon corps!"
# define WINDOW_WIDTH				1200
# define WINDOW_HEIGHT				800

// t range
# define T_MINIMUM					0.01
# define T_INFINITY 				INT_MAX

// sampling
# define SAMPLES_PER_PIXEL			1000
# define PUT_IMG_TERM				5

// recursive depth
# define MAX_DEPTH					50

// camera
# define APERTURE					0
# define FOCAL_DISTANCE				10.0

// object
# define POINT_LIGHT_RADIUS			10
# define BRIGHTNESS_CORRECT_VAL		3

// dynamic array
# define INITIAL_OBJECT_ARR_SIZE	10
# define INITIAL_INFO_ARR_SIZE		10

/** dev **/

// object
# define MATERIAL_NUMBER			4
# define OBJECT_NUMBER				5

// camera
# define FIELD_OF_VIEW				30

#endif
