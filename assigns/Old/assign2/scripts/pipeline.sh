#!/bin/sh
L=3000
O=300

for species in CHIMP DOG MOUSE;
do
    echo aligning HUMAN and $species ...
    ./blastz HUMAN $species L=$L O=$O \
    | ./lav2maf /dev/stdin HUMAN $species \
    | ./single_cov2 /dev/stdin R=HUMAN \
    | ./maf_project /dev/stdin HUMAN \
    > HUMAN.$species.L$L.O$O.maf
done
