#ifndef BTT_FIELD_H
#define BTT_FIELD_H

#include <stdint.h>

#define print_cellset(mask1, mask2, mask3, suff)           \
            print_cell(" ",   (mask1));                    \
            print_cell(" | ", (mask2));                    \
            print_cell(" | ", (mask3));                    \
            printf((suff))

void get_cell (void);
void print_board (void);
void print_cell (char *pref, uint16_t mask);

#endif /* BTT_FIELD_H */
