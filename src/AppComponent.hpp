
#pragma once

#include <oatpp/core/macro/component.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/AsyncHttpConnectionHandler.hpp>
#include <oatpp/web/server/HttpRouter.hpp>

class AppComponent
{
public:
  // async executor
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor)
  (
      []
      {
        return std::make_shared<oatpp::async::Executor>(
            9,  // data processing threads
            2,  // IO threads
            1); // timer threads
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

  /**
   *  Create ConnectionHandler component which uses Router component to route requests
   */
  // connection handler for routing requests
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)
  (
      []
      {
        // component getter
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
        OATPP_COMPONENT(std::shared_ptr<oatpp::async::Executor>, executor);

        return oatpp::web::server::AsyncHttpConnectionHandler::createShared(router, executor);
      }());

  // object mapper for serialization and deserialization
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)
  (
      []
      {
        auto serializerConfig = oatpp::parser::json::mapping::Serializer::Config::createShared();
        auto deserializerConfig = oatpp::parser::json::mapping::Deserializer::Config::createShared();
        deserializerConfig->allowUnknownFields = false;
        auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared(serializerConfig, deserializerConfig);

        return objectMapper;
      }());
};
