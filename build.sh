#! /bin/bash

function build()
{
    if [ ! -d build ]
    then
        mkdir -p build
    fi
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    # cmake .. -DCMAKE_BUILD_TYPE=Release
    make -j 16
}

function clean()
{
    if [ -d build ]
    then
        cd build
        rm -rf ./*
    fi
}

function main()
{
    if [[ $# > 0 ]]
    then
        case $1 in
        "distclean" | "clean")
            clean
            exit 0
            ;;
        esac
    fi
    build
}

main $@