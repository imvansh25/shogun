#!/bin/bash
if [ -z "${PYTHON}" ]
then
	PYTHON=python
fi

( cd ../../src
for e in ../examples/python/*.py
do
	echo -n "running $e .."
	if ${PYTHON} "$e" >/dev/null 2>&1
	then
		echo " OK"
	else
		echo " ERROR"
	fi
done
)
