/*
** mlx_key_hook.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Feb 23 17:10:09 2001 Charlie Root
*/


#include	"mlx_int.h"


    //mlx_key_hook(data.win_ptr, handle_input, &data);


int		mlx_key_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[KeyRelease].hook = funct;
  win->hooks[KeyRelease].param = param; // key release == 3
  win->hooks[KeyRelease].mask = KeyReleaseMask;
}
 