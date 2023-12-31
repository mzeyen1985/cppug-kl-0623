
#pragma once

#include <oatpp-swagger/Model.hpp>
#include <oatpp-swagger/Resources.hpp>
#include <oatpp/core/macro/component.hpp>

class SwaggerComponent
{
public:
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
    oatpp::swagger::DocumentInfo::Builder builder;

    builder
    .setTitle("User entity service")
    .setDescription("CRUD API Example project with swagger docs")
    .setVersion("1.0")
    .setContactName("Max")
    .setContactUrl("https://www.itwm.fraunhofer.de/de/abteilungen/hpc/mitarbeiter/max-zeyen.html")

    .setLicenseName("Apache License, Version 2.0")
    .setLicenseUrl("http://www.apache.org/licenses/LICENSE-2.0")

    .addServer("http://localhost:8000", "server on localhost");

    return builder.build();
  }());

  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
  }());
};
