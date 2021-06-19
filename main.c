#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "masks.h"
#include "mask.h"
#include "cell.h"

/*
 *       |
 *       |       7         9 [b]
 * cell  | 0000000 000000000 (16)
 *       |         |cell
 *       |         board
 *       |
 * brd1  | 0000000 000000000 (16)
 * brd2  | 0000000 000000000 (16)
 *       |         board
 *       |
 * char1 |          00000000 (8)
 * char2 |          00000000 (8)
 *       |          char
 *       |
 */

uint16_t brd1;
uint16_t brd2;
uint16_t cell;
uint8_t char1;
uint8_t char2;

int main (void)
{
    brd1 = 0;
    brd2 = 0;
    char1 = 'X';
    char2 = 'O';

    get_cell();

    for(;;)
    {
        // !(1 >= cell <= 9)
        while((uint16_t)(cell-'1') > 8)
        {
            printf("Error: Invalid cell '%c'\n", cell);
            cell = getchar();
            if(cell == '\n')
                get_cell();
        }

        cell = MASK_CELL_1 >> (cell-'1');
        if(cell & brd2)
        {
            printf("Error: Cell %c is occupied\n", cell);
            goto next;
        }
        brd1 |= cell;

        switch(cell)
        {
        case MASK_CELL_1: checkmask3(MASK_DIAG_159, MASK_HORZ_123, MASK_VERT_147);
        case MASK_CELL_2: checkmask2(MASK_HORZ_123, MASK_VERT_258);
        case MASK_CELL_3: checkmask3(MASK_DIAG_357, MASK_HORZ_123, MASK_VERT_369);
        case MASK_CELL_4: checkmask2(MASK_HORZ_456, MASK_VERT_147);
        case MASK_CELL_5: checkmask4(MASK_DIAG_159, MASK_DIAG_357, MASK_HORZ_456, MASK_VERT_258);
        case MASK_CELL_6: checkmask2(MASK_HORZ_456, MASK_VERT_369);
        case MASK_CELL_7: checkmask3(MASK_DIAG_357, MASK_HORZ_789, MASK_VERT_147);
        case MASK_CELL_8: checkmask2(MASK_HORZ_789, MASK_VERT_258);
        case MASK_CELL_9: checkmask3(MASK_DIAG_159, MASK_HORZ_789, MASK_VERT_369);
        }

        print_board();
        printf("\n~ %c wins!\n", char1);
        break;

    afterwin:
        print_board();

        if(brd1 + brd2 == MASK_BOARD_FULL)
        {
            printf("\n~ It's a tie!\n");
            break;
        }

        char2 = char1;
        char1 ^= 0x17;

        cell = brd1;
        brd1 = brd2;
        brd2 = cell;

    next:
        printf("============================== %c's turn!\n", char1);

        cell = getchar();
        if(cell == '\n')
        {
            get_cell();
        }
    }

    return EXIT_SUCCESS;
}
