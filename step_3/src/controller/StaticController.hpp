
#pragma once

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include <filesystem>
#include <fstream>

#include OATPP_CODEGEN_BEGIN(ApiController)

class StaticController : public oatpp::web::server::api::ApiController
{
public:
  StaticController(const std::shared_ptr<ObjectMapper> &objectMapper)
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

  static std::shared_ptr<StaticController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
  {
    return std::make_shared<StaticController>(objectMapper);
  }

  ENDPOINT("GET", "/", root)
  {
    auto index_html_path = std::filesystem::path(STATIC_HTML);
    std::ifstream index_html_file(index_html_path / "index.html");
    std::stringstream index_html;
    index_html << index_html_file.rdbuf();

    auto response = createResponse(Status::CODE_200, index_html.str().c_str());
    response->putHeader(Header::CONTENT_TYPE, "text/html");
    return response;
  };
};

#include OATPP_CODEGEN_END(ApiController)
