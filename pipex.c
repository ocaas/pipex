/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 04:50:17 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/30 05:29:54 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//	./pipex infile cmd1 cmd2 outfile
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
char	*find_path(char *cmd, char *envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while(envp[i] && ft_strcmp(envp, "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	i += 5;
	paths = ft_split(envp[i], ":");
	i = 0;
	while(paths[i])
	{
		paths = ft_strjoin()
	}
}

void	exvec(char **av)
{
	char	*cmd;
	char	*path;

	cmd = ft_split(cmd, ' ');
	if(!cmd || !cmd[0])
		return((ft_putstr_fd("Error, no command", 2)), 1);
	
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd1;
	char	*cmd2;

	if(ac == 5)
	{
		cmd1 = av[2];
		cmd2 = av[3];
		
	}
	else
		return (ft_putstr_fd("input error", 2), 1);
}


