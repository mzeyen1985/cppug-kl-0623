#pragma once

#include "db/UserDb.hpp"

#include <oatpp/core/macro/component.hpp>

#include <filesystem>

class DatabaseComponent
{
public:
  // create db connection provider
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider)
  ([]
   {
     auto db_file = std::filesystem::path(DATABASE_FILE);
     auto connectionProvider = std::make_shared<oatpp::sqlite::ConnectionProvider>(db_file.string());

     return oatpp::sqlite::ConnectionPool::createShared(connectionProvider,
                                                        10,                       // max connections
                                                        std::chrono::seconds(5)); // connection TTL
   }());

  // create db client
  OATPP_CREATE_COMPONENT(std::shared_ptr<UserDb>, userDb)
  ([]
   {
     OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

     auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

     return std::make_shared<UserDb>(executor);
   }());
};
