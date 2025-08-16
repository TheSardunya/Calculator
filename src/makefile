default: ac.exe
oreno.obj : oreno.cpp oreno.h
  cl /c oreno.cpp
orenomath.obj : orenomath.cpp orenomath.h
  cl /c orenomath.cpp
orenomath.lib : orenomath.obj
  lib /OUT:orenomath.lib orenomath.obj
oreno.lib : oreno.obj
  lib /OUT:oreno.lib oreno.obj
ac.res : ac.rc
  rc ac.rc
ac.exe : oreno.lib orenomath.lib ac.res ac.cpp
  cl /EHsc ac.cpp ac.res /link oreno.lib orenomath.lib


