#!/bin/sh
K=2000
O=300
T=1
W=8
#w = 18
#t = 0,1,2

while [ $O -le 500 ]; do
	while [ $K -le 5000 ]; do
	    for species in BABOON CAT CHIMP COW DOG MOUSE PIG RAT;
	    do
	 	 echo aligning HUMAN and $species ...
	       	 ./blastz HUMAN $species K=$K O=$O T=$T\
	   	 | ./lav2maf /dev/stdin HUMAN $species \
	   	 | ./single_cov2 /dev/stdin R=HUMAN \
	  	 | ./maf_project /dev/stdin HUMAN \
	   	 > HUMAN.$species.K$K.O$O.T$T.maf
	    done
	    K=$((K+1000))
	    echo $K
	    rm -r *.K4000.*
	done
	K=$((K-4000))
	O=$((O+200))
	echo $O
done
