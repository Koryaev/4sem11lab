#include "start_options.hpp"

int main(int argc, const char* argv[]) {
  Options app(argc, argv);
  return app.exec();
}
