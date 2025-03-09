/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:03:35 by ibayandu          #+#    #+#             */
/*   Updated: 2025/03/09 16:18:55 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	process(char **argv, char **envv, int *fd, int is_parent)
{
	int	file;

	if (is_parent)
		file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		file = open(argv[1], O_RDONLY, 0777);
	if (file == -1)
		error();
	dup2(fd[!is_parent], !is_parent);
	dup2(file, is_parent);
	close(fd[is_parent]);
	execute(argv[is_parent + 2], envv);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			process(argv, envp, fd, FALSE);
		waitpid(pid1, NULL, 0);
		process(argv, envp, fd, TRUE);
	}
	else
		ft_putendl_fd("Error: invalid arguments", 2);
	return (0);
}
