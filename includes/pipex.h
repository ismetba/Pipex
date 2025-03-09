/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:53:22 by ibayandu          #+#    #+#             */
/*   Updated: 2025/03/09 16:33:52 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define TRUE 1
# define FALSE 0

# include "ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

// Common_Utils
void	error(void);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);

// Bonus_Utils
int		get_next_line(char **line);
int		open_file(char *argv, int i);

#endif
