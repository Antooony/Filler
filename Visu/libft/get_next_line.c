/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:20:47 by adenis            #+#    #+#             */
/*   Updated: 2017/03/07 09:02:13 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# define ENDL '\n'

int read_from_fd_into_stock(int const fd, char **stock)
{
    static char buff[BUFF_SIZE+1] = { ENDL };
    int         read_bytes;
    char        *nstr;

    read_bytes = read(fd, buff, BUFF_SIZE);
    if (read_bytes > 0)
    {
        buff[read_bytes] = '\0';
        nstr = ft_strjoin(*stock, buff);
        if (!nstr)
            return (-1);
        // free(*stock);
        *stock = nstr;
    }
    return (read_bytes);
}

int get_next_line(int const fd, char ** line)
{
    static char *stock = NULL;
    char        *endl_index;
    int         ret;

    if (!stock && (stock = (char *)ft_memalloc(sizeof(char))) == NULL)
    {
        *line = NULL;
        return (-1);
    }
    endl_index = ft_strchr(stock, ENDL);
    while (endl_index == NULL)
    {
        ret = read_from_fd_into_stock(fd, &stock);
        if (ret == 0 && 
            ((endl_index = ft_strchr(stock, '\0')) == stock))
        {
                *line = NULL;
                return (0);
        }
        else if (ret < 0)
        {
            *line = NULL;
            return (-1);
        }
        else
            endl_index = ft_strchr(stock, ENDL);
    }
    *line = ft_strsub(stock, 0, endl_index - stock);
    if (!*line)
        return (-1);
    endl_index = ft_strdup(endl_index + 1);
    // free(stock);
    stock = endl_index;
    return (1);
}

// static int		ft_return(char **line, char **str, int ret)
// {
// 	if (ret == 0 && !*str[0])
// 	{
// 		*line = ft_strnew(0);
// 		return (0);
// 	}
// 	if (ft_strchr(*str, '\n'))
// 	{
// 		if (ft_strchr(*str, '\n') - *str == 0)
// 			*line = ft_strnew(0);
// 		else
// 			*line = ft_strsub(*str, 0, ft_strchr(*str, '\n') - *str);
// 		*str = ft_strchr(*str, '\n') + 1;
// 	}
// 	else
// 	{
// 		*line = ft_strdup(*str);
// 		*str = ft_strnew(0);
// 	}
// 	return (1);
// }

// static int		get_input(int fd, char **s, char **line)
// {
// 	char	*buff;
// 	int		ret;
// 	char	*str;

// 	ret = BUFF_SIZE;
// 	if (*s)
// 		str = ft_strdup(*s);
// 	else
// 		str = ft_strnew(0);
// 	while ((ret == BUFF_SIZE) && str && !ft_strchr(str, '\n'))
// 	{
// 		if (!(buff = ft_strnew(BUFF_SIZE)))
// 			return (-1);
// 		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
// 			return (-1);
// 		buff[ret] = '\0';
// 		str = ft_strjoinfree(str, buff);
// 	}
// 	*s = ft_strdup(str);
// 	if (str)
// 		ft_strdel(&str);
// 	return (ft_return(line, s, ret));
// }

// static t_list	*ft_check_fd(t_list *lst, int fd)
// {
// 	if (lst->start)
// 		lst = lst->start;
// 	while (lst)
// 	{
// 		if (lst->fd == fd)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// static t_list	*ft_getfd(t_list *lst, int fd)
// {
// 	t_list	*tmp;

// 	if (!lst)
// 	{
// 		if (!(lst = ft_lstnew(NULL, 0)))
// 			return (NULL);
// 		lst->fd = fd;
// 	}
// 	if (!ft_check_fd(lst, fd))
// 	{
// 		if (!(tmp = ft_lstnew(NULL, 0)))
// 			return (NULL);
// 		tmp->fd = fd;
// 		ft_lstadd_end(lst, tmp);
// 	}
// 	return (ft_check_fd(lst, fd));
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static t_list *lst;

// 	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
// 	{
// 		if (line)
// 			*line = ft_strnew(0);
// 		return (-1);
// 	}
// 	if (!(lst = ft_getfd(lst, fd)))
// 	{
// 		*line = ft_strnew(0);
// 		return (-1);
// 	}
// 	return (get_input(fd, (char **)&lst->content, line));
// }
