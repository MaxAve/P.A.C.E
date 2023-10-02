#include <stdio.h>
#include <stdlib.h>
#include <types.h>
#include <board.h>
#include <moves.h>

int main(int argc, char** argv)
{
    //! This is a demo of some of the newly added features
    Board b = STANDARD_BOARD;
    PUT_PIECE(b, 3, 20);
    u64 attack_bb = get_attack_bitboard(b, 11, PW, BLACK_PIECE_BB(b), WHITE_PIECE_BB(b));
    print_board(b, attack_bb);

    return 0;
}
