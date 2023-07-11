#include "AppComponent.hpp"

#include "controller/UserController.hpp"
#include "controller/StaticController.hpp"

#include <oatpp-swagger/Controller.hpp>

#include <oatpp/network/Server.hpp>

int main(int argc, char **argv)
{
  oatpp::base::Environment::init();

  AppComponent components;

  OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

  oatpp::web::server::api::Endpoints docEndpoints;

  docEndpoints.append(router->addController(UserController::createShared())->getEndpoints());

  router->addController(oatpp::swagger::Controller::createShared(docEndpoints));
  router->addController(StaticController::createShared());

  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
  OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

  oatpp::network::Server server(connectionProvider, connectionHandler);

  OATPP_LOGD("Server", "Running on port %s...", connectionProvider->getProperty("port").toString()->c_str());

  server.run();

  // stop db connection pool
  OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, dbConnectionProvider);
  dbConnectionProvider->stop();

  oatpp::base::Environment::destroy();

  return EXIT_SUCCESS;
}
