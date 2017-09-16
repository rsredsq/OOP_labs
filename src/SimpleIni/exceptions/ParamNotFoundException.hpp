#include <exception>
#include <string>

namespace SimpleIni {
  class ParamNotFoundException : std::exception {
  public:
    explicit ParamNotFoundException(const std::string& paramName) noexcept
        : message("Parameter " + paramName + " not found") {
    }

    ~ParamNotFoundException() noexcept override = default;

    const char* what() const noexcept override {
      return message.what();
    }

  private:
    std::runtime_error message;
  };
}