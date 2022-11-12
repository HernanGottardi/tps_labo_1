



int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
// agregue yo:
int controller_mostrarJugadoresConvocados(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador);
int controller_convocarjugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_quitarConvocado(LinkedList *pArrayListJugador, LinkedList *pArrayListSeleccion);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarYListar(LinkedList* listaJugadores, LinkedList* listaSelecciones);
int controller_imprimirArchivoConvocados(LinkedList* pArrayListJugador, char* path);
int controller_GenerarArchivoConvocadosPorConfederacion(LinkedList* listaJugadores, LinkedList* listaSelecciones,
		LinkedList* listaAux);
