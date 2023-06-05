#ifndef SNAKE_VDP_H
#define SNAKE_VDP_H

void clear_screen(void);
void mode(int m);
void color(char c);
void plot(char mode, int x, int y);
void move_to(int x, int y);
void line(int x, int y);
void bitmap_select(char n);
void bitmap_col_load(int sx, int sy);
void bitmap_draw(int x, int y);
void sprite_select(char n);
void sprite_clear_frames(void);
void sprite_add_frame(int bitmap_n);
void sprite_activate(int count);
void sprite_frame_select(int n);
void sprite_show(void);
void sprite_move_to(int x, int y);
void sprite_update(void);

extern void vdp_init(void);
extern void vdp_vsync(void);
extern char vdp_get_vkey(void);
extern char vdp_get_vkey_pressed(void);

#endif
