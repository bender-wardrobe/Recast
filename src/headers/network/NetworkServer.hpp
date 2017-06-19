/**
 * @file server.cpp
 * @brief Networking server header file
 * @author StealthTech
 * @project Recast-server
 * @date 19.06.17
 * @email st3althtech@mail.ru
 *
 **/

#ifndef RECAST_NETWORKINGSERVER_H
#define RECAST_NETWORKINGSERVER_H

#include "network/Networking.hpp"

using namespace std;

class NetworkServer {
public:
    NetworkServer(uint32_t PortTCP, uint32_t PortUDP);
    void run();
    void shutdown();
private:
    uint32_t portTCP;
    uint32_t portUDP;
    bool isRunning;

    void clientWork(shared_ptr<Socket> client);
    string exchange(const string action);
    string check(const string action);
};

#endif //RECAST_NETWORKINGSERVER_H
