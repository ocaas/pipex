/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 19:19:50 by olopez-s          #+#    #+#             */
/*   Updated: 2025/09/12 19:40:17 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(char **av, char **envp, int infile, int *fd)
{
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	run_command(av[2], envp, infile, fd[1]);
}

void	second_child(char **av, char **envp, int outfile, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	run_command(av[3], envp, fd[0], outfile);
}

void	close_everything(int infile, int outfile, int *fd)
{
	close(infile);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	die(char *s)
{
	ft_putstr_fd("Error", 2);
	perror(s);
	exit(1);
}
