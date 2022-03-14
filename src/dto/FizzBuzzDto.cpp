#include "FizzBuzzDto.hpp"


std::vector<std::string> FizzBuzzDto::computeFizzBuzz() {
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

std::string FizzBuzzDto::validate() {
    std::string err = "";

    if(int1 <= 0) {
        err += "int1 must be greater than 0. ";
    }
    if(int2 <= 0) {
         err += "int2 must be greater than 0. ";
    }

    if(str1 == "") {
        err += "str1 must not be empty. ";
    }

    if(str2 == "") {
        err += "str2 must not be empty. ";
    }

    return err;
}
