#include "../../git-compat-util.h"

int win32_has_drive_prefix(char *path) {
	if(win32_has_dos_drive_prefix(path)) {
		return 2;
	} else if(((path[0] == '\\' && path[1] == '\\') || (path[0] == '/' && path[1] == '/')) && path[2] == '?' && is_dir_sep(path[3])) {
		if(win32_has_dos_drive_prefix(path + 4)) {
			return 6;
		} else if(!_strnicmp(path + 4, "Volume{", 7)) {
			char* pos = strpbrk(path + 11, "\\/");
			if(pos) {
				return (pos - path) + 1;
			}
		}
	}
	return 0;
}

int win32_skip_drive_prefix(char **path)
{
	int ret = win32_has_drive_prefix(*path);
	*path += ret;
	return ret;
}

int win32_offset_1st_component(const char *path)
{
	char *pos = (char *)path;

	/* unc paths */
	if (!skip_dos_drive_prefix(&pos) &&
			is_dir_sep(pos[0]) && is_dir_sep(pos[1])) {
		/* skip server name */
		pos = strpbrk(pos + 2, "\\/");
		if (!pos)
			return 0; /* Error: malformed unc path */

		do {
			pos++;
		} while (*pos && !is_dir_sep(*pos));
	}

	return pos + is_dir_sep(*pos) - path;
}
