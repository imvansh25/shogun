#!/bin/bash
( cd ../../src
for e in ../examples/r-modular/*.R
do
	echo -n "running $e .."
	if R --slave -f "$e" >/dev/null 2>&1
	then
		echo " OK"
	else
		echo " ERROR"
	fi
done
)
