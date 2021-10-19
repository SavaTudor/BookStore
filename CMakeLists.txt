cmake_minimum_required(VERSION 3.19)
project(Lab6_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6_7
        App.cpp
        Carte.cpp
        Carte.h
        Cos.cpp
        Cos.h
        exceptions.h
        MyList.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        TestCarte.cpp
        TestCarte.h
        TestCos.cpp
        TestCos.h
        TestList.cpp
        TestList.h
        TestRepo.cpp
        TestRepo.h
        Tests.cpp
        Tests.h
        TestService.cpp
        TestService.h
        TestValidator.cpp
        TestValidator.h
        UI.cpp
        UI.h
        ValidatorCarte.cpp
        ValidatorCarte.h)
