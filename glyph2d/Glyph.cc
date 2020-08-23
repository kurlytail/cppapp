
#include "Glyph.h"

Glyph test = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    3,
    3,
};

static const GlyphMap glyphs = {
    {
        'z',
        {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            3,
            3,
        },
    },
    {
        'a',
        {
            {0, 0, 0, 1, 1, 1, 0, 1, 0},
            3,
            3,
        },
    },
    {
        'b',
        {
            {0, 1, 0, 1, 1, 0, 0, 1, 0},
            3,
            3,
        },
    },
};

void GlyphInit(GlyphMap &glyphMap) { ; }