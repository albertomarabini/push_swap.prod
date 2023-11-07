/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarabin <amarabin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:20:21 by amarabin          #+#    #+#             */
/*   Updated: 2023/11/05 10:19:58 by amarabin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/**
 * Deallocates or allocates memory (or both) for a file buffer.
 *
 * @fd: File descriptor.
 * @allocate: 1 to allocate, 0 to deallocate.
 * @old_buffer: Pointer to the old t_file_info structure.
 * @new_buffer: Pointer to the new t_file_info structure.
 *
 * Return: New buffer pointer or NULL if failed or deallocated.
 */

char	*allocate_buffer(int fd, int allocate, t_file_info **old_buffer,
		t_file_info **new_buffer)
{
	if (old_buffer && *old_buffer)
	{
		if ((*old_buffer)->content)
			free((*old_buffer)->content);
		free(*old_buffer);
		*old_buffer = NULL;
	}
	if (allocate)
	{
		*new_buffer = (t_file_info *)malloc(sizeof(t_file_info));
		if (!*new_buffer)
			return (NULL);
		(*new_buffer)->fd = fd;
		(*new_buffer)->content = NULL;
		(*new_buffer)->eof = 0;
		return ("");
	}
	return (NULL);
}

static char	*extract_line(t_file_info *buffer)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (buffer->content[i] && buffer->content[i] != '\n')
		i++;
	if (buffer->content[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	ft_memcpy(line, buffer->content, i);
	tmp = ft_strdup(buffer->content + i);
	if (tmp == NULL)
	{
		free(line);
		return (NULL);
	}
	free(buffer->content);
	buffer->content = tmp;
	return (line);
}

/**
 * man read
 *
 * On success, 1 is returned (zero indicates
 * end of file), and the file position is advanced by this number.
 * It is not an error if this number is smaller than the number of
 * bytes requested; this may happen for example because fewer bytes
 * are actually available right now (maybe because we were close to
 * end-of-file, or because we are reading from a pipe, or from a
 * terminal), or because read() was interrupted by a signal. See
 * also NOTES.
 *
 * On error, -1 is returned, and errno is set to indicate the error.
 * In this case, it is left unspecified whether the file position
 * (if any) changes.
 */

static int	read_fd(int fd, t_file_info *buffer)
{
	int		n_bytes;
	char	tmp[BUFFER_SIZE + 1];
	char	*tmp2;

	while (!ft_strchr(buffer->content, '\n') && !buffer->eof)
	{
		n_bytes = read(fd, tmp, BUFFER_SIZE);
		if (n_bytes == -1)
			return (0);
		buffer->eof = n_bytes != BUFFER_SIZE;
		tmp[n_bytes] = '\0';
		tmp2 = ft_strjoin(buffer->content, tmp);
		if (tmp2 == NULL)
			return (0);
		if (buffer->content != NULL)
			free(buffer->content);
		buffer->content = tmp2;
	}
	return (1);
}

/**
 * Reads one line at a time from a file descriptor.
 *
 * @param fd File descriptor to read from.
 * @return A string containing the line read, or NULL if there's nothing to read
 *         or an error occurs.
 *
 * Successive calls to this function will allow reading the entire text
 * available on the file descriptor, one line at a time, up to the end
 * of the file. The function handles reading from both file descriptors
 * and standard input. The buffer size is defined at compile time using
 * the BUFFER_SIZE param. We assume the stream will stay open until the
 * the function is being used.
 * Steps:
 * 	1: Initial Validation
 *  2: No buffer initialized yet, initialize one
 * 	3: Different FD than the last one, clean the buffer
 *  4: Reached EOF and end of available content, clean up
 * 	5: If is not EOF yet go read the file.
 * 		Read of the actual file won't happen if a /n is found in the
 * 		buffer content.
 * 		If an error happens deallocate and return NULL
 * 	6: Extract the line from the buffer content.
 * 		If an error happens or the content is empty after the last read
 * 		clean up and return NULL
 */
char	*get_next_line(int fd)
{
	static t_file_info	*buffer;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	if (!buffer)
	{
		if (allocate_buffer(fd, 1, NULL, &buffer) == NULL)
			return (NULL);
	}
	if (buffer && buffer->fd != fd)
	{
		if (allocate_buffer(fd, 1, &buffer, &buffer) == NULL)
			return (NULL);
	}
	if (!buffer->eof && !read_fd(fd, buffer))
		return (allocate_buffer(fd, 0, &buffer, NULL));
	if (buffer->eof && *buffer->content == '\0')
		return (allocate_buffer(fd, 0, &buffer, NULL));
	line = extract_line(buffer);
	if (line == NULL)
		return (allocate_buffer(fd, 0, &buffer, NULL));
	return (line);
}
