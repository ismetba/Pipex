/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:02:35 by ibayandu          #+#    #+#             */
/*   Updated: 2025/03/09 16:30:10 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	get_next_line(char **line)
{
	char	*line_buffer;
	int		index;
	int		bytes_read;
	char	character;

	index = 0;
	bytes_read = 0;
	line_buffer = (char *)malloc(10000);
	if (!line_buffer)
		return (-1);
	bytes_read = read(0, &character, 1);
	while (bytes_read && character != '\n' && character != '\0')
	{
		if (character != '\n' && character != '\0')
			line_buffer[index] = character;
		index++;
		bytes_read = read(0, &character, 1);
	}
	line_buffer[index] = '\n';
	line_buffer[++index] = '\0';
	*line = line_buffer;
	free(line_buffer);
	return (bytes_read);
}

/* Function to open the files with the right flags */
int	open_file(char *argv, int i)
{
	int	file;

	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}
