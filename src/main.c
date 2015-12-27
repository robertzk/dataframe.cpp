#ifndef DATAFRAME_MAIN
#define DATAFRAME_MAIN 1
#endif

#include <iostream>
#include "dataframe/dataframe.h"

int main(int argc, char** argv) {
  std::cout << sizeof(dataframe::dataframe) << std::endl;
  return 0;
}

