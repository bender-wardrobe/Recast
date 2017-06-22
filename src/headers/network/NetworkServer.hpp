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
    NetworkServer(uint32_t port, bool isTCP = false);
    void run();
    void shutdown();
private:
    uint32_t port;
    bool isTCP;
    bool isRunning;

    void listenFor(shared_ptr<SocketTCP> client);
    void listenFor(shared_ptr<SocketUDP> client);
    string exchange(const string action);
    string check(const string action);
};

#endif //RECAST_NETWORKINGSERVER_H
