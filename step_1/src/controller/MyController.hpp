
#pragma once

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/web/server/api/ApiController.hpp>

#include <filesystem>
#include <fstream>
#include <sstream>

#include OATPP_CODEGEN_BEGIN(ApiController)

// basic endpoints
class MyController : public oatpp::web::server::api::ApiController
{
protected:
  MyController(const std::shared_ptr<ObjectMapper> &objectMapper)
      : oatpp::web::server::api::ApiController(objectMapper)
  {
  }

public:
  // inject object mapper component
  static std::shared_ptr<MyController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
  {
    return std::shared_ptr<MyController>(new MyController(objectMapper));
  }

  // static html endpoint mapped to root
  ENDPOINT_ASYNC("GET", "/", Root)
  {
    ENDPOINT_ASYNC_INIT(Root)

    Action act() override
    {
      auto index_html_path = std::filesystem::current_path() / "site" / "index.html";
      std::ifstream index_html_file(index_html_path);
      std::stringstream index_html;
      index_html << index_html_file.rdbuf();

      return _return(controller->createResponse(Status::CODE_200, index_html.str().c_str()));
    }
  };
};

#include OATPP_CODEGEN_BEGIN(ApiController)
