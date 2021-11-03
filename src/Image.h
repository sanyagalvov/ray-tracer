//
// Created by Aleksandr Lvov on 2021-11-01.
//

#pragma once

#include <vector>
#include <string_view>
#include "Vec3.h"

class Pixel {
    using u_char = unsigned char;
    u_char red, green , blue, alpha;

    Pixel(u_char r, u_char g, u_char b, u_char a = 0)
    : red(r), green(g), blue(b), alpha(a) {}

public:
    static Pixel fromVec3(const Vec3& v) {
        return {
            static_cast<u_char>(clamp(v.x(), 0, 1) * 255),
            static_cast<u_char>(clamp(v.y(), 0, 1) * 255),
            static_cast<u_char>(clamp(v.z(), 0, 1) * 255)
        };
    }

    static Pixel fromRGB(u_char r, u_char g, u_char b) {
        return {r, g, b};
    }
};

class Image {
    size_t width_, height_;
    std::vector<Pixel> data_;

public:
    Image(size_t w, size_t h);
    size_t width()  const { return width_;  }
    size_t height() const { return height_; }

public:
    Pixel& at(size_t x, size_t y);
    void writeToFile(std::string_view filename);
};
