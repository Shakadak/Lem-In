#include "inc/structs.h"
#include "inc/lemin.h"
#include "libft/inc/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	what_error(unsigned int error)
{
	if (error == (error | SRT_ERR))
		printf("Multiple or no start detected\n");
	if (error == (error | END_ERR))
		printf("No end detected\n");
	if (error == (error | LNK_ERR))
		printf("Error when linking rooms\n");
	if (error == (error | OTH_ERR))
		printf("an unidentified error is detected\n");
}
