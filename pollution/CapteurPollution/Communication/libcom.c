/** fichier libcom.c **/

/*****************************************************************/
/** Ce fichier contient des fonctions utilisees par le serveur  **/
/** de jeu et concernant les sockets.                           **/
/*****************************************************************/

/**** Fichiers d'inclusion ****/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include "libcom.h"

/**** Constantes ****/

/**** Variables globales *****/

/**** Fonctions de gestion des sockets ****/
