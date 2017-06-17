/**
 * @file SQLite.h
 * @brief Class-helper for DB vars
 * @author LionZXY
 * @project Recast-server
 * @date 17.06.17
 * @email nikita@kulikof.ru
 *
 * This class helped easy put or get var from DB. Using sqlite_orm and sqlite
 * 
 **/
#ifndef RECAST_SERVER_SQLITE_H
#define RECAST_SERVER_SQLITE_H

#include <sqlite_orm/sqlite_orm.h>
#include "models/Player.h"
#include "models/User.h"

inline auto create_db() {
    using namespace sqlite_orm;
    return make_storage("db.sqlite",
                        make_table("players",
                                   make_column("id",
                                               &Player::id,
                                               autoincrement(),
                                               primary_key()),
                                   make_column("user_id",
                                               &Player::userId)),
                        make_table("users",
                                   make_column("id",
                                               &User::id,
                                               autoincrement(),
                                               primary_key()),
                                   make_column("login",
                                               &User::login,
                                               unique()),
                                   make_column("password",
                                               &User::password),
                                   make_column("player_id",
                                               &User::playerId)));
}
/**
 * @brief This class helped easy put or get var from DB. Using sqlite_orm and sqlite
 **/
class SQLite {
public:
    SQLite() { storage.sync_schema(); }

    User registerUser(std::string login, std::string password);

    User authUser(std::string login, std::string password);

    void update(Player player);

private:
    decltype(create_db()) storage = create_db();
};


#endif //RECAST_SERVER_SQLITE_H
