#include "idxval.h"

void	idxval_setvalue(t_idxval *idxval, const int value)
{
	idxval->value = value;
}

void	idxval_setindex(t_idxval *idxval, const int index)
{
	idxval->index = index;
}
