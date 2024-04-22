/*
 * Project: server
 * Moudle: common/config
 * File: config.cpp
 * Created Date: 2024-04-22 14:18:14
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */

#include "config.h"

namespace myweb::common {

bool Config::load(std::string_view path)
{
    port_ = 8888;
    return true;
}

} // namespace myweb::common
