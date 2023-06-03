#include <stdio.h>
#include <mos.h>
#include <vdp.h>

void main(void)
{
    vdp_init();
    mode(1);

    move_to(0, 0);
    line(640 * 2, 512 * 2);

    bitmap_select(0);
    bitmap_col_load(32, 32);

    for (int y = 0; y < 32; y++)
    {
        for (int x = 0; x < 32; x++)
        {
            if (x == 0 || x == 31 || y == 0 || y == 31)
            {
                putchar(0xFF);
                putchar(0xFF);
                putchar(0xFF);
                putchar(0xFF);
            }
            else
            {
                putchar(0x80);
                putchar(0);
                putchar(0);
                putchar(0xFF);
            }
        }
    }

    bitmap_select(0);
    bitmap_draw(100, 100);

    sprite_select(0);
    sprite_clear_frames();
    sprite_add_frame(0);
    sprite_frame_select(0);
    sprite_show();
    sprite_activate(3);

    for (int x = 0; x < 300; x+=2)
    {
        sprite_select(0);
        sprite_move_to(x, 100);
        sprite_update();

        vdp_vsync();
    }
}
