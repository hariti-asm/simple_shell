#include "shell.h"

/**
 * is_executable - determines if a file is an executable command or not
 * @inf: the inf struct
 * @pt: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
bool is_executable(info_s *inf, char *pt)
{
	struct stat st;

	(void)inf;
	if (!pt || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (true);
	}
	return (false);
}

/**
 * dup_chars - duplicates characters
 * @ptstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *ptstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (ptstr[i] != ':')
			buf[k++] = ptstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * check_file_in_pt - finds this cmd in the PATH string
 * @inf: the inf struct
 * @ptstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full pt of cmd if found or NULL
 */
char *check_file_in_pt(info_s *inf, char *pathstr, char *cmd)
{
	int i = 0, pos = 0;
	char *pt;

	if (!ptstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_executable(inf, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!ptstr[i] || pathstr[i] == ':')
		{
			pt = dup_chars(pathstr, pos, i);
			if (!*pt)
				strcat(pt, cmd);
			else
			{
				strcat(pt, "/");
				strcat(pt, cmd);
			}
			if (is_executable(inf, pt))
				return (pt);
			if (!ptstr[i])
				break;
			pos = i;
		}
		i++;
	}
	return (NULL);
}
