# cmake_cpp_subprojects
This is simple example how can be organised a C++ project with application which used some libraries and that libraries may depend on each other. Using cmake build system.

There are some code style used here:
* main application is placed in **app** directory
* libraries are placed in **libs** directory
  * each library is placed in separate directories. In our case they are **libA** and **libB**
* public headers are placed in **include** directory
* source files and private headers are placed in **src** directory

So, in general, there is structure of the project:
```
  |-app
  |-libs
     |-libA
     |-libB
```
Application uses **libA** and **libB**. Library **libA** has public and private source code. And it uses **libB**.

Explanation how to write such project is done by commits (they are shown in reverse order):
* **add simple app and folders structure**
  * here we just create our simple working app  
* **add library libA to the app**
  * and call this library from app
* **add some private code to libA and use it in main**
  * just to demonstrate how it can be
* **add libB to project**
  * similar to **libA**
* **add libB as a dependency for libA**
  * using **libB** in **app** and in **libA**
  
Main points - each logical block contains CMakeLists.txt:
```
  |-app
    |-CMakeLists.txt      -> application
  |-libs
     |-libA
        |-CMakeLists.txt  -> libA
     |-libB
        |-CMakeLists.txt  -> libB
     |-CMakeLists.txt     -> libraries
  |-CMakeLists.txt        -> root project  
```

* root CMakeLists.txt just declarate project and added directory to it: **app** and **libs**
```cmake
add_subdirectory(app)
add_subdirectory(libs)
```
* CMakeLists.txt in **libs** directory added directories with libraries source code: **libA** and **libB**
```cmake
add_subdirectory(libA)
add_subdirectory(libB)
```
* CMakeLists.txt files in directories **app**, **libA** and **libB** are ordinary cmake files. For example, **app** dependencies defined by:
```cmake
target_include_directories(CMAKE_VOODO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../libs)
add_dependencies(CMAKE_VOODO libA libB)
target_link_libraries(CMAKE_VOODO libA libB)
```
* **libA** added its dependence by referencing upper folders level and specify that it is only for internal build:
```cmake
target_include_directories(libA 
    PUBLIC 
        ...
    PRIVATE 
        ...
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
)
```

More information can be found in [cmake documentation]( https://cmake.org/cmake/help/latest/command/target_include_directories.html)

## License
MIT
