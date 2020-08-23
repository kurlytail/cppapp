
#pragma once

#include <unordered_map>
#include <vector>
#include <wx/bitmap.h>

struct Glyph {
    wxBitmap bitmap;

    Glyph(const char bits[], const int width, const int height)
        : bitmap(bits, width, height)
    {
        ;
    }

    Glyph(std::vector<char> bits, const int width, const int height)
        : bitmap(bits.data(), width, height)
    {
        ;
    }
};

using GlyphMap = std::unordered_map<char, Glyph>;

void GlyphInit(GlyphMap &glyphMap);