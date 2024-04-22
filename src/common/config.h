/*
 * Project: server
 * Moudle: common
 * File: config.h
 * Created Date: 2024-04-22 13:51:41
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef COMMON_CONFIG_H
#define COMMON_CONFIG_H

#include "singleton.h"
#include <string_view>

namespace myweb::common {

class Config : public utils::Singleton<Config> {
  public:
    bool load(std::string_view);

    int port_ = 0;
};

} // namespace myweb::common

#endif // COMMON_CONFIG_H