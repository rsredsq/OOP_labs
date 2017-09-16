#include <exception>
#include <string>

namespace SimpleIni {
  class SectionNotFoundException : std::exception {
  public:
    explicit SectionNotFoundException(const std::string& sectionName)
        : message("Section " + sectionName + " not found") {
    }

    ~SectionNotFoundException() noexcept override = default;

    const char* what() const noexcept override {
      return message.what();
    }

  private:
    const std::runtime_error message;
  };
}