# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-src"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-build"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/shasdor/CalcGTestHomeTask/CalcGTest/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
