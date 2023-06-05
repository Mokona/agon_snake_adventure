#include <stdio.h>
#include <mos.h>
#include <vdp.h>

char directions[4];

void main(void)
{
    vdp_init();
    mode(1);

    char previous_key = 0;
    char previous_pressed = 0;
    while (previous_key != 125 || previous_pressed != 1)
    {
        vdp_vsync();
        char key = vdp_get_vkey();
        char pressed = vdp_get_vkey_pressed();

        if (previous_key != key || previous_pressed != pressed)
        {
            clear_screen();
            if (key == 156)
                directions[0] = pressed;
            if (key == 152)
                directions[1] = pressed;
            if (key == 154)
                directions[2] = pressed;
            if (key == 150)
                directions[3] = pressed;

            for (int i = 0; i < 4; ++i)
            {
                putchar('0' + directions[i]);
            }
            putchar('\n');

            previous_key = key;
            previous_pressed = pressed;
        }
    }
}
