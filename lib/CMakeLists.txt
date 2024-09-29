set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set (SOURCESDLL
boots.cpp
broom.cpp
camel.cpp
carpet.cpp
centaur.cpp
eagle.cpp
fastCamel.cpp
flying.cpp
ground.cpp
vehicle.cpp)

set (HEADERSDLL
boots.h
broom.h
camel.h
carpet.h
centaur.h
eagle.h
fastCamel.h
flying.h
ground.h
vehicle.h)

add_library(Vehicles SHARED ${HEADERSDLL} ${SOURCESDLL})	