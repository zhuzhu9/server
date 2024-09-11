/*
 * Project: server
 * Moudle:  * File: os.h
 * Created Date: 2024-09-10 14:55:03
 * Author: zhuzhu
 * Description: description
 * -----
 * todo: modified
 * -----
 * Copyright (c) 2024  Inc
 */
#ifndef OS_H
#define OS_H

#include <thread>

namespace myweb::os::system {

inline void SetThreadPriority(int policy, int priority)
{
    int cur_policy = 0;
    sched_param param{};
    pthread_getschedparam(pthread_self(), &cur_policy, &param);
    if (policy == cur_policy && priority == param.sched_priority) {
        return;
    }
    param.sched_priority = priority;
    int max = sched_get_priority_max(policy);
    int min = sched_get_priority_min(policy);
    if (priority > max || priority < min) {
        std::string policy_str{"UNKONWN"};
        if (policy == SCHED_RR) {
            policy_str = "SCHED_RR";
        }
        if (policy == SCHED_FIFO) {
            policy_str = "SCHED_FIFO";
        }
        return;
    }
    pthread_setschedparam(pthread_self(), policy, &param);
}

inline void SetThreadName(const char *name)
{
    pthread_setname_np(pthread_self(), name);
}

} // namespace myweb::os::system

#endif // OS_H