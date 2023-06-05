#include "keys.h"

#include "vdp.h"

char directions[4];

static char previous_key = 0;
static char previous_pressed = 0;

void update_keys(void)
{
    char key = vdp_get_vkey();
    char pressed = vdp_get_vkey_pressed();

    if (previous_key != key || previous_pressed != pressed)
    {
        if (key == 156)
            directions[0] = pressed;
        if (key == 152)
            directions[1] = pressed;
        if (key == 154)
            directions[2] = pressed;
        if (key == 150)
            directions[3] = pressed;

        previous_key = key;
        previous_pressed = pressed;
    }
}

char escape_pressed(void)
{
    return previous_key == 125 && previous_pressed == 1;
}