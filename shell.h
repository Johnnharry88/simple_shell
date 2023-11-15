#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define STORE_SIZE 1024
#define SIZE_TOK 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct l_list_s - single linked list handling command
 * @fedline: command line
 * @next: next node
 * Description: single linked list to store command
 */
typedef struct l_list_s
{
	char *fedline;
	struct l_list_s *next;
} l_list;

/**
 * struct x_list_s- single linked list holding delim
 * @wall: ; | &
 * @next: next node
 * Description: single linked list to store dividers
 */
typedef struct x_list_s
{
	char wall;
	struct x_list_s *next;
} x_list;

/**
 * struct v_list - single linked list v_list handling env variables
 * @first: length of the variable
 * @alpha: value of the variable
 * @len_: length of the value
 * @next: next node
 * Description: single linked list to store environ variables
 */
typedef struct v_list_s
{
	int first;
	char *alpha;
	int len;
	struct v_list_s *next;
} v_list;

/**
 * struct data - struct that contains all relevant data on runtime
 * @ax: argument vector
 * @str: command line passed
 * @args: tokenized command line
 * @status: status of the shell
 * @rec: lines counter
 * @venv: environment variable
 * @pid: process ID of the shell
 */
typedef struct storev
{
	char **ax;
	char *str;
	char **argstr;
	int status;
	int rec;
	char **venv;
	char *pid;
} store_v;

/**
 * struct builtin_s - Builtin struct for command args.
 * @action:name of inbuilt command
 * @fun: pointer to inbuilt function
 */
typedef struct inbuiltfunhold_s
{
	char *action;
	int (*fun)(store_v *store);
} inbuiltfunhold_t;

x_list *endnodesepadd(x_list **head, char sep);
void x_listfree(x_list **head_x);
l_list *endnodelineadd(l_list **head_l, char *xmine);
void l_listfree(l_list **head);
v_list *endnodevaradd(v_list **head, int, char *, int);
void v_listfree(v_list **head);
void varenvcheck(v_list **h, char *in, store_v *store);
int varsxmine(v_list **h, char *in, char *st, store_v *store);
char *str_varconvert(v_list **head, char *input, char *new_input, int nlen);
char *str_vardisplace(char *i, store_v *store);
char *charaxchange(char *input, int bool);
void nodeadder(x_list **head_x, l_list **head_l, char *xmine);
void nxtcomd(x_list **list_s, l_list **list_l, store_v *store);
int comdsplit(store_v *store, char *);
char **arrangeline(char *input);
int linexef(store_v *store);

char *xtrcat(char *dest, const char *src);
char *xtrcopy(char *dest, char *src);
int xtrcomp(char *s1, char *s2);
char *xtrchr(char *s, char c);
char *dupstring(const char *);
int xtrlent(const char *);
int characomp(char str[], const char *);
char *tokxtr(char str[], const char *);
int digitxmine(const char *);
void str_inverse(char *);
int xtrspn(char *s, char *accept);

void helpaux_env(void);
void helpaux_envset(void);
void helpaux_resetenv(void);
void helpaux_general(void);
void helpaux_exit(void);
void helpaux(void);
void helpaux_alias(void);
void helpaux_dir(void);
int aidgethelp(store_v *store);

void copy_memo(void *newptr, const void *ptr, unsigned int size);
void *dym_memoloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **dym_memoreloc(char **ptr, unsigned int old_size, unsigned int new_size);
void free_store(store_v *store);
void datareset(store_v *store, char **av);

int chkchararep(char *input, int i);
int searcherr(char *input, int i, char last);
int idxcharasrch(char *input, int *i);
void syn_errprinter(store_v *store, char *input, int i, int bool);
int auxsyn_errprinter(store_v *store, char *input);

char *delcomment(char *in);
void hshloop(store_v *store);

char *rdlinef(int *);
int srchdir(char *path, int *i);
char *findcomd(char *cmd, char **venv);
int chkexef(store_v *store);
int user_chkpermit(char *dir, store_v *store);
int comdexe(store_v *store);

char *envgetter(const char *name, char **venv);
int envprint(store_v *store);
int envnamecomp(const char *env_name, const char *tag);
char *copy_info(char *name, char *value);
void envset(char *name, char *value, store_v *store);
int envsetter(store_v *store);
int resetenv(store_v *store);

void xdirchange(store_v *store);
void fwd_dirchange(store_v *store);
void f_dirchange(store_v *store);
void home_dirchange(store_v *store);
int shelldirxchange(store_v *store);

int (*func_passer(char *cmd))(store_v *store);
void _signinteg(int sig);
int shellxit(store_v *store);

int numb_len(int n);
char *int_strconvert(int num);
int str_intconvert(char *istr);

char *cderrxcat(store_v *, char *, char *, char *);
char *cdirerr(store_v *store);
char *neg_error(store_v *store);
char *shellxiterror(store_v *store);
char *environerr(store_v *store);
char *patherror_126(store_v *store);
int fetcherr(store_v *store, int errval);

#endif
