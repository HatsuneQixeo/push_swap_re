#include "idxval.h"

int	idxval_getvalue(const t_idxval *idxval)
{
	return (idxval->value);
}

int	idxval_getindex(const t_idxval *idxval)
{
	return (idxval->index);
}
