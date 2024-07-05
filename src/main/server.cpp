#include "log.h"
#include "webserver.h"

int main(int argc, char *argv[])
{
    LogInit("aaa");
    auto &server = myweb::webserver::WebServer::instance();
    server.init();

    LOGD("{}", 1);
    LOGE("{}", 1);
    LOGT("{}", 1);
    LOGI("{}", 1);
    LOGW("{}", 1);
    server.start();
    server.run();

    return 0;
}