#ifndef UserDto_hpp
#define UserDto_hpp

#include <string>
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp/core/utils/ConversionUtils.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class FizzBuzzDto : public oatpp::DTO {
  
  DTO_INIT(FizzBuzzDto, DTO)
  DTO_FIELD(UInt32, hits);
  DTO_FIELD(UInt32, int1);
  DTO_FIELD(UInt32, int2);
  DTO_FIELD(String, str1);
  DTO_FIELD(String, str2);
  DTO_FIELD(UInt32, max_limit);

public:
  std::vector<std::string> computeFizzBuzz()  {
    std::vector<std::string> ret;
    std::string temp =  "";
    for(int i = 1; i <= max_limit; i++) {
      if(i % int1 == 0) {
        temp += str1.getValue("");
      } 

      if(i % int2 == 0) {
        temp += str2.getValue("");
      } 

      if(temp == "") {
        temp = std::to_string(i);
      }

      ret.push_back(temp);
      temp = "";
    }

    return ret;
  }
};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
