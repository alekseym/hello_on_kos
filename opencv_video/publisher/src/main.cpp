#include <cstring>
#include <exception>
#include <iostream>
#include <memory>

#include <kos_net.h>

#include "general.h"
#include "publisher.h"

namespace consts {
constexpr int PublicationIntervalInSec = 5;
} // namespace consts

const char* GetBrokerAddress()
{
    const char* brokerAddress = getenv("MQTT_BROKER_ADDRESS");
    if (brokerAddress)
    {
        return brokerAddress;
    }
    throw std::runtime_error{"Failed to get MQTT broker address."};
}

int GetBrokerPort()
{
    if (auto brokerPortEnvVariable = getenv("MQTT_BROKER_PORT"))
    {
        try
        {
            return std::stoi(brokerPortEnvVariable);
        }
        catch (const std::logic_error&)
        {}
    }
    throw std::runtime_error{"Failed to get MQTT broker port."};
}

int main(void) try
{
    if (!wait_for_network())
    {
        throw std::runtime_error{"Error: Wait for network failed!"};
    }

    mosqpp::lib_init();
    auto pub = std::make_unique<Publisher>("publisher", GetBrokerAddress(), GetBrokerPort());
    while (true)
    {
        sleep(consts::PublicationIntervalInSec);
        pub->send_time();
    }

    mosqpp::lib_cleanup();
    return EXIT_SUCCESS;
}
catch (const std::exception& exc)
{
    std::cerr << app::AppTag << exc.what() << std::endl;
    return EXIT_FAILURE;
}
