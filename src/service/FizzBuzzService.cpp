#include "FizzBuzzService.hpp"

oatpp::Object<StatusDto> FizzBuzzService::getFizzBuzz(const oatpp::Object<FizzBuzzDto>& dto) {

  // insert data to DB
  auto dbResult = m_database->insertFizzBuzz(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  // create result based on input
  std::string message = dto->computeFizzBuzz();
  auto status = StatusDto::createShared();
  status->status = "OK";
  status->code = 200;
  status->message = message;
  return status;
}

oatpp::Object<FizzBuzzDto> FizzBuzzService::getStats() {
  auto dbResult = m_database->getStats();
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FizzBuzzDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}