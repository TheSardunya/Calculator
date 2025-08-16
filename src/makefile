default:
oreno.obj : oreno.cpp oreno.h ; cl /c oreno.cpp
orenomath.obj : orenomath.cpp orenomath.h ; cl /c orenomath.cpp
orenomath.lib : orenomath.obj; lib /OUT:orenomath.lib orenomath.obj
oreno.lib : oreno.obj; lib /OUT:oreno.lib oreno.obj
ac.rc : ac.res ; rc ac.res
ac.exe : oreno.lib orenomath.lib ac.rc ; cl /EHsc ac.cpp ac.rc /link oreno.lib orenomath.lib