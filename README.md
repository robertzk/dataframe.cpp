# Data.frames in 100% C++

This is an attempt to recreate R's [data.frame](https://stat.ethz.ch/R-manual/R-devel/library/base/html/data.frame.html) in C++.

The primary idea is to rely on [tag dispatch](http://www.boost.org/community/generic_programming.html)
to achieve the illusion of type heterogeneity across the columns.

In order to support string vectors, we use a rebalancing [stochastic string map](http://github.com/robertzk/stringmap.cpp).


