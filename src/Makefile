
#IDIR=../hdr
#IDIR=../../../con2redis/src
ODIR=../obj
BDIR=../bin

CC=g++
# use this when connecting to Postgresql (library lpq)
#CFLAGS=-std=c++11 -I. -I$(IDIR) -I/usr/include/postgresql -lpq -lm 
CFLAGS=-std=c++20 -g -ggdb -fpermissive -L/usr/local/lib -Wall -I. -I$(IDIR) -lpq -lm -lhiredis

# use this when no connection to Postgresql (library lpq) is needed
#CFLAGS=-std=c++11 -I. -I$(IDIR) -lm 

DEPS = $(wildcard $(IDIR)/*.h)
#OBJ = $(wildcard $(ODIR)/*.o)
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, $(ODIR)/%.o, $(SRC))

#con2redis_OBJ=$(wildcard ../../../con2redis/obj/*.o)


#all:	con2redis $(BDIR)/main

#con2redis:
#	$(MAKE) -C ../../../con2redis/src
# Makefile principale

# Lista delle sotto-directory contenenti i Makefile da includere ed eseguire
SUBDIRS := TestGenerator/src \
			SUD/AverageAndCovariance/src \
			SUD/AverageAnomalyPresence/src \
			SUD/CovarianceAnomalyValue/src \
			SUD/AverageAnomalyValue/src \
			SUD/CovarianceAnomalyPresence/src \
			Monitors/Functional/CheckAnomalyAverage/src \
			Monitors/Functional/CheckAnomalyCovariance/src \
			Monitors/Functional/RangeNullData/src \
			Monitors/Functional/NullDataAnomaly/src \
			Monitors/NonFunctional/AverageDetectionTime/src \
			Monitors/NonFunctional/CovarianceDetectionTime/src \
			Monitors/NonFunctional/AverageAnomalyTime/src \
			Monitors/NonFunctional/CovarianceAnomalyTime/src \


# Target predefinito: esegui tutti i Makefile nelle sotto-directory
all:
	@for dir in $(SUBDIRS); do \
    	echo "Esecuzione di Makefile in $$dir..."; \
    	$(MAKE) -C $$dir; \
	done
	
run:
	../delRedisDB.sh
	../ScriptsDB/create.sh

	TestGenerator/bin/main

	SUD/AverageAndCovariance/bin/main
	SUD/AverageAnomalyPresence/bin/main
	SUD/CovarianceAnomalyValue/bin/main
	SUD/AverageAnomalyValue/bin/main
	SUD/CovarianceAnomalyPresence/bin/main

	Monitors/Functional/CheckAnomalyAverage/bin/main
	Monitors/Functional/CheckAnomalyCovariance/bin/main
	Monitors/Functional/RangeNullData/bin/main
	Monitors/Functional/NullDataAnomaly/bin/main

	Monitors/NonFunctional/AverageDetectionTime/bin/main
	Monitors/NonFunctional/CovarianceDetectionTime/bin/main
	Monitors/NonFunctional/AverageAnomalyTime/bin/main
	Monitors/NonFunctional/CovarianceAnomalyTime/bin/main
	
	
	
	

$(ODIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/main: $(OBJ) $(DEPS)
#	$(CC) -o $@ $(OBJ) $(con2redis_OBJ) $(CFLAGS)


.PHONY: clean

clean:
	@for dir in $(SUBDIRS); do \
    	echo "Esecuzione di Makefile in $$dir..."; \
    	$(MAKE) -C $$dir clean; \
	done
