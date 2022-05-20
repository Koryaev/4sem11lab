// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_START_OPTIONS_HPP_
#define INCLUDE_START_OPTIONS_HPP_

#include "boost/program_options.hpp"
#include "iostream"

namespace po = boost::program_options;

class Options {
 private:
  po::options_description _description{"Allowed options"};
  po::variables_map _vm;

  std::string _config;
  bool _install;
  bool _pack;
  int _time_out;
  bool _is_throw = false;

 public:
  Options(int argc, const char **argv);

  int exec();
};

#endif  // INCLUDE_START_OPTIONS_HPP_
