#include "board.h"

#include <stdlib.h>
#include <assert.h>

#include <stdio.h>


static u8 *board_data = 0;

void initialize_board(u8 width, u8 height)
{
    printf("Board %x\r\n",board_data);

    assert(board_data == 0);
    board_data = malloc(width * height);

    printf("Board %x\r\n",board_data);
}
