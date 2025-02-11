#pragma once

#include "board.h"
#include "search.h"

namespace chess
{
    namespace eval
    {
        const int piece_square_tables[6][64] = {
        {
        0,   0,   0,   0,   0,   0,   0,   0,
        250, 250, 250, 250, 250, 250, 250, 250,
        170, 150, 150, 160, 160, 150, 150, 170,
        125, 120, 100, 125, 125, 100, 120, 125,
        100, 110, 120, 150, 150, 120, 110, 100,
        100, 110, 70,  125, 125, 70,  110, 100,
        100, 100, 100, 100, 100, 100, 100, 100,
        0,   0,   0,   0,   0,   0,   0,   0
        },
        {
        200, 200, 200, 200, 200, 200, 200, 200,
        210, 220, 260, 265, 265, 260, 220, 210,
        250, 280, 320, 340, 340, 320, 280, 250,
        265, 290, 320, 335, 335, 320, 290, 265,
        265, 290, 315, 270, 270, 315, 290, 265,
        250, 270, 330, 315, 315, 330, 270, 250,
        210, 250, 280, 300, 300, 280, 250, 210,
        200, 200, 200, 200, 200, 200, 200, 200
        },
        {
        230, 230, 230, 230, 230, 230, 230, 230,
        250, 280, 290, 300, 300, 290, 280, 250,
        270, 300, 320, 310, 310, 320, 300, 270,
        290, 320, 350, 330, 330, 350, 320, 290,
        290, 300, 350, 330, 330, 350, 300, 290,
        270, 300, 320, 310, 310, 320, 300, 270,
        250, 310, 280, 310, 310, 280, 310, 250,
        210, 210, 210, 210, 210, 210, 210, 210
        },
        {
        600, 600, 600, 600, 600, 600, 600, 600,
        580, 580, 580, 580, 580, 580, 580, 580,
        550, 550, 550, 550, 550, 550, 550, 550,
        500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500,
        500, 500, 500, 500, 500, 500, 500, 500,
        450, 450, 500, 510, 510, 500, 450, 450,
        450, 450, 500, 510, 510, 500, 450, 450
        },
        {
        955, 960, 960, 950, 950, 960, 960, 955,
        940, 930, 925, 920, 920, 925, 930, 940,
        920, 900, 900, 900, 900, 900, 900, 920,
        900, 900, 900, 900, 900, 900, 900, 900,
        900, 900, 900, 900, 900, 900, 900, 900,
        880, 900, 870, 900, 900, 870, 900, 880,
        850, 900, 900, 900, 900, 900, 900, 850,
        800, 830, 860, 880, 880, 860, 830, 800
        },
        {
        9999, 9999, 9999, 9999, 9999, 9999, 9999, 9999,
        9000, 9000, 9000, 9000, 9000, 9000, 9000, 9000,
        9260, 9240, 9220, 9200, 9200, 9220, 9240, 9260,
        9460, 9440, 9420, 9400, 9400, 9420, 9440, 9460,
        9700, 9660, 9620, 9600, 9600, 9620, 9660, 9700,
        9790, 9760, 9690, 9700, 9700, 9690, 9760, 9790,
        9950, 9980, 9945, 9920, 9920, 9945, 9980, 9950,
        9999, 9999, 9850, 9935, 9935, 9850, 9999, 9999
        }
        };

        /* Evaluates position using piece square tables */
        int eval_pst(const board::Board &b);

		int get_material_diff(const board::Board &board, int p=1, int n=3, int b=3, int r=5, int q=9, int k=999999999); /* Counts material difference */

        /* Checks for draws */
        bool is_draw(const board::Board &b, const std::unordered_map<u64, u8> &position_history, u64 white_pieces_bb, u64 black_pieces_bb);
    }
}
