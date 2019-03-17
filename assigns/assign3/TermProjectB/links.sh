#!/bin/sh

PROGS=/home/turing/mhou/csci652fall2018/progs

for dir in 001 002 003 004 005 006 007 008 009 010;
do

ln -s $PROGS/blastz ./dataset$dir
ln -s $PROGS/lav2maf ./dataset$dir
ln -s $PROGS/single_cov2 ./dataset$dir
ln -s $PROGS/maf_project ./dataset$dir

done
