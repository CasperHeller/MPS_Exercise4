#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

//Check that the led name is correct
//const char* IOFILE = "/sys/class/leds/SYSLED4/brightness";
const char* IOFILE = "/sys/class/leds/led1/brightness";
const char OFF = '0';
const char ON = '1';

int main (void)
{
	// Åbner filen
	printf("%s", "ledapp running\nremember to load leds-gpio\n");
	int fd = open(IOFILE, O_WRONLY);

	// Tjekker filen er blevet åbnet
	if (fd == -1)
	{
		printf("ERROR: %s: %s\n", strerror(errno), IOFILE);
		return EXIT_FAILURE;
	}

	//Toggler LED 10 gange
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%s", "LED turned off,\n");
		if (write(fd, &OFF, 1) == -1)
		{
			printf("ERROR: %s: %s\n", strerror(errno), IOFILE);
			return EXIT_FAILURE;
		}
		sleep(1);

		printf("%s", "LED turned on,\n");
		if (write(fd, &ON, 1) == -1)
		{
			printf("ERROR: %s: %s\n", strerror(errno), IOFILE);
			return EXIT_FAILURE;
		}
		sleep(1);
	}
	
	// Slukker LED sidste gang
	printf("%s", "LED turned off,\n");
	if (write(fd, &OFF, 1) == -1)
	{
		printf("ERROR: %s: %s\n", strerror(errno), IOFILE);
		return EXIT_FAILURE;
	}

	// Lukker filen ned
	if (close(fd) == -1)
	{
		printf("ERROR: %s: %s\n", strerror(errno), IOFILE);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}