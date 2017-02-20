#include "prompt.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/times.h>
#include <stdio.h>              /* Standard lineaed input/output         */
#include <stdlib.h>             /* Standard library functions            */
#include <string.h>             /* String operations                     */
#include <strings.h>			/* String operations                     */
#include <signal.h>             /* Signal operations 					 */
#include <time.h>

static clock_t c0;
static clock_t c1;
static struct tms st_cpu;
static struct tms en_cpu;


main(){

	c0	=	times(&st_cpu);
	int max=0;
	for (max; max<10000; max++) printf("Ya te voy a dar el tiempo nene\n");
	printf("\n");
	c1 = times(&en_cpu);
	printf("Tardó\n\t Real time: %.3f\n\t User time: %.3f\n\t Sys time: %.3f\n", 
				(float)(c1-c0)/CLOCKS_PER_SEC,
				(float)(en_cpu.tms_utime - st_cpu.tms_utime)/CLOCKS_PER_SEC,												 
				(float)(en_cpu.tms_stime - st_cpu.tms_stime)/CLOCKS_PER_SEC );
}
