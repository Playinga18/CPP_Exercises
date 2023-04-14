#pragma once

#include "pixels.hpp"

#include "../lib/lib.hpp"

#include <stdint.h>
#include <cstddef>
#include <functional>
#include <string>
#include <array>
#include <iostream>


template<typename P, size_t W, size_t H>
struct Image
{
public:
    Image() = default;
    Image(const P& pix){
        for (size_t j = 0; j < H; ++j){
            for (size_t i = 0; i < W; ++i){
                _data[j][i] = pix;
            }
        }
    }

    const P &
    operator()(const size_t i,
               const size_t j) const
    {
        return _data[j][i];
    }

    P &
    operator()(const size_t i,
               const size_t j)
    {
        return _data[j][i];
    }

    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)> & functor)
    {
        for (size_t j = 0; j < H; ++j){
            for (size_t i = 0; i < W; ++i){
                _data[j][i] = functor(i,j);
            }
        }
    }

private:
    std::array<std::array<P, W>, H> _data;
};

template <typename P, size_t W, size_t H>
Image<P, W, H> operator+(const Image<P, W, H>& i1, const Image<P, W, H>& i2)
{
    Image<P, W, H> out = {};
    for (size_t j = 0; j < H; ++j){
        for (size_t i = 0; i < W; ++i){
            out(i,j) = i1(i,j) + i2(i,j);
        }
    }
    return out;
}

