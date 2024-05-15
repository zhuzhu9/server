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
#include "log.h"
#include <unistd.h>

namespace myweb::common {

bool Config::load(std::string_view path)
{
    // TODO: config is not parse
    if (access(path.data(), F_OK)) {
        LOGE("path is no exist");
        // return false;
    }
    port_ = 8888;
    return true;
}

} // namespace myweb::common
