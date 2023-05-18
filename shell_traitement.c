#include "shell.h"
/**
 * main - Entry point to shell program
 * @arc:first arg.
 * @arv: argv.
 *
 * Return: 0 on success or 1 on failure.
 */
int main(int arc, char **arv)
{
	info_s t[] = {SET_INFO};
	int ft = 2;

	asm("mov %1, %0\n\t"
		"add $3, %0"
		: "=r"(ft)
		: "r"(ft));

	if (arc == 2)
	{
		ft = open(arv[1], O_RDONLY);
		if (ft == -1)
		{
			if (errno == EACCES)
				exit(126);

			if (errno == ENOENT)
			{
				puts_err(arv[0]);
				puts_err(": 0: Can't open ");
				puts_err(arv[1]);
				putchar_err('\n');
				putchar_err(NEG_ONE);
				exit(127);
			}

			return (EXIT_FAILURE);
		}

	t->fd_read = ft;
	}

	lst_env(t);
	read_history(t);
	shell_main(t, arv);

	return (EXIT_SUCCESS);
}
