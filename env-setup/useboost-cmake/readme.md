<details>
<summary>

### how to use boost 1.68.0? click here!

</summary>

<details>
<summary>

add below in your CMakeLists.txt->

</summary>

```cmake

cmake_minimum_required(VERSION 3.10)
project(test)
set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.68 REQUIRED)
#sometimes you need to add come components in boost, uncomment below and add Boost::<missed component> in target_link_libraries()
# find_package(Boost COMPONENTS system )
include_directories(${Boost_INCLUDE_DIR})

add_executable(main main.cpp)

target_link_libraries(  main 
                        ${Boost_LIBRARIES} 
                        pthread
                        # Boost::<missed components>
                        )


```
</details>

</details>
