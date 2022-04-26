#ifndef SO_LONG_H
# define SO_LONG_H
#include <fcntl.h>
#include "list.h"

# define SIDE_SQUARE 49

typedef struct s_map
{
	int height;
	int width;
	t_list *lines;
	void *wall;
	void *coin;
	void *character;
	void *exit;
} t_map;

typedef struct s_context
{
	void *mlx;
	void *win;
	t_map map;
} t_context;

enum e_keys {
    UP_KEY = 13,
    DOWN_KEY = 1,
    LEFT_KEY = 0,
    RIGHT_KEY = 2,
};


int check_map(t_list *lines);
t_list	*parse(char *filename);
void put_img(t_context ctx, int x, int y, void *img);
void draw(t_context *ctx);
int key_event(int key, t_context *ctx);

int main();

#endif
