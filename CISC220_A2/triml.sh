#!/usr/bin/env bash

shopt -s extglob

input=$(cat)
input=${input%x}
echo "${input##+( )}"