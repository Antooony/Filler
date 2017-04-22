#!/bin/bash

for ((i=0; i<10; i++))
do
	echo ROUND$i
	>&2 echo ROUND$i
	liste_maps=`ls resources/maps`
	
	for map in $liste_maps
	do
		echo "/////////////////////////////"
		>&2 echo "/////////////////////////////"
		liste_joueurs=`ls resources/players`
		for joueurs in $liste_joueurs
		do
			echo $joueurs $map
			>&2 echo $joueurs $map
				printf "p1 -- "
				>&2 printf "p1 -- "
				./resources/filler_vm -f ./resources/maps/$map -p1 ./adenis.filler -p2 \
				./resources/players/$joueurs | ./score 1; 
				printf "p2 -- "
				>&2 printf "p2 -- "
				./resources/filler_vm -f ./resources/maps/$map -p1 ./adenis.filler -p2 \
				./resources/players/$joueurs | ./score 1; 
				printf "p1 -- "
				>&2 printf "p1 -- "
				./resources/filler_vm -f ./resources/maps/$map -p1 ./adenis.filler -p2 \
				./resources/players/$joueurs | ./score 1; 
				printf "p2 -- "
				>&2 printf "p2 -- "
				./resources/filler_vm -f ./resources/maps/$map -p1 ./adenis.filler -p2 \
				./resources/players/$joueurs | ./score 1; 
				printf "p1 -- "
				>&2 printf "p1 -- "
				./resources/filler_vm -f ./resources/maps/$map -p1 ./adenis.filler -p2 \
				./resources/players/$joueurs | ./score 1; 
				sleep 1
			printf '\n'
			>&2 printf '\n'
		done
	done
done