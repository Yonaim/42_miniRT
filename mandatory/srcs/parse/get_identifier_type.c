
#include "parse_internal.h"
#include <string.h>

static int	get_idx_matching_string(const char **strs, const char *seek)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strcmp(seek, strs[i]) == 0) // TODO
			return (i);
		i++;
	}
	return (-1);
}

int	get_element_type(const char *str)
{
	const char	*identifier[] = {
	[ELEMENT_CAMERA] = IDETIFIER_ELEMENT_CAMERA,
	[ELEMENT_AMBIENT] = IDETIFIER_ELEMENT_AMBIENT,
	[ELEMENT_LIGHT] = IDETIFIER_ELEMENT_LIGHT,
	[ELEMENT_SPHERE] = IDETIFIER_ELEMENT_SPHERE,
	[ELEMENT_PLANE] = IDETIFIER_ELEMENT_PLANE,
	[ELEMENT_CYLINDER] = IDETIFIER_ELEMENT_CYLINDER,
	[ELEMENT_CONE] = IDETIFIER_ELEMENT_CONE,
	[ELEMENT_BOX] = IDETIFIER_ELEMENT_BOX,
		NULL
	};

	return (get_idx_matching_string(identifier, str));
}

int	get_material_type(const char *str)
{
	const char	*identifier[] = {
	[MATERIAL_LAMBERTIAL] = IDETIFIER_MATERIAL_LAMBERTIAL,
	[MATERIAL_METAL] = IDETIFIER_MATERIAL_METAL,
	[MATERIAL_DIELECTRIC] = IDETIFIER_MATERIAL_DIELECTRIC,
	[MATERIAL_EMMISIVE] = IDETIFIER_MATERIAL_EMMISIVE,
	[MATERIAL_RANDOM] = IDETIFIER_MATERIAL_RANDOM,
		NULL
	};
	
	return (get_idx_matching_string(identifier, str));
}

int	get_texture_type(const char *str)
{
	const char	*identifier[] = {
	[TEXTURE_SOLID] = IDETIFIER_TEXTURE_SOLID,
	[TEXTURE_CHECKER] = IDETIFIER_TEXTURE_CHECKER,
	[TEXTURE_IMAGE] = IDETIFIER_TEXTURE_IMAGE,
		NULL
	};

	return (get_idx_matching_string(identifier, str));
}