#include <unistd.h>

int
main(void)
{
	char *const bogus_argv[] = {NULL, NULL, NULL, NULL};
	char *const bogus_envp[] = {"PS1=$", NULL};

	execve("./argvdump", bogus_argv, bogus_envp);
}
