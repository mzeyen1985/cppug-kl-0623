
#pragma once

#include "dto/MyDTOs.hpp"

#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/web/server/api/ApiController.hpp>

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
  static std::shared_ptr<MyController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                                                                    objectMapper))
  {
    return std::shared_ptr<MyController>(new MyController(objectMapper));
  }

  // hello world endpoint mapped to root
  ENDPOINT_ASYNC("GET", "/", Root){
      ENDPOINT_ASYNC_INIT(Root)

          Action act() override{
              auto dto = HelloDto::createShared();
  dto->message = "Hello Async!";
  dto->server = Header::Value::SERVER;
  dto->userAgent = request->getHeader(Header::USER_AGENT);

  return _return(controller->createDtoResponse(Status::CODE_200, dto));
}
}
;

// echo body endpoint mapped to "/body/string"
// return body received in the request
ENDPOINT_ASYNC("GET", "/body/string", EchoStringBody){
    ENDPOINT_ASYNC_INIT(EchoStringBody)

        Action act() override{
            return request->readBodyToStringAsync().callbackTo(&EchoStringBody::returnResponse);
}

Action returnResponse(const oatpp::String &body)
{
  return _return(controller->createResponse(Status::CODE_200, body));
}
}
;

// echo body endpoint mapped to "/body/dto"
ENDPOINT_ASYNC("GET", "/body/dto", EchoDtoBody){
    ENDPOINT_ASYNC_INIT(EchoDtoBody)

        Action act() override{
            return request->readBodyToDtoAsync<oatpp::Object<MessageDto>>(controller->getDefaultObjectMapper()).callbackTo(&EchoDtoBody::returnResponse);
}

Action returnResponse(const oatpp::Object<MessageDto> &body)
{
  return _return(controller->createDtoResponse(Status::CODE_200, body));
}
}
;
}
;

#include OATPP_CODEGEN_BEGIN(ApiController)
