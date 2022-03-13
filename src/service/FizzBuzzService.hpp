
#ifndef EXAMPLE_POSTGRESQL_USERSERVICE_HPP
#define EXAMPLE_POSTGRESQL_USERSERVICE_HPP

#include "db/FizzBuzzDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class FizzBuzzService {
private:
  typedef oatpp::web::protocol::http::Status Status;
private:
  OATPP_COMPONENT(std::shared_ptr<FizzBuzzDb>, m_database); // Inject database component
public:

  oatpp::Object<StatusDto> getFizzBuzz(const oatpp::Object<FizzBuzzDto>& dto);
  oatpp::Object<FizzBuzzDto> getStats();


};

#endif //EXAMPLE_POSTGRESQL_USERSERVICE_HPP
