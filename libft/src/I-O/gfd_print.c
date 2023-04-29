#include "../../inc/gfd.h"

void	gfd_print(t_gfd gfd)
{
	ft_pnerc(gfd.n_part, "");
	write(STDERR, "\n", 1);
	while (gfd.data && gfd.data->part)
	{
		ft_ps(gfd.data->part);
		gfd.data = gfd.data->next;
	}
}
