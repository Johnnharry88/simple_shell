 #include "shell.h"

/**
 * xdirchange - function that changes workig directory to
 * parent directory *
 * @store: struct holding arguments
 * Return: void
 */
void xdirchange(store_v *store)
{
	char wd[PATH_MAX];
	char *d, *p_pwd, *tok_pwd;
	int x = 0;

	getcwd(wd, sizeof(wd));
	p_pwd = dupstring(wd);
	envset("OLDPWD", p_pwd, store);
	d = store->argstr[x + 1];
	if (xtrcomp(".", d) == x)
	{
		envset("PWD", p_pwd, store);
		free(p_pwd);
		return;
	}
	if (xtrcomp("/", p_pwd) == x)
	{
		free(p_pwd);
		return;
	}
	tok_pwd = p_pwd;
	str_inverse(tok_pwd);
	tok_pwd = tokxtr(tok_pwd, "/");
	if (tok_pwd != NULL)
	{
		tok_pwd = tokxtr(NULL, "\0");

		if (tok_pwd != NULL)
			str_inverse(tok_pwd);
	}
	if (tok_pwd != NULL)
	{
		chdir(tok_pwd);
		envset("PWD", tok_pwd, store);
	}
	else
	{
		chdir("/");
		envset("PWD", "/", store);
	}
	store->status = x;
	free(p_pwd);
}

/**
 * fwd_dirchange - function that changes to a user given
 * directory.
 * @store: struct holding arguments
 * Return: void
 */
void fwd_dirchange(store_v *store)
{
	char wd[PATH_MAX];
	char *d, *p_pwd, *p_d;
	unsigned int x = 1;
	int s = -1;

	getcwd(wd, sizeof(wd));

	d = store->argstr[x];
	if (chdir(d) == s)
	{
		fetcherr(store, 2);
		return;
	}

	p_pwd = dupstring(wd);
	envset("OLDPWD", p_pwd, store);

	p_d = dupstring(d);
	envset("PWD", p_d, store);

	free(p_pwd);
	free(p_d);

	 store->status = s + 1;

	chdir(d);
}

/**
 * f_dirchange - function that working directory
 * to the previous directory.
 * @store: struct holding arguments
 * Return: void.
 */
void f_dirchange(store_v *store)
{
	char wd[PATH_MAX];
	char *ppwd;
	char *o_pwd;
	char *c_pwd;
	char *d_pwd;
	int x = -1;

	getcwd(wd, sizeof(wd));
	c_pwd = dupstring(wd);

	o_pwd = envgetter("OLDPWD", store->venv);

	if (o_pwd == NULL)
		d_pwd = c_pwd;
	else
		d_pwd = dupstring(o_pwd);

	envset("OLDPWD", c_pwd, store);

	if (chdir(d_pwd) == x)
		envset("PWD", c_pwd, store);
	else
		envset("PWD", d_pwd, store);

	ppwd = envgetter("PWD", store->venv);

	write(STDOUT_FILENO, ppwd, xtrlent(ppwd));
	write(STDOUT_FILENO, "\n", 1);

	free(c_pwd);
	if (o_pwd)
		free(d_pwd);

	store->status = (x + 1);

	chdir(ppwd);
}

/**
 * home_dirchange - function that changes working directory
 * to home directory
 * @store: struct holding arguments
 * Return: void.
 */
void home_dirchange(store_v *store)
{
	char *ppd, *alx;
	char wd[PATH_MAX];
	int x = -1;

	getcwd(wd, sizeof(wd));
	ppd = dupstring(wd);

	alx = envgetter("HOME", store->venv);

	if (alx == NULL)
	{
		envset("OLDPWD", ppd, store);
		free(ppd);
		return;
	}

	if (chdir(alx) == x)
	{
		fetcherr(store, 2);
		free(ppd);
		return;
	}

	envset("OLDPWD", ppd, store);
	envset("PWD", alx, store);
	free(ppd);
	store->status = x + 1;
}
