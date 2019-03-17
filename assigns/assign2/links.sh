#!/bin/sh

PROGS=/home/turing/mhou/csci652fall2018/progs

for dir in 01 02 03 04 05 06 07 08 09 10;
do

ln -s $PROGS/blastz dataset$dir
ln -s $PROGS/lav2maf dataset$dir
ln -s $PROGS/single_cov2 dataset$dir
ln -s $PROGS/maf_project dataset$dir

done
