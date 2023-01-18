/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <fatilly@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 08:22:38 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 11:49:10 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*suppr_before(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	s = ft_strdup(str + i + 1);
	free(str);
	return (s);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			ret;
	char		buf[BUFFER_SIZE + 1];

	ret = BUFFER_SIZE;
	if (BUFFER_SIZE < 1 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while (!(ft_strchr(str, '\n')) && ret > 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
	}
	if (!(*line = ft_strdup_backline(str)))
		return (-1);
	if (ret < BUFFER_SIZE && !(ft_strchr(str, '\n')))
	{
		free(str);
		str = NULL;
		return (0);
	}
	str = suppr_before(str);
	return (1);
}
