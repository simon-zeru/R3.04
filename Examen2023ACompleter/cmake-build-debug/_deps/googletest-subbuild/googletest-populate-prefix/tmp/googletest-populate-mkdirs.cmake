# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-src"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-build"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/BUT/BUT2/S3/R3.04/Examen2023ACompleter/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()