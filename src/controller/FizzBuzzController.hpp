
#ifndef FizzBuzzController_hpp
#define FizzBuzzController_hpp

#include "service/FizzBuzzService.hpp"
#include <iostream>

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * User REST controller.
 */
class FizzBuzzController : public oatpp::web::server::api::ApiController {
public:
  FizzBuzzController(const std::shared_ptr<ObjectMapper>& objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
private:
  FizzBuzzService m_fbService; // Create user service.
public:

  static std::shared_ptr<FizzBuzzController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<FizzBuzzController>(objectMapper);
  }
  
  ENDPOINT_INFO(getFizzBuzz) {
    info->summary = "Create or update a FizzBuzz request";
    info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "fizzbuzz/int1/{int1}/int2/{int2}/str1/{str1}/str2/{str2}/limit/{limit}", getFizzBuzz,
           PATH(UInt32, int1),
           PATH(UInt32, int2),
           PATH(String, str1),
           PATH(String, str2),
           PATH(UInt32, limit))
  {
    // perform check type validation from the request:
    // createDtoResponse
    oatpp::Object<FizzBuzzDto> fbDto = FizzBuzzDto::createShared();
    fbDto->int1 = int1;
    fbDto->int2 = int2;
    fbDto->str1 = str1;
    fbDto->str2 = str2;
    fbDto->max_limit = limit;
    return createDtoResponse(Status::CODE_200, m_fbService.getFizzBuzz(fbDto));
  }


  ENDPOINT_INFO(getStats) {
    info->summary = "Get the most requested FizzBuzz";
    info->addResponse<Object<FizzBuzzDto>>(Status::CODE_200, "application/json");
    info->addResponse<Object<FizzBuzzDto>>(Status::CODE_500, "application/json");
  }
  ENDPOINT("GET", "stats", getStats)
  {
    return createDtoResponse(Status::CODE_200, m_fbService.getStats());
  }

};

#include OATPP_CODEGEN_BEGIN(ApiController) //<- End Codegen

#endif /* FizzBuzzController_hpp */
