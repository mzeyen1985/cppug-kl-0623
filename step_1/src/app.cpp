#include "AppComponent.hpp"
#include "controller/MyController.hpp"

#include <oatpp/network/Server.hpp>

int main(int argc, char **argv)
{
  oatpp::base::Environment::init();

  AppComponent components;

  auto router = components.httpRouter.getObject();
  router->addController(MyController::createShared());

  oatpp::network::Server server(
      components.serverConnectionProvider.getObject(),
      components.serverConnectionHandler.getObject());

  OATPP_LOGD("Server", "Running on port %s...", components.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());

  server.run();

  oatpp::base::Environment::destroy();

  return EXIT_SUCCESS;
}
