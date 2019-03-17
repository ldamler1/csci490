./blastz HUMAN MOUSE K=5000 O=300 T=1 | ./lav2maf /dev/stdin HUMAN BABOON > out.txt
for dir in 001 002 003 004 005 006 007 008 009 010; do mkdir dataset$dir; ~/csci490/assign3/links.sh dataset$dir; done

