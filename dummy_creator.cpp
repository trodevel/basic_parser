/*

Dummy Creator.

Copyright (C) 2020 Sergey Kolevatov

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

// $Revision: 13242 $ $Date:: 2020-06-11 #$ $Author: serge $

#include "dummy_creator.h"

#include <limits>          // std::numeric_limits<T>::max
#include <cstdlib>         // rand()

namespace basic_parser
{

template<class T>
T get_rand()
{
    auto res = static_cast<T>( rand() % std::numeric_limits<T>::max );

    return res;
}

bool create_dummy__bool()
{
    auto res = get_rand<bool>();

    return res;
}

std::uint8_t create_dummy__uint8()
{
    auto res = get_rand<uint8_t>();

    return res;
}

std::uint16_t create_dummy__uint16()
{
    auto res = get_rand<uint16_t>();

    return res;
}

std::uint32_t create_dummy__uint32()
{
    auto res = get_rand<uint32_t>();

    return res;
}

std::uint64_t create_dummy__uint64()
{
    auto res = get_rand<uint64_t>();

    return res;
}

std::int8_t create_dummy__int8()
{
    auto res = get_rand<int8_t>();

    return res;
}

std::int16_t create_dummy__int16()
{
    auto res = get_rand<int16_t>();

    return res;
}

std::int32_t create_dummy__int32()
{
    auto res = get_rand<int32_t>();

    return res;
}

std::int64_t create_dummy__int64()
{
    auto res = get_rand<int64_t>();

    return res;
}

float create_dummy__float()
{
    auto X = 256;

    float res = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/X));

    return res;
}

double create_dummy__double()
{
    auto X = 256;

    double res = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/X));

    return res;
}

// https://stackoverflow.com/a/12468109/4833314
std::string random_string( std::size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

std::string create_dummy__string()
{
    auto length = 1 + rand() % 20;

    auto res = random_string( length );

    return res;
}

} // namespace basic_parser