
#pragma once

#include "DatabaseComponent.hpp"
#include "SwaggerComponent.hpp"

#include "ErrorHandler.hpp"

#include <oatpp/core/macro/component.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/web/server/HttpRouter.hpp>

class AppComponent
{
public:
  DatabaseComponent databaseComponent;

  SwaggerComponent swaggerComponent;

  // object mapper for serialization and deserialization
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)
  (
      []
      {
        auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        objectMapper->getDeserializer()->getConfig()->allowUnknownFields = false;

        return objectMapper;
      }());

  // connection provider listening on the port
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)
  (
      []
      {
        return oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"0.0.0.0", 8000, oatpp::network::Address::IP_4});
      }());

  // http router
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)
  (
      []
      {
        return oatpp::web::server::HttpRouter::createShared();
      }());

  // connection handler for routing requests
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)
  (
      []
      {
        // component getter
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
        OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper);

        auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
        connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));

        return connectionHandler;
      }());


};
