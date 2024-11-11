/*
 * Project: server
 * Moudle: magic_enum
 * File: test_magic_enum.cpp
 * Created Date: 2024-11-11 09:24:29
 * Author: zhuzhu
 * Description: magic_enum/example/example.cpp
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#include <format>

#include "log.h"
#include "magic_enum/magic_enum.hpp"
#include "magic_enum/magic_enum_format.hpp"
#include <iostream>

enum class Color : int { RED = -10, BLUE = 0, GREEN = 10 };

template <typename E>
auto to_integer(magic_enum::Enum<E> value)
{
    return static_cast<magic_enum::underlying_type_t<E>>(value);
}

int main(int argc, char *argv[])
{
    LogInit("aaa");
    myweb::zlog::LOGDEFAULT->set_level(spdlog::level::debug);

    // Enum variable to string name.
    Color c1 = Color::RED;
    auto c1_name = magic_enum::enum_name(c1);
    LOGD("c1_name is: {}", c1_name); // RED

    // String enum name sequence.
    constexpr auto names = magic_enum::enum_names<Color>();
    for (const auto &n : names) {
        LOGD("{}", n);
    }
    // Color names: RED BLUE GREEN

    // String name to enum value.
    auto c2 = magic_enum::enum_cast<Color>("aaaa");
    if (c2.has_value()) {
        LOGD("BLUE = {}", to_integer(c2.value())); // BLUE = 0
    }

    // Case insensitive enum_cast.
    c2 = magic_enum::enum_cast<Color>("blue", magic_enum::case_insensitive);
    if (c2.has_value()) {
        LOGD("BLUE = {}", to_integer(c2.value())); // BLUE = 0
    }

    // Integer value to enum value.
    auto c3 = magic_enum::enum_cast<Color>(10);
    if (c3.has_value()) {
        LOGD("GREEN = {}", magic_enum::enum_integer(c3.value())); // GREEN = 10
    }

    // Enum value to integer value.
    auto c4_integer = magic_enum::enum_integer(Color::RED);
    LOGD("RED = {}", c4_integer); // RED = -10

    // Ostream operator for enum.
    LOGD("Color: {} {} {} ", c1, c2, c3);

    // Number of enum values.
    LOGD("Color enum size: {}", magic_enum::enum_count<Color>()); // Color size: 3

    // Indexed access to enum value.
    LOGD("Color[0] = {}", magic_enum::enum_value<Color>(0)); // Color[0] = RED

    // Enum value sequence.
    constexpr auto values = magic_enum::enum_values<Color>();
    for (const auto c : values) {
        LOGD("{}", c);
    }
    // Color values: RED BLUE GREEN

    enum class Flags { A = 1, B = 2, C = 4, D = 8 };
    using namespace magic_enum::bitwise_operators; // out-of-the-box bitwise operators for all enums.
    // Support operators: ~, |, &, ^, |=, &=, ^=.
    Flags flag = Flags::A | Flags::C;
    LOGD("flag is: {}", flag); // 5

    enum color { red, green, blue };

    // Checks whether type is an Unscoped enumeration.
    static_assert(magic_enum::is_unscoped_enum_v<color>);
    static_assert(!magic_enum::is_unscoped_enum_v<Color>);
    static_assert(!magic_enum::is_unscoped_enum_v<Flags>);

    // Checks whether type is an Scoped enumeration.
    static_assert(!magic_enum::is_scoped_enum_v<color>);
    static_assert(magic_enum::is_scoped_enum_v<Color>);
    static_assert(magic_enum::is_scoped_enum_v<Flags>);

    // Enum pair (value enum, string enum name) sequence.
    constexpr auto entries = magic_enum::enum_entries<Color>();
    for (const auto &e : entries) {
        LOGD("{} = {}", e.second, static_cast<int>(e.first));
    }
    // Color entries: RED = -10 BLUE = 0 GREEN = 10

    return 0;
}