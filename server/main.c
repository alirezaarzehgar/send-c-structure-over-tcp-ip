#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include "../common/share.h"

#define PORT  1234
#define IP    "127.0.0.1"

int
main (int argc, char const *argv[])
{
  int fd;

  struct sockaddr_in saddr;

  int retval;

  /* create socket */
  fd = socket (AF_INET, SOCK_STREAM, IPPROTO_IP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't open socket\n");
      exit (EXIT_FAILURE);
    }

  /* binding */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  retval = bind (fd, (struct sockaddr *)&saddr, sizeof (saddr));

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't bind ip&port\n");
      exit (EXIT_FAILURE);
    }

  /* listen */
  retval = listen (fd, 10);

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't listen on network\n");
      exit (EXIT_FAILURE);
    }

  /* loop and accept */
  while (1)
    {
      int cfd;

      struct sockaddr_in caddr;

      socklen_t caddrLen;

      int retval;

			person_t ali = {
				.info = {
					.firstname = "alireza",
					.lasttname = "arzehgar",
					.age = 18
				},
				.job = {
					.name = "system programming",
					.level = JUNIOR,
					.company_name = "zharf poyan",
					.company_address = "mashhad charah milad"
				},
				.home = {
					.address = "meydan takhti abkoh 1 babataher 7 pelak 26",
					.postal_code = 424234234,
					.zone = "sa'd abad"
				}
			};

      /* accept */
      cfd = accept (fd, (struct sockaddr *)&caddr, &caddrLen);

			if(cfd == -1)
			{
				fprintf(stderr, "Couldn't accept new connection\n");
				exit(EXIT_FAILURE);
			}

			write(cfd, &ali, sizeof(ali));

			close(cfd);
    }

  return EXIT_SUCCESS;
}