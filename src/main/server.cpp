#include "log.h"
#include "webserver.h"

int main(int argc, char *argv[])
{
    auto &server = myweb::webserver::Webserver::instance();
    server.init();

    LOGD("%d", 1);
    server.start();
    server.run();

    LOGD("%d", 1);

    return 0;
}