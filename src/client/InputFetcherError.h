#ifndef SRC_CLIENT_INPUTFETCHERERROR_H
#define SRC_CLIENT_INPUTFETCHERERROR_H

#include <exception>

namespace client {
// Generic exception to report error conditions that may arise when fetching
// puzzle inputs, such as cURL errors.
class InputFetcherError : public std::exception {
 public:
  explicit InputFetcherError(const char* message) noexcept
      : message_(message) {}
  const char* what() const noexcept override { return message_; }

 private:
  const char* message_;
};
}  // namespace client
#endif
