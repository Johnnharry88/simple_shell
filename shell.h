#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

/**
 * struct built_ins - A structure for the built in commands
 * @cmd: The command
 * @f: The command
 */
typedef struct inbuilt_s
{
        char *comd;
        int (*action)(char *args);
} inbuilt_t;

extern char **environ;

char *xtrcopy(char *dest, char *src);
int str_intconvert(char *s);
ssize_t read_comm(char **comm_cache, size_t *comm_bytes);
int exe_com(char *comm_cache);
int exe_chd(char *av[]);
int exe_p(pid_t pid);
void mem_free(char *comm_cache);
char *find_exec(char *com_cache);
int comargs_p(char *com_cache, char **args);
ssize_t _getline(char **_ptr, size_t *num);
int xtrlent(char *s);
char *xtrchr(const char *s, int ch);
char *tokxtr(char *s, const char *del);
int checks_inbuilt(char *args[], char *com_cache);
void shellxit(char *com_cache, int status);
int xtrcomp(const char *s1, const char *s2);
int init_buff(char **_ptr, size_t *_num);
ssize_t rdline(char **_ptr, size_t *_num);
char *exec_check(char *com_cache);
int dirxchange(char *args);
int print_pwd(char *args);
int env_print(char *args);
char *envgetter(char *name, char **environ);
char *abs_pathgetter(char *cmd, char **environ);
int token_rec (char *str);
int (*func_fetch(char *comd))(char *args);
char *xtrcat(char *str1, char *str2);
char **tokexe(char *str, int rex, char **args);
int _putchar(char c);

#define PROMPT_SIZE 2
#define MAX_ARGS 64
#define BUFF_SIZE 128

#endif
