#pragma once
#include <exception>
#include <string>

namespace SimpleIni {
  class FileOpenException : public std::runtime_error {
  public:
    explicit FileOpenException(const std::string& fileName) noexcept
        : std::runtime_error("Unable to open file " + fileName) {
    }
  };

  class ParamNotFoundException : public std::runtime_error {
  public:
    explicit ParamNotFoundException(const std::string& paramName) noexcept
        : std::runtime_error("Parameter " + paramName + " not found") {
    }
  };

  class SectionNotFoundException : public std::runtime_error {
  public:
    explicit SectionNotFoundException(const std::string& sectionName)
        : std::runtime_error("Section " + sectionName + " not found") {
    }
  };
}