#if !defined(SHARE_H)
#define SHARE_H

typedef enum { JUNIOR, MEDIOR, SENIOR, LEADER } job_level;

typedef struct person person_t;

typedef struct personal_info personal_info_t;

typedef struct job job_t;

typedef struct home home_t;

struct personal_info
{
  char firstname[10];

  char lasttname[10];

	short int age;
};

struct job
{
  char name[20];

  job_level level;

	char company_name[20];

	char company_address[50];
};

struct home
{
	char address[50];

	int postal_code;

	char zone[10];
};

struct person
{
  personal_info_t info;

	job_t job;

	home_t home;
};

#endif // SHARE_H
