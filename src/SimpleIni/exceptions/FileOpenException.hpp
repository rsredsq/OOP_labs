#include <exception>
#include <string>

namespace SimpleIni {
  class FileOpenException : std::exception {
  public:
    explicit FileOpenException(const char* fileName) noexcept : fileName(fileName) {
    }

    ~FileOpenException() noexcept override = default;

    const char* what() const noexcept override {
      return fileName;
    }

  private:
    const char* fileName;
  };
}