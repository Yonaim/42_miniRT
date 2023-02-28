#ifndef HANDLE_ERROR_H
# define HANDLE_ERROR_H

# define ERRMSG_ARG_CNT 		"Usage: <scene_description_file_path>"
# define ERRMSG_PARSE			"Failed to parse"
# define ERRMSG_MALLOC_FAILED	"Malloc failed"

int	handle_error(char *err_msg);

#endif