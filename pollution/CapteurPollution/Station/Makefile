#
# Makefile pour generer le serveur "station meteo"
#

OBJS = station.o
LIBS = -lpthread
LOCAL_LIBS  = -L ../Communication # -L ../Threads
LOCAL_LIBS += -lcom # -lthrd
CFLAGS     += -I ../Communication # -I ../Threads

#
# Cible generale
#

all: station

#
# La cible de nettoyage
#

clean: 
	rm -f core *.o jeu

#
# Les cibles pour l'executable
#

station: $(OBJS)
	$(CC) $(CFLAGS) -o station $(OBJS) $(LOCAL_LIBS) $(LIBS)

station.o: station.c station.h
