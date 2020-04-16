
#include "philo_one.h"

int main()
{
	t_phil *phil = create_struct_pointer();
	struct timeval begin;
	struct timeval end;
	long i;

	gettimeofday(&phil->begin, NULL);
	usleep(1000000);
	gettimeofday(&phil->end, NULL);
	ft_putnbr_long(get_time(phil));
}