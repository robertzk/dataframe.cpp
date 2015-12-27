// Copyright (c) 2016 Robert Krzyzanowski. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef DATAFRAME_INCLUDE_DATAFRAME_H
#define DATAFRAME_INCLUDE_DATAFRAME_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace dataframe {
  class dataframe {
  public:

    union column {
      std::vector<int>         *int_column;
      std::vector<double>      *double_column;
      std::vector<std::string> *string_column;
      std::vector<bool>        *bool_column;
    };
    

  private:
    std::map<std::string, column> columns;
    

  };
}

#endif // DATAFRAME_INCLUDE_DATAFRAME_H

#ifndef DATAFRAME_MAIN
int main(int argc, char** argv) {
  std::cout << sizeof(dataframe::dataframe::column);
  return 0;
}
#endif

