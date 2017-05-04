lst_maps=`ls resources/maps`
for map in $lst_maps
do
	echo $map
	lst_players=`ls resources/players`
	for player in $lst_players
	do
	echo $player		
		for ((i=0; i<5; i++))
		do
			./resources/filler_vm -f ./resources/maps/$map \
			 -p1 ./adenis.filler -p2 ./resources/players/$player | ./show.filler
			 sleep 1
		done
		for ((i=0; i<5; i++))
		do
			 ./resources/filler_vm -f ./resources/maps/$map \
			 -p2 ./adenis.filler -p1 ./resources/players/$player | ./show.filler
			 sleep 1
		done
	done
done