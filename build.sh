#!/bin/bash

mkdir -p _build && cd _build

cmake ../source && make

cd program && cp ./editBase ./editBase-copy

