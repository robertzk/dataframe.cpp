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
    
    // Mimicking STL iterator tags.
    struct column_tag { };
    struct double_column_tag : public column_tag { };
    struct int_column_tag    : public double_column_tag { };
    struct bool_column_tag   : public int_column_tag { };
    struct string_column_tag : public column_tag { };

    union column {
      std::vector<int>         *int_column;
      std::vector<double>      *double_column;
      std::vector<std::string> *string_column;
      std::vector<bool>        *bool_column;

      // http://stackoverflow.com/questions/5060177/c-casting-a-union-to-one-of-its-member-types
      operator std::vector<int>*() const         { return int_column; }
      operator std::vector<double>*() const      { return double_column; }
      operator std::vector<std::string>*() const { return string_column; }
      operator std::vector<bool>*() const        { return bool_column; }
    };

    void add_column(std::string key, std::vector<int> &int_column) {
      column x = column();
      x.int_column = &int_column;
      this->columns[key] = std::pair<int_column_tag, column>(int_column_tag(), x);
    }

    inline std::vector<int>* operator[](std::string key) const {
      auto it = this->columns.find(key);
      if (it == columns.end()) {
        throw std::out_of_range("No such key: " + key);
      } else {
        return dataframe::get_column((*it).second.second, int_column_tag());
      }
    }
    
    static std::vector<int>         *get_column(column c, int_column_tag) { return (std::vector<int>*)(c); }
    static std::vector<double>      *get_column(column, double_column_tag);
    static std::vector<std::string> *get_column(column, string_column_tag);
    static std::vector<bool>        *get_column(column, bool_column_tag);

  private:
    std::map<std::string, std::pair<column_tag, column> > columns;
    

  };
}

#endif // DATAFRAME_INCLUDE_DATAFRAME_H

#ifndef DATAFRAME_MAIN
int main(int argc, char** argv) {
  dataframe::dataframe df;
  std::vector<int> vec = { 1, 2, 3 };
  df.add_column("foo", vec);
  std::cout << sizeof(dataframe::dataframe::column) << std::endl;
  std::cout << (*df["foo"])[2] << std::endl;
 
  return 0;
}
#endif

