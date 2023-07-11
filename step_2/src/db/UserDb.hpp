#pragma once

#include "dto/UserDto.hpp"

#include <oatpp-sqlite/orm.hpp>

#include <filesystem>

#include OATPP_CODEGEN_BEGIN(DbClient)

class UserDb : public oatpp::orm::DbClient
{
public:
  UserDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
    : oatpp::orm::DbClient(executor)
  {
    auto db_migrations = std::filesystem::path(DATABASE_MIGRATIONS);
    oatpp::orm::SchemaMigration migration(executor);
    migration.addFile(
      1, // start from version 1
      (db_migrations / "001_init.sql").string());
    migration.migrate(); // <-- run migrations. This will throw on error.

    auto version = executor->getSchemaVersion();
    OATPP_LOGD("UserDb", "Migration - OK. Version=%lld.", version);
  }

  QUERY(createUser,
        "INSERT INTO AppUser"
        "(username, email, password, role) VALUES "
        "(:user.username, :user.email, :user.password, :user.role);",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(updateUser,
        "UPDATE AppUser "
        "SET "
        " username=:user.username, "
        " email=:user.email, "
        " password=:user.password, "
        " role=:user.role "
        "WHERE "
        " id=:user.id;",
        PARAM(oatpp::Object<UserDto>, user))

  QUERY(getUserById,
        "SELECT * FROM AppUser WHERE id=:id;",
        PARAM(oatpp::Int32, id))

  QUERY(getAllUsers,
        "SELECT * FROM AppUser LIMIT :limit OFFSET :offset;",
        PARAM(oatpp::UInt32, offset),
        PARAM(oatpp::UInt32, limit))

  QUERY(deleteUserById,
        "DELETE FROM AppUser WHERE id=:id;",
        PARAM(oatpp::Int32, id))
};

#include OATPP_CODEGEN_END(DbClient)
