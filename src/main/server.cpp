#include "log.h"
#include "webserver.h"

int main(int argc, char *argv[])
{
    LogInit("aaa");
    auto &server = myweb::webserver::WebServer::instance();
    server.init();

    LOGD("%d", 1);
    server.start();
    server.run();

    return 0;
}