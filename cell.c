#include <stdio.h>
#include "masks.h"
#include "cell.h"

extern uint16_t brd1;
extern uint16_t brd2;
extern uint8_t char1;
extern uint8_t char2;
extern uint16_t cell;

void get_cell (void)
{
    printf("===========Cell: ");
    cell = getchar();
}

void print_cell (char *pref, uint16_t mask)
{
    printf(pref);
    if(brd1 & mask)
        printf("%c", char1);
    else if(brd2 & mask)
        printf("%c", char2);
    else
        printf(" ");
}

void print_board (void)
{
    print_cellset(MASK_CELL_1, MASK_CELL_2, MASK_CELL_3, "\n-----------\n");
    print_cellset(MASK_CELL_4, MASK_CELL_5, MASK_CELL_6, "\n-----------\n");
    print_cellset(MASK_CELL_7, MASK_CELL_8, MASK_CELL_9, "\n");
}
