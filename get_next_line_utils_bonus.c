/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slippert <slippert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:35:49 by slippert          #+#    #+#             */
/*   Updated: 2023/11/09 17:50:45 by slippert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)b;
	while (len--)
		*a++ = c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = (void *)malloc(count * size);
	if (!temp)
		return (NULL);
	return (ft_memset(temp, '\0', count * size));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*temp_s3;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = 0;
	while (s1[s1_length])
		s1_length++;
	s2_length = 0;
	while (s2[s2_length])
		s2_length++;
	s3 = (char *)ft_calloc((s1_length + s2_length) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	temp_s3 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	return (temp_s3);
}

char	*ft_free(char *res_buf, char *temp_buf)
{
	temp_buf = ft_strjoin(res_buf, temp_buf);
	free(res_buf);
	return (temp_buf);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a_c;

	a_c = (unsigned char) c;
	while (*s)
	{
		if (*s == a_c)
			return ((char *)s);
		s++;
	}
	if (a_c == *s)
		return ((char *)s);
	return (NULL);
}
