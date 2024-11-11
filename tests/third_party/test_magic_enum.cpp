/*
 * Project: server
 * Moudle: magic_enum
 * File: test_magic_enum.cpp
 * Created Date: 2024-11-11 09:24:29
 * Author: zhuzhu
 * Description: test
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#include <format>

#include "log.h"
#include "magic_enum/magic_enum.hpp"
#include "magic_enum/magic_enum_iostream.hpp"
#include <iostream>

enum class Color : int { RED = -10, BLUE = 0, GREEN = 10 };

int main(int argc, char *argv[])
{
    LogInit("aaa");
    Color c1 = Color::RED;
    auto c1_name = magic_enum::enum_name(c1);
    LOGI("c1_name is: {}", c1_name);

    auto c3 = magic_enum::enum_cast<Color>(10);
    if (c3.has_value()) {
        LOGI("GREEN  is: {}", magic_enum::enum_integer(c3.value()));
    }

    using magic_enum::iostream_operators::operator<<; // out-of-the-box ostream operator for all enums.
    auto values = magic_enum::enum_values<Color>();
    for (const auto value : values) {
        // LOGI("c1_value is: {}", value);
        std::cout << " " << (value);
    }
    std::cout << __cpp_lib_format << '\n';

    return 0;
}