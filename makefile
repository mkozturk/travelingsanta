all : data.c santa.h santa.cpython-36m-x86_64-linux-gnu.so

data.c santa.h : prepdata.py data/cities.csv
	python prepdata.py

santa.cpython-36m-x86_64-linux-gnu.so : data.c santa.h
	python setup.py build_ext --inplace
