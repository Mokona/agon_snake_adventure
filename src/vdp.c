#include <stdio.h>

void clear_screen(void)
{
    putchar(12);
}

void mode(int m)
{
    putchar(22);
    putchar(m);
}

void color(char c)
{
    putchar(17);
    putchar(c);
}

void plot(char mode, int x, int y)
{
    putchar(25);
    putchar(mode);
    putchar(x & 0xFF);
    putchar((x >> 8) & 0xFF);
    putchar(y & 0xFF);
    putchar((y >> 8) & 0xFF);
}

void move_to(int x, int y)
{
    plot(4, x, y);
}

void line(int x, int y)
{
    plot(5, x, y);
}

void bitmap_select(char n)
{
    putchar(23);
    putchar(27);
    putchar(0);
    putchar(n);
}

void bitmap_col_load(int sx, int sy)
{
    putchar(23);
    putchar(27);
    putchar(1);
    putchar(sx & 0xFF);
    putchar((sx >> 8) & 0xFF);
    putchar(sy & 0xFF);
    putchar((sy >> 8) & 0xFF);
}

void bitmap_draw(int x, int y)
{
    putchar(23);
    putchar(27);
    putchar(3);
    putchar(x & 0xFF);
    putchar((x >> 8) & 0xFF);
    putchar(y & 0xFF);
    putchar((y >> 8) & 0xFF);
}

void sprite_select(char n)
{
    putchar(23);
    putchar(27);
    putchar(4);
    putchar(n);
}

void sprite_clear_frames(void)
{
    putchar(23);
    putchar(27);
    putchar(5);
}

void sprite_add_frame(int bitmap_n)
{
    putchar(23);
    putchar(27);
    putchar(6);
    putchar(bitmap_n);
}

void sprite_activate(int count)
{
    putchar(23);
    putchar(27);
    putchar(7);
    putchar(count);
}

void sprite_frame_select(int n)
{
    putchar(23);
    putchar(27);
    putchar(10);
    putchar(n);
}

void sprite_show(void)
{
    putchar(23);
    putchar(27);
    putchar(11);
}

void sprite_move_to(int x, int y)
{
    putchar(23);
    putchar(27);
    putchar(13);
    putchar(x & 0xFF);
    putchar((x >> 8) & 0xFF);
    putchar(y & 0xFF);
    putchar((y >> 8) & 0xFF);
}

void sprite_update(void)
{
    putchar(23);
    putchar(27);
    putchar(15);
}

extern void vdp_init(void);
extern void vdp_vsync(void);
