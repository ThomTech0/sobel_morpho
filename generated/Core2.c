/**
 * @file Core2.c
 * @generated by CPrinter
 * @date Fri Dec 01 11:00:16 CET 2023
 *
 * Code generated for processing element Core2 (ID=2).
 */

#include "preesm_gen.h"
// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int preesmStopThreads;

extern char *const explode_Split_0_output__Sobel_3__0; // explode_Split_0_output > Sobel_3 size:= 537600*char defined in Core0
extern uchar *const output_3__input__0; // explode_Split_0_output_output_3 > Sobel_3_input size:= 537600*uchar defined in Core0
extern uchar *const output__y_3__0;  // Erosion_3_output > implode_display_0_y_y_3 size:= 518400*uchar defined in Core0
extern char *const Erosion_3__implode_display_0_y__0; // Erosion_3 > implode_display_0_y size:= 518400*char defined in Core0

// Core Global Definitions
char Core2[1059840]; //  size:= 1059840*char
char *const Sobel_3__Dilation_3__0 = (char*) (Core2 + 0);  // Sobel_3 > Dilation_3 size:= 533760*char
char *const Dilation_3__Erosion_3__0 = (char*) (Core2 + 533760);  // Dilation_3 > Erosion_3 size:= 526080*char
uchar *const output__input__7 = (uchar*) (Core2 + 0);  // Sobel_3_output > Dilation_3_input size:= 533760*uchar
uchar *const output__input__8 = (uchar*) (Core2 + 533760);  // Dilation_3_output > Erosion_3_input size:= 526080*uchar

void* computationThread_Core2(void *arg) {
  if (arg != NULL) {
    printf("Warning: expecting NULL arguments\n");
    fflush (stdout);
  }

  // Initialisation(s)

  // Begin the execution loop
  pthread_barrier_wait(&iter_barrier);
#ifdef PREESM_LOOP_SIZE // Case of a finite loop
	int index;
	for(index=0;index<PREESM_LOOP_SIZE && !preesmStopThreads;index++){
#else // Default case of an infinite loop
  while (!preesmStopThreads) {
#endif
    // loop body
    receiveStart(); // Core0 > Core2
    receiveEnd(0, 2); // Core0 > Core2
    sobel(1920/*width*/, 280/*height*/, output_3__input__0, output__input__7); // Sobel_3

    dilation(278/*height*/, 1920/*width*/, 2/*window*/, output__input__7, output__input__8); // Dilation_3

    erosion(274/*height*/, 1920/*width*/, 2/*window*/, output__input__8, output__y_3__0); // Erosion_3

    sendStart(2, 0); // Core2 > Core0
    sendEnd(); // Core2 > Core0
    // loop footer
    pthread_barrier_wait(&iter_barrier);

  }

  return NULL;
}
