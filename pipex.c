/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 04:50:17 by olopez-s          #+#    #+#             */
/*   Updated: 2025/09/10 01:31:27 by olopez-s         ###   ########.fr       */
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

void	die(char *s)
{
	ft_putstr_fd("Error", 2);
	perror(s);
	exit(1);
}

//PATH=/bin:/usr/bin needs to become ["/bin", "/usr/bin", NULL].
char	*find_path(const char *cmd, char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))  // put in new function, this function should return
		i++;											//envp[i] + 5. : cause find path isnt working.
	if (!envp[i])
		return (NULL);
	i += 5; // ?
	paths = ft_split(envp[i], ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoinx2(paths[i], "/", cmd);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	run_command(char *cmd, char **envp, int infile, int outfile)
{
	const char	*cmd_path;
	char	**av;

	cmd_path = find_path(cmd, envp);
	av = ft_split(cmd, ' ');

	if (infile > 0)
		dup2(infile, STDIN_FILENO); // to esta vaina tne q ir con el tema de los close forks etc yatusabe manito keloke
	if (outfile > 0)
		dup2(outfile, STDOUT_FILENO);
	if (!cmd_path || !cmd_path[0])
		return(ft_putstr_fd("Error, no command", 2)); // add exit failure 
	execve(cmd_path, av, envp);
	//execve(path, av, envp);
}

void	pipex(char **av, char **envp, int infile, int outfile)
{
	int p1;
	int p2;
	int	fd[2];
	
	if (pipe(fd) == -1)
		return (ft_putstr_fd("Error, pipe", 2));
	p1 = fork();
	if (p1 == 0)
	{
		close(fd[0]);
		run_command(av[1], envp, infile, fd[1]);
	}
	p2 = fork();
	if (p2 == 0)
	{
		close (fd[1]);
		run_command(av[3], envp, fd[0], outfile);
	}
	close(p1);
	close(p2);
}

void	close_everything(int infile, int outfile)
{
	close(infile);
	close(outfile);
}

/* 	need infile and out as variables
	errotr check if pipe doesnt work
	create the child proccess (with fork, must == 0)
		do twice for both
	finish by closing everything   */

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
		close_everything(infile, outfile);
	}
	else
		return (ft_putstr_fd("input error", 2), 1);
}
	/* 	(void)ac;
		char	*hola = find_path(av[1], envp);
		printf("%s", hola); */
