#include <exception>
#include <string>

namespace SimpleIni {
  class FileOpenException : public std::exception {
  public:
    explicit FileOpenException(const std::string& fileName) noexcept
        : message("Unable to open file " + fileName) {
    }

    ~FileOpenException() noexcept override = default;

    const char* what() const noexcept override {
      return message.what();
    }

  private:
    std::runtime_error message;
  };
}