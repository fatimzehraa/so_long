#ifndef SO_LONG_H
# define SO_LONG_H
#include <fcntl.h>
#include "list.h"

# define SIDE_SQUARE 51

typedef struct s_map
{
	int height;
	int width;
	t_list *lines;
} t_map;

typedef struct s_context
{
	void *mlx;
	void *win;
	t_map map;
//	void *img;
} t_context;




int check_map(t_list *lines);
t_list	*parse(char *filename);
void put_img(t_context ctx, int x, int y, char *relative_path);

int main();

#endif
