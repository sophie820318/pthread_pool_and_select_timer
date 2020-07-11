#指定cmake最小版本
cmake_minimum_required(VERSION 3.5.1)
project (Timer)
#源文件
set(SOURCES 
    src/main.c
    src/pthread_pool.c
    src/timer_select.c
    )


#链接pthread库  
link_libraries(-lpthread)

add_executable(${PROJECT_NAME} ${SOURCES})

#头文件
target_include_directories(${PROJECT_NAME} 
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include 
    )
