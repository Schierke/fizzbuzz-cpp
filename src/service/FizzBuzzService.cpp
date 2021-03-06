#include "FizzBuzzService.hpp"

oatpp::Object<PageDto> FizzBuzzService::getFizzBuzz(const oatpp::Object<FizzBuzzDto>& dto) {
  // check input data:
  OATPP_ASSERT_HTTP(dto->validate() == "", Status::CODE_406, dto->validate());
  
  // insert data to DB
  auto dbResult = m_database->insertFizzBuzz(dto);
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
  OATPP_LOGD("FizzBuzzService", "Finish adding new FizzBuzz data on DB, results:");

  // create result based on input
  std::vector<std::string> items = dto->computeFizzBuzz();
  oatpp::Object<PageDto> output = PageDto::createShared();
  output->items = {};
  
  for(const std::string& item : items) {
    OATPP_LOGD("FizzBuzzService", " %s", item.c_str());
    oatpp::String current(item.c_str(), item.length());
    output->items->push_back(current);
  }
  
  return output;
}

oatpp::Object<FizzBuzzDto> FizzBuzzService::getStats() {
  auto dbResult = m_database->getStats();
  OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

  auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FizzBuzzDto>>>();
  OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
  return result[0];
}