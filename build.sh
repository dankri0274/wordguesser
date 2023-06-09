#!/bin/bash

platform=""

while getopts "mlw" option; do
	case $option in
		m)
			platform="macos"
			;;
		l)
			platform="linux"
			;;
		w)
			platform="windows"
			;;
		*)
			echo "Invalid argument: $OPTARG"
			exit 1
			;;
	esac
done

if [ -z "$platform" ]; then
	echo "Please specify the target platform: -m (macOS), -l (Linux), -w (Windows)"
	exit 1
fi

if [ "$platform" == "macos" ]; then
	gcc -o game game.c
	chmod +x game
elif [ "$platform" == "linux" ]; then
	gcc -o game game.c
	chmod +x game
elif [ "$platform" == "windows" ]; then
	gcc -o game.exe game.c
else
	echo "Invalid platform: $platform"
	exit 1
fi
