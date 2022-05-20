// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <chrono>
#include <cstdlib>
#include <iostream>
#include <istream>
#include <string>
#include <utility>

#include "async++.h"

#include "boost/filesystem.hpp"
#include "boost/process.hpp"
#include "pthread.h"
#include "thread"
#include "boost/beast.hpp"

#define installation \
  "cmake -H. -B_builds -DCMAKE_INSTALL_PREFIX=_install -DCMAKE_BUILD_TYPE="
#define build "cmake --build _builds"
#define target "cmake --build _builds --target install"
#define package "cmake --build _builds --target package"
#define path \
  "/Users/mihailkoraev/Documents/GitHub/11lab/cmake-build-debug"


extern bool is_running;
extern std::string directory;

namespace bp = boost::process;

class Builder {
 private:
  std::string _config;
  bool _install;
  bool _pack;
  bool _timeout;
  int _timeout_value;

 public:
  Builder(std::string config, bool install, bool pack, bool timeout,
          int timeout_value);

  void Run();

 private:
  void info();

  void timer() const;

  void building();
};


#endif  // INCLUDE_EXAMPLE_HPP_
