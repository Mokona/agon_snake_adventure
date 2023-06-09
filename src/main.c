#include <stdio.h>
#include <mos.h>

#include "vdp.h"
#include "keys.h"
#include "board.h"

void main(void)
{
    vdp_init();
    initialize_board(10, 10);

#if 0
    mode(1);

    static int count = 60;
    while (!escape_pressed())
    {
        vdp_vsync();
        update_keys();

        count--;
        if (count == 0)
        {
            count = 60;
            for (int i = 0; i < 4; ++i)
            {
                    putchar('0' + directions[i]);
            }
            putchar('\r');
            putchar('\n');
        }
    }
#endif
}
