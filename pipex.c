/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 04:50:17 by olopez-s          #+#    #+#             */
/*   Updated: 2025/09/12 19:55:53 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//						./pipex infile cmd1 cmd2 outfile
//validate arguments
//open files
//builds the pipe
//forks the children
//redirect fds w dup2
//runs commands w execve
//the parent waitpids both 
//PATH=/bin:/usr/bin needs to become ["/bin", "/usr/bin", NULL].
// ...existing code...

char	*find_path(const char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoinx2(paths[i], "/", cmd);
		if (access(path, X_OK) == 0)
		{
			free_array(paths);
			return (path);
		}
		free(path);
		i++;
	}
	return (free_array(paths), NULL);
}

void	run_command(char *cmd, char **envp, int infile, int outfile)
{
	const char	*cmd_path;
	char		**av;

	av = ft_split(cmd, ' ');
	cmd_path = find_path(av[0], envp);
	if (infile > 0)
		dup2(infile, STDIN_FILENO);
	if (outfile > 0)
		dup2(outfile, STDOUT_FILENO);
	if (!cmd_path || !cmd_path[0])
	{
		ft_putstr_fd("Command not found", 2);
		free_array(av);
		exit(1);
	}
	execve(cmd_path, av, envp);
	free_array(av);
	free((void *)cmd_path);
}

void	pipex(char **av, char **envp, int infile, int outfile)
{
	int	p1;
	int	p2;
	int	fd[2];

	if (pipe(fd) == -1)
		die("pipe");
	p1 = fork();
	if (p1 < 0)
		die("fork");
	if (p1 == 0)
		first_child(av, envp, infile, fd);
	p2 = fork();
	if (p2 < 0)
		die("fork");
	if (p2 == 0)
		second_child(av, envp, outfile, fd);
	close_everything(infile, outfile, fd);
	waitpid(p1, NULL, 0);
	waitpid(p2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;

	if (ac == 5)
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (infile < 0 || outfile < 0)
			return (ft_putstr_fd("Error with files", 2), 1);
		pipex(av, envp, infile, outfile);
	}
	else
		return (ft_putstr_fd("input error", 2), 1);
}

	// ...existing code...
	/* 	need infile and out as variables
		errotr check if pipe doesnt work
		create the child proccess (with fork, must == 0)
			do twice for both
		finish by closing everything   */
