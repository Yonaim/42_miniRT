/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim  <yeonhkim@student.42seoul.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:49 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/03/01 00:16:49 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_ERROR_BONUS_H
# define HANDLE_ERROR_BONUS_H

# define ERRMSG_ARG_CNT 		"Usage: <scene_description_file_path>"
# define ERRMSG_PARSE			"Failed to parse"
# define ERRMSG_MALLOC_FAILED	"Malloc failed"

int	handle_error(char *err_msg);

#endif