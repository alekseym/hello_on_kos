#include <ctime>
#include <iostream>

#include "general.h"
#include "publisher.h"

Publisher::Publisher(const char *id, const char *host, int port)
    : mosquittopp(id)
{
    std::cout << app::AppTag << "Connecting to MQTT Broker with address "
              << host << " and port " << port << std::endl;

    const int keepAlive = 60;
    connect(host, port, keepAlive);
}

void Publisher::on_publish(int)
{
    std::cout << app::AppTag << "Publication succeeded." << std::endl;
}

void Publisher::send_time()
{
    const std::time_t now = std::time(nullptr);
    const std::string message =
        "The time is : " + std::string(std::asctime(std::localtime(&now)));
    std::cout << app::AppTag << message;
    publish(nullptr, "datetime", static_cast<int>(message.size()),
            message.c_str());
}