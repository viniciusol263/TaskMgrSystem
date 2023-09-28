#pragma once

#include <string>
#include "sqlite_orm/sqlite_orm.h"

namespace Common
{
    struct Account
    {
        int id;
        std::string accountId;
        std::string username;
        std::string password;
        int typeId;
    };

    inline auto InitAccountStorage(const std::string &path) {
        using namespace sqlite_orm;
        return make_storage(path,
                            make_table("accounts",
                                    make_column("ID",
                                                &Common::Account::id,
                                                primary_key()),
                                    make_column("ACCOUNTID",
                                                &Common::Account::accountId),
                                    make_column("USERNAME",
                                                &Common::Account::username),
                                    make_column("PASSWORD",
                                                &Common::Account::password),
                                    make_column("TYPEID",
                                                &Common::Account::typeId)));
    }

    using AccountStorage = decltype(InitAccountStorage(""));
};