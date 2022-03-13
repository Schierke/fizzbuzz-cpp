
#ifndef EXAMPLE_POSTGRESQL_PAGEDTO_HPP
#define EXAMPLE_POSTGRESQL_PAGEDTO_HPP

#include "FizzBuzzDto.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PageDto : public oatpp::DTO {

  DTO_INIT(PageDto, DTO)

  DTO_FIELD(UInt32, offset);
  DTO_FIELD(UInt32, limit);
  DTO_FIELD(UInt32, count);
  DTO_FIELD(Vector<T>, items);

};

class FizzBuzzPageDto : public PageDto<oatpp::Object<FizzBuzzDto>> {

  DTO_INIT(FizzBuzzPageDto, PageDto<oatpp::Object<FizzBuzzDto>>)

};

#include OATPP_CODEGEN_END(DTO)

#endif //EXAMPLE_POSTGRESQL_PAGEDTO_HPP
