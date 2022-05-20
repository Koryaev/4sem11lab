// Copyright 2021 Your Name <your_email>

#include "Builder.hpp"
#include "ThreadPool.h"

bool is_running;
std::string directory;

namespace bp = boost::process;

Builder::Builder(std::string config, bool install, bool pack, bool timeout,
                 int timeout_value)
    : _config(std::move(config)),
      _install(install),
      _pack(pack),
      _timeout(timeout),
      _timeout_value(timeout_value) {
  directory = boost::filesystem::current_path().string();
  boost::filesystem::current_path(path);
  is_running = true;
}

void Builder::info() {
  std::cout << "\033[32m";
  if (_install) {
    std::cout << "Install\n";
  }
  if (_pack) {
    std::cout << "Pack\n";
  }
  if (_timeout) {
    std::cout << "Timeout\n";
  }
  std::cout << _config << "\033[0m" << std::endl << std::endl;
}

void Builder::timer() const {
  std::this_thread::sleep_for(std::chrono::seconds(_timeout_value));
  std::cout << "\033[31mTIMEOUT\033[0m\n";
  is_running = false;
  boost::filesystem::current_path(directory);
  exit(0);
}

void Builder::Run() {
  info();

  if (_timeout) {
    std::vector<std::thread> threads;
    std::thread timer(&Builder::timer, this);
    std::thread builder(&Builder::building, this);
    threads.emplace_back(std::move(timer));
    threads.emplace_back(std::move(builder));

    for (auto& thr : threads) {
      thr.join();
    }

  } else {
    building();
  }
}

void Builder::building() {
  async_init();
  async::event_task<std::string> event;
  auto task1 = event.get_task();

  auto task = task1.then([](std::string config) {
    bp::ipstream stream;
    bp::ipstream err;
    std::string text;
    std::string install(installation);
    bp::child proc(install + config, bp::start_dir(directory),
                   bp::std_out > stream);

    while (proc.running()) {
      std::getline(stream, text);
      std::cout << text << std::endl;
      if (!is_running) {
        proc.terminate();
      }
    }
  });

  event.set(_config);
  task.wait();

  auto task2 = async::spawn([]() {
    bp::ipstream stream;
    std::string text;
    bp::child proc(build, bp::start_dir(directory), bp::std_out > stream);

    while (proc.running()) {
      std::getline(stream, text);
      std::cout << text << std::endl;
      if (!is_running) {
        proc.terminate();
      }
    }
  });

  task2.wait();

  if (_install) {
    auto task3 = async::spawn([]() {
      bp::ipstream stream;
      std::string text;
      bp::child proc(target, bp::start_dir(directory), bp::std_out > stream);

      while (proc.running()) {
        std::getline(stream, text);
        std::cout << text << std::endl;
        if (!is_running) {
          proc.terminate();
        }
      }
    });
    task3.wait();
  }

  if (_pack) {
    auto task4 = async::spawn([]() {
      bp::ipstream stream;
      std::string text;
      bp::child proc(package, bp::start_dir(directory), bp::std_out > stream);

      while (proc.running()) {
        std::getline(stream, text);
        std::cout << text << std::endl;
        if (!is_running) {
          proc.terminate();
        }
      }
    });
    task4.wait();
  }
  boost::filesystem::current_path(directory);
  exit(0);
}
