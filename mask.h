#ifndef BTT_MASK_H
#define BTT_MASK_H

#define skip_win() goto afterwin

#define checkmask(mask)                         \
            if((brd1 & (mask)) == (mask))       \
                break

#define checkmask2(mask1, mask2)    \
            checkmask((mask1));     \
            checkmask((mask2));     \
            skip_win()

#define checkmask3(mask1, mask2, mask3)     \
            checkmask((mask1));             \
            checkmask((mask2));             \
            checkmask((mask3));             \
            skip_win()

#define checkmask4(mask1, mask2, mask3, mask4)      \
            checkmask((mask1));                     \
            checkmask((mask2));                     \
            checkmask((mask3));                     \
            checkmask((mask4));                     \
            skip_win()

#endif /* BTT_MASK_H */
