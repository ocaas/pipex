/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 05:16:33 by olopez-s          #+#    #+#             */
/*   Updated: 2025/09/12 19:47:57 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include <fcntl.h>

//pipex
char	*find_path(const char *cmd, char **envp);
void	run_command(char *cmd, char **envp, int infile, int outfile);
void	pipex(char **av, char **envp, int infile, int outfile);

//utils
void	first_child(char **av, char **envp, int infile, int *fd);
void	second_child(char **av, char **envp, int outfile, int *fd);
void	close_everything(int infile, int outfile, int *fd);
void	free_array(char **arr);
void	die(char *s);

#endif