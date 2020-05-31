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
	char b;

	t_log* logger;

	logger = iniciar_logger();

	log_debug(logger,"soy un log");

	conexion = crear_conexion(ip,puerto);

	if (conexion!=0){
		log_debug(logger,"se creo la conexión");
	}

	// Probar la subscripción
//	scanf("%c", &a);
//	SendSubscriptionRequest(NEW_POKEMON,conexion);

	// Probar un mensaje
	printf("Ingresa un caracter para enviar el mensaje \n");
	scanf("%c", &b);
//
//	conexion = crear_conexion(ip,puerto);
//
//	deli_message* message = (deli_message*)malloc(sizeof(deli_message));;
//
//	message->messageType = 1;
//
	char * nombre = "pikachu";

	new_pokemon* pokemon = (new_pokemon*)malloc(sizeof(new_pokemon));

	pokemon->pokemonName = nombre;
	pokemon->horizontalCoordinate = 10;
	pokemon->verticalCoordinate = 10;
	pokemon->ammount = 1;


//	message->messageContent = malloc(sizeof(void*));
//	message->messageContent = (void*)pokemon;

	puts("va a mandar el mensaje");

	int resultado = Send_NEW(*(pokemon), conexion);

//	SendMessage(*(message) , conexion);

	puts("mandó el mensaje");

	free(pokemon);
//	free(message);

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
