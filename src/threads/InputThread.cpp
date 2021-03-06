/**
 * @file InputThread.cpp
 * @brief Input thread for execution of terminal command
 * @author LionZXY
 * @project Recast-server
 * @date 12.06.17
 * @email nikita@kulikof.ru
 *
 * Execute background command
 * 
 **/

#include <string>
#include <iostream>
#include <boost/log/trivial.hpp>
#include "threads/InputThread.hpp"
#include "Server.hpp"

using namespace std;

InputThread::InputThread(Server *srv) {
    server = srv;
    BOOST_LOG_TRIVIAL(info) << "Input thread is running...";
}

void InputThread::init() {
    while (server->isRunning()) {
        string cmd = "";
        getline(cin, cmd);
        manager.onCommand(server, cmd);
    }
}
