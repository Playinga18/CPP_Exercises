#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r,g,b,a;
};
struct RGB
{
    uint8_t r,g,b;
};
struct Luma
{
    uint8_t gray;
};

template<typename A, typename B>
A from(const B & x);

template<> RGBA from(const RGBA & x){ return x; }
template<> RGB  from(const RGB  & x){ return x; }
template<> Luma from(const Luma & x){ return x; }


template<> RGBA from(const RGB & x){return {x.r,x.g,x.b,255};}

template<> RGB from(const RGBA & x){return {x.r,x.g,x.b};}

template<>
RGB from(const Luma & x)
{
    const auto [r,g,b] = lib::grayscale_to_rgb(x.gray);
    return {r,g,b};
}

template<>
Luma from(const RGB & x)
{
    return {lib::rgb_to_grayscale(x.r,x.g,x.b)};
}

template<>
RGBA from(const Luma & x)
{
    return from<RGBA, RGB>(from<RGB, Luma>(x));
}
template<>
Luma from(const RGBA & x)
{
    return from<Luma, RGB>(from<RGB, RGBA>(x));
}
