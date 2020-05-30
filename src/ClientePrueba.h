/*
 * ClientePrueba.h
 *
 *  Created on: 16 may. 2020
 *      Author: utnso
 */

#ifndef CLIENTEPRUEBA_H_
#define CLIENTEPRUEBA_H_

#include<stdio.h>
#include<stdlib.h>
#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>
#include<readline/readline.h>

#include<stdint.h>
#include<unistd.h>
#include<commons/collections/queue.h>
#include<commons/collections/list.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "delibird/comms/messages.h"
#include "delibird/comms/serialization.h"
#include "delibird/comms/pokeio.h"

#include "utils.h"


t_log* iniciar_logger(void);
t_config* leer_config(void);
void terminar_programa(int, t_log*);

#endif /* CLIENTEPRUEBA_H_ */
