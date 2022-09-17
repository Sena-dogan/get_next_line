/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:04:15 by zdogan            #+#    #+#             */
/*   Updated: 2022/09/17 18:33:40 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read return value = rdrv
int	ft_error(int rdrv, char *buff, char *str)
{
	if (rdrv == -1)
	{
		free (buff);
		free (str);
		return (1);
	}
	return (0);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rdrv;
	char	*tmp;

	if (!str)
		str = ft_strdup("");
	buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buff)
		return (NULL);
	rdrv = 1;
	while (!ft_strchr(str, '\n') && rdrv != 0)
	{
		rdrv = read(fd, buff, BUFFER_SIZE);
		if (rdrv == 0)
			break ;
		if (ft_error(rdrv, buff, str))
			return (NULL);
		buff[rdrv] = '\0';
		tmp = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	free(buff);
	return (str);
}

char	*ft_new_line(char *str)
{
	char	*ptr;
	int		len;

	if (!str || !*str)
		return (NULL);
	ptr = ft_strchr(str, '\n');
	if (!ptr)
		return (ft_strdup(str));
	ptr++;
	if (!*ptr)
		return (ft_strdup(str));
	len = ft_strlen(str) - ft_strlen(ptr);
	return (ft_substr(str, 0, len));
}

char	*ft_static_str(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
	{
		free(str);
		return (NULL);
	}
	ptr++;
	if (!(*ptr))
	{
		free(str);
		return (NULL);
	}
	ptr = ft_strdup(ptr);
	free (str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_new_line(str[fd]);
	str[fd] = ft_static_str(str[fd]);
	return (line);
}

// int	main(int ac, char **av)
// {
// 	int	fd;
// 	int	i = 1;

// 	if (ac >= 2)
// 	{
// 		while (av[i++])
// 		{
// 			fd = open(av[i], O_RDWR);
// 			char	*x = get_next_line(fd);
// 			while(x)
// 			{
// 				printf("%s", x);
// 				free(x);
// 				x = get_next_line(fd);
// 			}
// 		}
// 	}
// 	system("leaks a.out");
// }