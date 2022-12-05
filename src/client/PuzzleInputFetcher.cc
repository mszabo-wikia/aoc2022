#include "PuzzleInputFetcher.h"

#include <curl/curl.h>
#include <curl/easy.h>

#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include "InputFetcherError.h"

namespace client {
PuzzleInputFetcher::PuzzleInputFetcher() {
  curl = curl_easy_init();
  if (curl == nullptr) {
    throw InputFetcherError("cURL init failed");
  }
}
PuzzleInputFetcher::~PuzzleInputFetcher() { curl_easy_cleanup(curl); }

std::unique_ptr<std::istream> PuzzleInputFetcher::FetchInput(int day) {
  // Use an ephemeral cache directory to stash inputs and reuse cached data if
  // possible.
  auto cache_directory = std::filesystem::temp_directory_path() / "aoc2022";
  std::filesystem::create_directories(cache_directory);
  auto cache_file_name =
      cache_directory /
      std::filesystem::path("day" + std::to_string(day) + "-input-cache.txt");

  if (std::filesystem::exists(cache_file_name)) {
    return std::make_unique<std::ifstream>(cache_file_name);
  }

  auto token = std::getenv("AOC_SESSION_TOKEN");
  if (token == nullptr) {
    throw InputFetcherError("must provide AOC_SESSION_TOKEN");
  }

  char url[43];
  snprintf(url, sizeof(url), "https://adventofcode.com/2022/day/%d/input", day);

  char cookie[137];
  snprintf(cookie, sizeof(cookie), "session=%s", token);

  buffer.clear();

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_COOKIE, cookie);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                   &PuzzleInputFetcher::write_callback);

  auto res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    throw InputFetcherError(curl_easy_strerror(res));
  }

  long status;
  res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
  if (res != CURLE_OK) {
    throw InputFetcherError(curl_easy_strerror(res));
  }
  if (status != 200) {
    char status_error[31];
    snprintf(status_error, sizeof(status_error),
             "got non-successful status: %ld", status);
    throw InputFetcherError(status_error);
  }

  std::ofstream cache_file_writer(cache_file_name);
  cache_file_writer << buffer;

  return std::make_unique<std::istringstream>(buffer);
}

// cURL write callback in the format expected by CURLOPT_WRITEFUNCTION.
// Since C++ instance method pointers don't mesh well with that,
// this method is declared static and obtains an instance reference
// via the userdata parameter.
size_t PuzzleInputFetcher::write_callback(char* ptr, size_t size, size_t nmemb,
                                          void* userdata) {
  auto byte_size = size * nmemb;
  auto instance = reinterpret_cast<PuzzleInputFetcher*>(userdata);
  instance->buffer.append(ptr, byte_size);
  return byte_size;
}
}  // namespace client
