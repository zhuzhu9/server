/*
 * Project: server
 * Moudle:
 * File: utils.h
 * Created Date: 2024-05-07 16:36:41
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef UTILS_H
#define UTILS_H

#include <fcntl.h>
namespace myweb::utils {

inline int setnonblocking(int fd)
{
    int old_opt = fcntl(fd, F_GETFL);
    int new_opt = old_opt | O_NONBLOCK;

    fcntl(fd, F_SETFL, new_opt);

    return old_opt;
}

} // namespace myweb::utils

#endif // UTILS_H