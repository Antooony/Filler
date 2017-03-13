#include <ncurses.h>
#include "libft/libft.h"

int			main(void)
{	
	char 	*p1;
	char 	*p2;
	char	*line;
	int 	p = 0;

	int fd = open("test", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'l')
		{
			if (!p)
			{
			   	p1 = ft_strdup(ft_strrchr(line, '/') + 1);
				p++;				
			}
			else
				p2 = ft_strdup(ft_strrchr(line, '/') + 1);
		}
		if (line[0] == 'P')
			break ;
		free(line);
	}
	char *cut = ft_strchr(line, ' ') + 1;
	int gx = ft_atoi(ft_strsub(cut, ft_strchr(cut, ' ') - cut, ft_strchr(cut, ':') - cut - 1));
	int gy = ft_atoi(ft_strsub(cut, 0, ft_strchr(cut, ' ') - cut));
    initscr();
    printw("%s VS %s", p1, p2);
    printw("Plateau %d x %d", gy, gx);
   	int y = 1;
   	int x = 0;
    while (y < gy)
    {
    	x = 0;
    	while (x < gx)
    	{
    		move(y, x);
    		printw(".");
    		x++;
    	}
    	y++;
    }
    refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    getch();                // On attend que l'utilisateur appui sur une touche pour quitter
    endwin();               // Restaure les paramètres par défaut du terminal
    
    return 0;
}
