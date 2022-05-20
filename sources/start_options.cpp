// Copyright 2021 Your Name <your_email>

#include "start_options.hpp"
#include "Builder.hpp"

Options::Options(int argc, const char **argv) {
  _description.add_options()
      ("help,h", "print usage message")
      ("config,c", po::value<std::string>(&_config)->default_value("Debug"), "cmake configuration <Release|Debug>")
      ("install,i", po::bool_switch(&_install)->default_value(false), "add installation stage")
      ("pack,p", po::bool_switch(&_pack)->default_value(false), "add pack stage")
      ("timeout,t",po::value<int>(&_time_out)->default_value(0),"add timeout <seconds>");
  po::store(po::parse_command_line(argc, argv, _description), _vm);
  po::notify(_vm);

  if (_vm.count("help")) {
    _is_throw = true;
    std::cout << _description << std::endl;
  }
}


int Options::exec() {
  if (_is_throw) {
    return 1;
  }

  bool is_timeout = false;

  if (_time_out != 0) {
    is_timeout = true;
  }

  Builder builder(_config, _install, _pack, is_timeout, _time_out);
  builder.Run();
  return 0;
}