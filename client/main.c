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

char *get_job_level (job_level job);

int
main (int argc, char const *argv[])
{
  int fd;

  struct sockaddr_in saddr;

  int retval;

  person_t person;

  /* create socket */
  fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (fd == -1)
    {
      fprintf (stderr, "Couldn't open socket\n");
      exit (EXIT_FAILURE);
    }

  /* connect */
  saddr.sin_family = AF_INET;

  saddr.sin_port = htons (PORT);

  saddr.sin_addr.s_addr = inet_addr (IP);

  retval = connect (fd, (struct sockaddr *)&saddr, sizeof (saddr));

  if (retval == -1)
    {
      fprintf (stderr, "Couldn't connect to network\n");
      exit (EXIT_FAILURE);
    }

  /* send & recv */

  read (fd, &person, sizeof (person_t));

  printf ("firstname : %s\n", person.info.firstname);
  printf ("lasttname : %s\n", person.info.lasttname);
  printf ("age : %d\n", person.info.age);

  printf ("job name : %s\n", person.job.name);
  printf ("company name : %s\n", person.job.company_name);
  printf ("company address : %s\n", person.job.company_address);
  printf ("level : %s\n", get_job_level (person.job.level));

  printf ("home address : %s\n", person.home.address);
  printf ("home postal code : %d\n", person.home.postal_code);
  printf ("home area : %s\n", person.home.zone);

  return EXIT_SUCCESS;
}

char *
get_job_level (job_level job)
{
  switch (job)
    {
    case JUNIOR:
      return "junior";

    case MEDIOR:
      return "medior";

    case SENIOR:
      return "senior";

    case LEADER:
      return "team leader";

    default:
      return "unknow";
    }
}