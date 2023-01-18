/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 08:23:19 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 11:49:24 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup_backline(char *s)
{
	char	*str1;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(str1 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
	{
		str1[i] = s[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char		*ft_strdup(char *s)
{
	char	*str1;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str1 = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str1[i] = s[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

int			ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}

static char	*ft_malloc_word(char *s1, char *s2)
{
	char	*str;

	if (!(str = (char *)malloc((ft_strlen(s1) +
		ft_strlen(s2)) * sizeof(char) + 1)))
		return (NULL);
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_malloc_word(s1, s2);
	if (s1)
	{
		while (s1[i])
		{
			str[j++] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}
