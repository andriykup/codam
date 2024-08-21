/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_hell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconvent <aconvent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:20:19 by ankupins          #+#    #+#             */
/*   Updated: 2024/08/05 16:03:48 by aconvent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_HELL_H
# define MINI_HELL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <stdbool.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include "macros.h"
//#include <limits.h>

//###color def###
//reset
# define RST  "\033[0m"
//red
# define RED  "\033[31m"
//green
# define GRN  "\033[32m"
//yellow
# define YEL  "\033[33m"
//blue
# define BLU  "\033[34m"
//magenta
# define MAG  "\033[35m"
//cyan
# define CYN  "\033[36m"
//withe
# define WHT  "\033[37m"

//###Typographic def### 
// bold
# define BLD  "\033[1m"
//fainted
# define FNT  "\033[2m"
//italic
# define ITA  "\033[3m"
//underlined
# define UNL  "\033[4m"

extern sig_atomic_t	g_signal_status;

typedef struct s_redirection
{
	char					*file_name;
	char					*delimiter;
	char					*redir;
	struct s_redirection	*next;

}	t_redir;

typedef struct s_command
{
	char				**args;
	t_redir				*redir;
	bool				redirected;
	struct s_command	*next;
}	t_command;

typedef struct s_mini_shell
{
	int			ret_value;
	int			pipes; // number of the pipes
	int			*pipefd;
	char		**parsed_input;
	char		**local_environ;
	char		*env_value;
	bool		quotes;
	bool		in_quotes;
	char		*my_paths;
	char		**splitted_paths;
	t_command	*commands;
}	t_mini_shell;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}	t_env;

//mini_hell + mini_Hell_utils
void		my_executions(t_mini_shell **mini_shell, t_env **my_env);
char		*get_env_path(t_env *my_env);
int			builtin_com(t_mini_shell **mini_shell,
				t_env **my_env, char **cmd_args);
int			builtin_com_pipe(t_mini_shell **mini_shell,
				t_env **my_env, char **cmd_args);
void		file_open_check(t_redir *redir, int *file_fd);
void		ft_start_child(t_mini_shell **mini_shell, int i,
				t_command *command_current, t_env **my_env);
void		ft_end_child(t_mini_shell **mini_shell,
				t_command *command_current, t_env **my_env);
void		ft_exec_dup2(t_redir *redir, t_mini_shell **mini_shell,
				t_env **my_env);
void		ft_exec_dup2_1(t_redir *redir, int *file_fd);
void		ft_exec_dup2_2(t_redir *redir, int *file_fd);
char		*find_cmd_path(char **paths_envp, char *cmd);
int			my_execution_p2(t_mini_shell **mini_shell,
				t_command *command_current);
void		my_execution_init(t_mini_shell **mini_shell, t_env **my_env);
int			ft_check_input_0(t_mini_shell **mini_shell, char *input);
int			ft_input_check(char	*input);
void		ft_no_input(t_mini_shell **mini_shell, t_env **my_env, char *input);

// signals
void		handle_sigint(int sig);
void		handle_sigint_heredoc(int sig);
void		ft_signal_check(t_mini_shell **mini_shell);

//error.c
void		ft_fd_check(int fd);
void		error_export(char *str);
void		ft_exit_error(int x, t_mini_shell **mini_shell, int length);

//environ
void		*ft_local_environ(t_mini_shell **mini_shell, t_env *my_env);

//parsing
int			command_list(t_mini_shell **mini_shell, t_env **env);
t_command	*init_command(void);
int			get_command(char *input, t_command **cmd,
				t_env **env, t_mini_shell *mini_shell);
void		add_command_to_end(t_command **head, t_command *new_node);
void		skip_spaces(char *str, int *i);
bool		token_delimiter(char c);
bool		is_quotes(char c);
void		replace_dollar_sign(char *str, t_env **env,
				t_mini_shell *mini_shell);
void		skip_quotes(char *str, int *i);
char		*get_env_value(const char *key, t_env *env);
int			parse_quotes_args(t_mini_shell **mini_shell);
void		quotes_out(char *dst, char *src);
char		*dquotes_work(char *str, t_env **env, t_mini_shell *mini_shell);
bool		ft_isspace(char c);
int			get_redir(char *str, int *i, t_redir **red);
t_redir		*redir_init(void);
char		*tokenizing(char *input, int *i);
int			calculate_total_length(char *str, t_env *env,
				t_mini_shell **mini_hell);
void		ft_strncpy(char *dest, char *src, int n);
void		add_redir_to_end(t_redir **head, t_redir *new_node);
char		*command_quotes(char *str);
char		**ft_split_pipes(char *input);
int			ft_check_inputs(char *input);
void		mini_init(t_mini_shell **mini_shell, t_env **my_env);
int			ft_isalnum(int c);
void		ft_str_increased(char *str, int *i, t_mini_shell **ms, int *j);

//commands folder
int			com_exit(t_mini_shell **mini_shell, t_env **my_env);
int			com_env(char**command, t_env **head, t_mini_shell **mini_shell);
void		free_my_env(t_env **head);
int			com_pwd(t_mini_shell **mini_shell);
int			com_echo(char **command, t_mini_shell **mini_shell);
int			com_unset(t_env **head, char *env, t_mini_shell **mini_shell);
void		empty_cd(t_env *head, t_mini_shell **mini_shell);
void		*com_cd(char *path, t_env *head, t_mini_shell **mini_shell);
char		*st_strjoin(const char *s1, const char *s2);
t_env		*find_last_node(t_env *head);
void		free_struct(t_mini_shell **mini_shell);
void		free_command_struct(t_mini_shell **mini_shell);
void		*update_old_pwd(t_env *head);
void		*update_pwd(t_env *head);
t_env		*ft_new_node(char	**splited_env_var);
//export.c -     t_env *my_env related fuctions
int			set_my_env(t_env **head);
void		com_export(t_env **head, char **new_env_var,
				t_mini_shell **mini_shell);
t_env		*find_env_var(t_env **head, char *env);
int			add_env_node(t_env **head, char *env);

//utils folder
char		*ft_strdup(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
char		*ft_substr(char const *s, int start, int len);
int			ft_length(char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_free_2arr(char **arr);
char		**ft_split(char *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_itoa(int n);
char		*ft_spaceout(char *input);
void		heredoc_tempfile(const char *delimiter,
				char *temp_file, t_mini_shell **mini_shell, t_env **my_env);
void		free_redirections(t_command **cmd);
void		ft_execve_fail(char *args, char *path);
void		ft_exec_close(t_mini_shell **mini_shell);
void		create_pipes(int *pipefd, t_mini_shell mini_shell);
void		ft_pipefd_malloc(t_mini_shell **mini_shell);
int			ft_isdigit(int c);
int			ft_num_check(char *str);
void		*ft_error(char *cmd, char *err_msg);
void		heredoc_tempfile(const char *delimiter, char *temp_file,
				t_mini_shell **mini_shell, t_env **my_env);
void		heredoc_tempfile1(int fd, char	*line, char	*temp);
#endif