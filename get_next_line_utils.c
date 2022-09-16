/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:35:42 by zdogan            #+#    #+#             */
/*   Updated: 2022/09/16 23:26:55 by zdogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	
	i = 0;
	if (!s)
		return (NULL);
	if(start > ft_strlen(s))
		start = ft_strlen(s);
	if(len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s[start])
		return str;
	while(len--)
	{
		str[i] = s[start];
		i++;
		start++;
	}
    str[i] = '\0';
	return str;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*str;
	size_t 	i;

	i = 0;
	size = ft_strlen((char *)s);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL && s == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	x;
	size_t	dlen;
	char	*dest;

	if(!s1 || !s2)
		return (NULL);
	dlen = (ft_strlen(s1) + ft_strlen(s2));
	dest = (char *) malloc(dlen + 1);
	if (!dest)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i])
		dest[x++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[x++] = s2[i++];
	dest[dlen] = '\0';
	return (dest);
}