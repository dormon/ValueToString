#pragma once

#include<type_traits>
#include<iostream>
#include<vector>
#include<memory>
#include<sstream>
#include<typeinfo>

namespace dsl{

  template<typename T,typename std::enable_if<std::is_fundamental<T>::value,unsigned>::type = 0>
    std::string valueToString(T const&v);

  template<typename T,typename std::enable_if<std::is_pointer<T>::value,unsigned>::type = 0>
    std::string valueToString(T const&v);

  template<typename T>
    std::string valueToString(std::vector<T>const&v);

  template<typename T>
    std::string valueToString(std::shared_ptr<T>const&v);

  std::string valueToString(std::string const&v);

  template<typename T,typename std::enable_if<std::is_enum<T>::value,unsigned>::type = 0>
    inline std::string valueToString(T const&v);

  template<typename T,typename std::enable_if<std::is_class<T>::value,unsigned>::type = 0>
    inline std::string valueToString(T const&v);

  template<typename T,typename std::enable_if<std::is_member_function_pointer<T>::value,unsigned>::type = 0>
    inline std::string valueToString(T const&v);


  template<typename T,typename std::enable_if<std::is_fundamental<T>::value,unsigned>::type>
    inline std::string valueToString(T const&v){
      std::stringstream ss;
      ss<<v;
      return ss.str();
    }

  template<typename T,typename std::enable_if<std::is_pointer<T>::value,unsigned>::type>
    inline std::string valueToString(T const&v){
      std::stringstream ss;
      ss<<v;
      return ss.str();
    }

  template<typename T>
    inline std::string valueToString(std::vector<T>const&v){
      std::stringstream ss;
      ss << "[";
      bool first = true;
      for(auto const&x:v){
        if(first)first=false;
        else ss<<",";
        ss << valueToString(x);
      }
      ss << "]";
      return ss.str();
    }

  inline std::string valueToString(std::string const&v){
    return "\""+v+"\"";
  }

  template<typename T>
    inline std::string valueToString(std::shared_ptr<T>const&v){
      std::stringstream ss;
      ss<<v;
      return ss.str();
    }

  template<typename T,typename std::enable_if<std::is_enum<T>::value,unsigned>::type>
    inline std::string valueToString(T const&v){
      std::stringstream ss;
      ss<<(size_t)v;
      return ss.str();
    }

  template<typename T,typename std::enable_if<std::is_class<T>::value,unsigned>::type>
    inline std::string valueToString(T const&){
      std::stringstream ss;
      ss<<typeid(T).name();
      return ss.str();
    }

  template<typename T,typename std::enable_if<std::is_member_function_pointer<T>::value,unsigned>::type>
    inline std::string valueToString(T const&v){
      std::stringstream ss;
      ss<<v;
      return ss.str();
    }

}

