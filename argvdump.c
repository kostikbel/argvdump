#include <sys/types.h>
#include <stddef.h>

int mywrite(int, const char *, size_t);
int myexit(int);

static int
mystrlen(const char *x)
{
	int res;

	for (res = 0; *x != '\0'; x++, res++)
		;
	return (res);
}

static void
putstr(const char *x)
{
	mywrite(1, x, mystrlen(x));
}

static void
putint(int x)
{
	char s[16], *p;

	p = s + sizeof(s) - 1;
	*p = '\0';
	do {
		p--;
		*p = '0' + x % 10;
		x /= 10;
	} while (x != 0);
	putstr(p);
}

static void
newline(void)
{
	putstr("\n");
}

void
start(char **ap)
{
	int i, argc;
	char **argv, **env, **p;

	argc = *(long *)(void *)ap;
	argv = ap + 1;
	env = ap + 2 + argc;

	putstr("argc: ");
	putint(argc);
	newline();
	for (i = 0; i < argc; i++) {
		putstr("argv ");
		putint(i);
		putstr(" : ");
		putstr(argv[i]);
		newline();
	}
	putstr("environ");
	newline();
	for (p = env, i = 0; *p != NULL; p++, i++) {
		putstr("env ");
		putint(i);
		putstr(" : ");
		putstr(*p);
		newline();
	}
	myexit(0);
}
