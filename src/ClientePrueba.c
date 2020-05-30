/*
 ============================================================================
 Name        : ClientePrueba.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "ClientePrueba.h"

int main(void) {
	int conexion;
	char* ip = "127.0.0.1";
	char* puerto = "6009";
	char a;

	t_log* logger;

	logger = iniciar_logger();

	log_debug(logger,"soy un log");

	conexion = crear_conexion(ip,puerto);

	if (conexion!=0){
		log_debug(logger,"se creo la conexión");
	}

	scanf("%c", &a);

	SendSubscriptionRequest(NEW_POKEMON,conexion);

//	enviar_mensaje("FFVII",conexion);
//	char* mensaje = recibir_mensaje(conexion);
//	log_info(logger,mensaje);
//	free(mensaje);

	terminar_programa(conexion, logger);
	return 0;
}

//TODO
t_log* iniciar_logger(void)
{
	return log_create("tp0.log","cliente",true,LOG_LEVEL_DEBUG);
}

//TODO
t_config* leer_config(void)
{
	return config_create("/home/utnso/workspace/Game-watch-client/tp0.config");

}

//TODO
void terminar_programa(int conexion, t_log* logger)
{
	log_destroy(logger);
	liberar_conexion(conexion);
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (c}onexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
}
