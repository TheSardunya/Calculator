ac.exe : ac.cpp oreno.cpp orenomath.cpp ac.rc
  cl /c oreno.cpp
  lib /OUT:oreno.lib oreno.obj
  cl /c orenomath.cpp
  lib /OUT:orenomath.lib orenomath.obj
  rc ac.rc
  cl /EHsc ac.cpp ac.res /link oreno.lib orenomath.lib
ac: ac.exe
