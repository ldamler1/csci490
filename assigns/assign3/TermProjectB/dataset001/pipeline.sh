#!/bin/sh
L=2000
O=300
T=1
W=8
#Only when T=0 9,10,11,12... T=1,2,3,4

while [ $L -le 5000 ]; do
    for species in BABOON CAT CHIMP COW DOG MOUSE PIG RAT;
    do
   	 echo aligning HUMAN and $species ...
   	 ./blastz HUMAN $species L=$L O=$O T=$T\
   	 | ./lav2maf /dev/stdin HUMAN $species \
   	 | ./single_cov2 /dev/stdin R=HUMAN \
  	 | ./maf_project /dev/stdin HUMAN \
   	 > HUMAN.$species.L$L.O$O.maf
    done
    L=$((L+1000))
    echo $L
done
