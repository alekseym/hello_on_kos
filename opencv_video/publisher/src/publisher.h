/* © 2021 AO Kaspersky Lab */
#ifndef _MOSQUITTO_PUBLISHER_H
#define _MOSQUITTO_PUBLISHER_H

#include <mosquittopp.h>

class Publisher : public mosqpp::mosquittopp
{
public:
    Publisher(const char *id, const char *host, int port);
    ~Publisher() {};

    void on_publish(int mid) override;
    void send_time();
};

#endif // _MOSQUITTO_PUBLISHER_H
