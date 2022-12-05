#ifndef SRC_CLIENT_PUZZLEINPUTFETCHER_H
#define SRC_CLIENT_PUZZLEINPUTFETCHER_H
#include <curl/curl.h>

#include <istream>
#include <memory>
#include <string>

namespace client {
// Fetches puzzle inputs for a given day over the network.
class PuzzleInputFetcher {
 public:
  PuzzleInputFetcher();
  ~PuzzleInputFetcher();

  std::unique_ptr<std::istream> FetchInput(int day);

 private:
  CURL* curl;
  std::string buffer;
  static size_t write_callback(char* ptr, size_t size, size_t nmemb,
                               void* userdata);
};
}  // namespace client
#endif
