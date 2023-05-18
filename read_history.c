#include "shell.h"

/**
 * read-history -> Reads history file into a linked list
 *
 * @info: Pointer
 *
 * Return: Depend Condition
 */

int read-history(info_t *info)
{
	int i, last = 0, countline = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_ht(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, countline++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, countline++);
	free(buf);
	info->histcount = countline;
	while (info->histcount-- >= HIST_MAX)
		delete_node(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
